//#define F_CPU 16000000UL
#include <avr/io.h>

#include <util/delay.h>






void main()
{
	
	//Configure TIMER1
	TCCR1A |= (1 << COM1A1 ) | (1<<WGM11) | ( 1 << WGM13) | ( 1 << WGM12 );        //NON Inverted PWM
	TCCR1B |= ( 1 << CS10 );

	ICR1 = 19999;  //fPWM=50Hz (Period = 20ms Standard).

	DDRD|=(1<<PD4)|(1<<PD5);   //PWM Pins as Out
	
	while(1)
	{
		OCR1A= 1000;  //90 degree
		_delay_ms(50);
		OCR1A= 2000;  //90 degree
		_delay_ms(50);
		OCR1A= 350;  //90 degree
		_delay_ms(50);
		
		
	}
}
