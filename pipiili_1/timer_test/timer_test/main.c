/*
 * timer_test.c
 *
 * Created: 29-01-2020 19:16:08
 * Author : Prabhakar jaiswal
 */ 

#include <avr/io.h>


int main(void)
{
	
    /* Replace with your application code */
	DDRD=0xFF;
    while (1) 
    {
		PORTD = 0xFF;
		TCCR1B=(1<<CS10);
		if (TCNT1>3000)
		{
			PORTD=(1<<PIND4);
		}
		else
		{
			PORTD=0b00000000;
		}
}
}
