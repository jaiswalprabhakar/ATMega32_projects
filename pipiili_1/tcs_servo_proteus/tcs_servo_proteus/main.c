#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>



#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void TCSSelectBlue()
{
	PORTA &= ~(1 << PINA0);
	PORTA |= (1 << PINA1);
	//TCSS2Low();
	//TCSS3High();
}
void TCSSelectRed()
{
	PORTA &= ~(1 << PINA0) | ~(1 << PINA1);
	
}
void TCSSelectGreen()
{
	PORTA |= (1 << PINA0) | (1 << PINA1);
	//TCSS2High();
	//TCSS3High();
}



uint32_t TCSMeasure()
{

	if(bit_is_set(PINB,4)==0)
	{
		while(bit_is_set(PINB,4)==0);   //Wait for rising edge
	}

	while(bit_is_set(PINB,4)==1);   //Wait for falling edge



	TCNT1=0x0000;//Reset Counter

	TCCR1B=(1<<CS10); //Prescaller = F_CPU/1 (Start Counting)

	while(bit_is_set(PINB,4)==0);   //Wait for rising edge
	int R=TCNT1;
	float f=8000000/R;

	//Stop Timer
	TCCR1B=0x00;

	return f;
}
int MeasureB()
{
	TCSSelectBlue();
	int r;

	_delay_ms(10);
	r=TCSMeasure();

	_delay_ms(1);
	r+=TCSMeasure();

	//_delay_ms(10);
	r+=TCSMeasure();

	return r/3;

}
int MeasureG()
{
	TCSSelectGreen();
	int r;

	_delay_ms(10);
	r=TCSMeasure();

	_delay_ms(1);
	r+=TCSMeasure();

	//_delay_ms(10);
	r+=TCSMeasure();

	return r;

}
int MeasureR()
{
	TCSSelectRed();
	int r;

	_delay_ms(10);
	r=TCSMeasure();

	_delay_ms(1);
	r+=TCSMeasure();

	//_delay_ms(10);
	r+=TCSMeasure();

	return r;

}







void UART_init(long USART_BAUDRATE)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8);
}
unsigned char UART_RxChar()
{
	while ((UCSRA & (1 << RXC)) == 0);
	return(UDR);
}


void UART_TxChar(char ch)
{
	while (! (UCSRA & (1<<UDRE)));
	UDR = ch ;
}

void UART_SendString(char *str)
{
	
	
	//str[]=gets(r);
	unsigned int j=0;
	
	while (str[j]!='\0')		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}

int main()
{
	int count_r=0;
	int count_b=0;
	int count_g=0;
	
	TCCR1A |= (1 << COM1A1 ) | (1<<WGM11) | ( 1 << WGM13) | ( 1 << WGM12 );        //NON Inverted PWM
	TCCR1B |= ( 1 << CS11 );

	ICR1 = 39999;  //fPWM=50Hz (Period = 20ms Standard).

	DDRD|=(1<<PD4)|(1<<PD5);   //PWM Pins as Out
	
	DDRA = 0b11111111;
	DDRD = 0b11111111;
	PORTA = (1 << PINA2) | (1 << PINA3);
	DDRB = 0x00;
	
	
	// 	while(1){
	// 	for(int i=0; i<11;++i){
	// 	int r=MeasureR();
	// 	int g=MeasureG();
	// 	int b=MeasureB();
	//
	// 		if(r>14000){
	// 			count_r++;
	// 		}
	// 		else if(g>15000){
	// 			if(b>2500 && b<6000){
	//
	// 				count_b++;
	//
	// 			}
	//
	// 			else{
	// 				count_g++;
	// 			}
	// 		}
	// 		else if(g<15000){
	// 			if(b>2500 && b<6000){
	// 		    	count_b++;
	// 			}
	// 	     }
	// 	}
	//
	// 	     if(count_r>count_g && count_r>count_b){
	// 			 OCR1A= 20000;
	// 		 }else if(count_b>count_g &&count_b>count_r){
	// 			 OCR1A=15000;
	// 		 }else if(count_g>count_b && count_g>count_r){
	// 			 OCR1A= 17000;
	// 		 }
	// 		 }
	//
	//char c;(
	UART_init(9600);
	
	
	while(1){
		int r=MeasureR();
		int g=MeasureG();
		int b=MeasureB();
		
		
		
		if(r>14000){
			//OCR1A= 20000;
			PORTA = (1<< PINA7);
		}
		else if(g>15000){
			if(b>2500 && b<6000){
				
				//OCR1A= 15000;
				PORTA = (1 << PINA6);
			}
			
			else{
				//OCR1A= 17000;
				
				PORTA = (1 << PINA5);
			}
		}
		else if(g<15000){
			if(b>2500 && b<6000){
				
				//OCR1A=15000;
				PORTA= (1<<PINA6);
				
				
			}
		}
		
		
		
	}
	
	
	
	
	
	
	// 	{
	// 		int r;
	// 		r=MeasureB();
	// 		int mod;
	// 		UART_SendString("red :");
	// 		for(int i=0;i<=6;i++){
	// 			mod=r%10;
	// 			r=r/10;
	// 			char a=mod;
	// 			 UART_TxChar(a);
	//
	//
	// 		}
	// 		_delay_ms(100);
	// 	}
}


//	UART_SendString(r);
//c=UART_RxChar();
//UART_TxChar(c);



// void f_read(void){
// 	int a,bi;
//
// 	for(int i=0;i<=10;i++){
// 		a=bi%10;
// 		bi=bi/10;
// 		goto main()
// 	}
//
// }
