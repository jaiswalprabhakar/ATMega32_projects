
#include "avr/io.h"
#include <util/delay.h>


void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}



int main ()
{
	unsigned char duty;
	
	PWM_init();

	while (1)
	{
		//for(duty=0; duty<255; duty+=1)
		    duty=1;
			OCR0=duty;  /*increase the LED light intensity*/
			
		
		//for(duty=255; duty>1; duty-=1)
		//{
			//OCR0=duty;  /*decrease the LED light intensity*/
			
		//}
	}
}