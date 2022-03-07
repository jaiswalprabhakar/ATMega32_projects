#define F_CPU 16000000UL
#include <avr/io.h>

#include <util/delay.h>






void main()
{
	
	//Configure TIMER1
	TCCR1A|=(1 << COM1A1 ) | ( 1<< COM1B1) | (1 << WGM11 );        //NON Inverted PWM
	TCCR1B|=( 1 << WGM13) | ( 1 << WGM12 ) | ( 1 << CS11 ) | ( 1 << CS10 ); //PRESCALER=64 MODE 14(FAST PWM)

	ICR1 = 500;  //fPWM=50Hz (Period = 20ms Standard).

	DDRD|=(1<<PD4)|(1<<PD5);   //PWM Pins as Out
    
	while(1)
	{
              //PORTD = 0xFF;
	//	OCR1A= 520;   //0 degree
     //_delay_ms(1)	;	

		OCR1A= 500;  //90 degree
//  		_delay_ms(1)	;
// 
//  		OCR1A = 90;  //135 degree
//  
//  		_delay_ms(1)	;
// 
//  		OCR1A=80;  //180 degree
//  		_delay_ms(1)	;
//  		
//  		OCR1A=3000;  //90 degree
//  		_delay_ms(1)	;
		 
// 		 OCR1A=75;
// 		 _delay_ms(1);
// 		 
// 		 OCR1A=95;
// 		 _delay_ms(1);
// 		 
// 		 OCR1A=1;
// 		 _delay_ms(1);
// 		 
// 		 OCR1A=375;
// 		 _delay_ms(1);
// 		 
// 		 OCR1A=10;
// 		 _delay_ms(1);
// 		 
// 		 OCR1A=425;
// 		 _delay_ms(1);
// 		 
// 		 OCR1A=450;
// 		 _delay_ms(1);
// 		 
// 		 OCR1A=30;
// 		 _delay_ms(1);
// 		 
// 		 OCR1A=2400;
// 		 _delay_ms(1);
		 
		 
	}
}
