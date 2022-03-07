#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
#define BAUDRATE 1200
#define BAUD_PRESCALE (((F_CPU / (BAUDRATE * 16UL))) - 1)


void UART_init()
{
	UBRRL = 51;
	//UBRRH = (BAUD_PRESCALE >> 8);
	
	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);
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



int main()
{
	
	UART_init();
	//("INITIALISING USART");
	
	//UART_SendString("\n\t Echo Test ");
	while(1)
	{
		uint8_t ch = 67;
		
		//char ch[8];
		//itoa(c,ch,10);
		
		UART_TxChar(ch);
		//_delay_ms(100);
	}
}


