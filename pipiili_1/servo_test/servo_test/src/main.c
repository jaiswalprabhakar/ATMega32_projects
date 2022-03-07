#define F_CPU 16000000UL
#include <avr/io.h>

#include <util/delay.h>






void main()
{
	
	//Configure TIMER1
/*	TCCR1A |= (1 << COM1A1 ) | (1 << COM1B1) | (1<<WGM11) | ( 1 << WGM13) | ( 1 << WGM12 );  
	TCCR1B |= (1 << COM1B1 ) | (1<<WGM11) | ( 1 << WGM13) | ( 1 << WGM12 );        //NON Inverted PWM
	TCCR1B |= ( 1 << CS11 );*/
	
	
	
	TCCR1A|=(1 << COM1A1 )  | (1 << WGM11 );  
	TCCR1A |=  ( 1<< COM1B1);      //NON Inverted PWM
	TCCR1B|= ( 1 << CS11 ) ;

	ICR1 = 39999;  //fPWM=50Hz (Period = 20ms Standard).
    
	DDRD = (1<<PD4);
	DDRD = (1<<PD5);   //PWM Pins as Out
	
	while(1)
	{
		OCR1A= 19000; 
		OCR1B= 19000;  //90 degree
 		_delay_ms(100);
		OCR1A= 16800; 
		OCR1B= 16800;  //90 degree
 		_delay_ms(100);
  	//	OCR1A= 16500;  //60 degree
  	//	_delay_ms(50);
// 		
		
	}
}
