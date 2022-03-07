#include <avr/io.h>
#include <util/delay.h>
uint8_t ss,mm,hh;


void start_comm(void)
{
	TWBR = 72;
	TWSR = ( 0<< TWPS0 ) | (  0<< TWPS1 );
	TWCR = 0x00;
	TWCR  = ( 1<< TWINT  ) | ( 1<< TWSTA ) |  ( 1<< TWEN ) ;
	while ( ! ( TWCR  & ( 1<< TWINT )));
	while(( TWSR & 0xF8) != 0x08);
}



void mr_mode()
{
	TWDR = 0xD1;
	TWCR = ( 1<< TWINT ) | (  1<< TWEN );
	while (!( TWCR & ( 1<< TWINT )));
	while(( TWSR &  0xF8 ) != 0x40) ;
}
void mt_mode()
{
	TWDR = 0xD0 ;
	TWCR = ( 1<< TWINT ) | ( 1<< TWEN ) ;
	while ( ! (TWCR & ( 1<< TWINT )))
	while(( TWSR & 0xF8) != 0x18) ;
}
void data_transmision(uint8_t data)
{
	TWDR = data;
	TWCR = ( 1<< TWINT ) | ( 1<< TWEN ) ;
	while ( ! (TWCR & ( 1<< TWINT )));
	while(( TWSR & 0xF8) != 0x28) ;
}
void stop_comm()
{
	TWCR = ( 1<< TWINT ) | ( 1<< TWEN ) |( 1<< TWSTO ) ;
}
uint8_t data_reception()
{
	TWCR = ( 1<< TWINT ) | ( 1<< TWEN ) |( 1<< TWEA ) ;
	while ( ! (TWCR & ( 1<< TWINT )));
	while(( TWSR & 0xF8) != 0x50) ;
	return( TWDR );
}
uint8_t nack()
{
	TWCR = (1<<TWINT ) |  ( 1<<TWEN  )  ;//data byte will be received & ack will be send
	while (!(TWCR & (1<<TWINT  )));
	while((TWSR & 0xF8)!=0x58);
	return(TWDR);
}
void set_time(uint8_t ss,uint8_t mm,uint8_t hh)
{
	start_comm();
	mt_mode();
	data_transmision(0x00);
	data_transmision(ss);
	data_transmision(mm);
	data_transmision(hh);
	stop_comm();
}
void get_time(void)
{ start_comm();
	mt_mode();
	data_transmision(0x00);
	stop_comm();
	start_comm();
	mr_mode();
	ss=data_reception(); //seconds
	mm=data_reception(); //minutes
	hh=nack(); //hours
	stop_comm();
}
int main(void)
{
	DDRA=0xFF;
	DDRB=0xFF;
	PORTA=0xF0;
	set_time(0x00,0x59,0x01); //you can set initial time accordingly.
	while(1)
	{
		get_time();
		PORTA &=~(1<<PA0);
		PORTB=ss;
		_delay_us(2000);
		PORTA|=1<<PA0;
		_delay_us(2000);
		PORTA &=~(1<<PA1);
		PORTB=ss>>4;
		_delay_us(2000);
		PORTA|=1<<PA1;
		_delay_us(2000);
		PORTA &=~(1<<PA2);
		PORTB=mm;
		_delay_us(2000);
		PORTA|=1<<PA2;
		_delay_us(2000);
		PORTA &=~(1<<PA3);
		PORTB= mm>>4;
		_delay_us(2000);
		PORTA|=1<<PA3;
		_delay_us(2000);/////
		PORTA &=~(1<<PA4);
		PORTB=hh;
		_delay_us(2000);
		PORTA|=1<<PA4;
		_delay_us(2000);
		PORTA &=~(1<<PA5);
		PORTB=hh>>4;
		_delay_us(2000);
		PORTA|=1<<PA5;
		_delay_us(2000);
		
	}
}