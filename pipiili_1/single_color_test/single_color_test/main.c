#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>






int main(void)
{
	DDRD = 0b00000000;
	DDRB = 0b00000001;
	//PORTD = 0xFF;
	//DDRA = 0b00000011;
	DDRC = 0b00000001;
	PORTB = 0b00000001;
	//DDRB = 0xFF;
	int r; 
	
	
	
	while(1)
	{
		
		if(bit_is_set(PIND,4)==0)
		{
			while(bit_is_set(PIND,4)==0);   //Wait for rising edge
		}

	while(bit_is_set(PIND,4)==1);   //Wait for falling edge
	
		

		TCNT1=0x0000;//Reset Counter

		TCCR1B=(1<<CS10); //Prescaller = F_CPU/1 (Start Counting)

		while(bit_is_set(PIND,4)==0);   //Wait for rising edge
		r=TCNT1;
		float f=8000000/r;
		
		//Stop Timer
		TCCR1B=0x00;

			if(f < 500000)
			{
				PORTC = 0b00000001;
			}
			else
			{
				PORTC = 0b00000000;
			}
	
	
	}
	
}
        
