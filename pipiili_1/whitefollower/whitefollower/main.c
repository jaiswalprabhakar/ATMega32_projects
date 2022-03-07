//#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/sfr_defs.h>
//#include <util/delay.h>
int ir1,ir2,ir3,ir4,ir5;
int main()
{
	DDRA = 0xFF;
	DDRD = 0x00;
	int true = 1;       //For white strip and black backgrond true = 1; false = 0;
	int false = 0;      //For black strip and white background true = 0; false = 1;
	while(1)
	{
		
		
		
			ir1 = bit_is_clear(PIND,2);
			ir2 = bit_is_clear(PIND,3);
			ir3 = bit_is_clear(PIND,4);
			ir4 = bit_is_clear(PIND,5);
			ir5 = bit_is_clear(PIND,6);
		
		
		
		
		if((ir1 == false && ir2 == false && ir3 == true  && ir4 == false && ir5 == false) || 
		   (ir1 == false && ir2 ==  true && ir3 == true  && ir4 == true  && ir5 == false) ||
		   (ir1 == false && ir2 ==  true && ir3 == false && ir4 ==  true && ir5 == false))
		          {
		           //PORTA = 0b00000000;
			       //_delay_us(40);
			        PORTA = 0b10100000;//straight 
		          }
		if((ir1 == false && ir2 ==  true  && ir3 == false && ir4 == false && ir5 == false) || 
		   (ir1 == false && ir2 == true  && ir3 ==  true  && ir4 == false && ir5 == false) ||
		   (ir1 == true && ir2 == true  && ir3 ==  false  && ir4 == false && ir5 == false) ||
		   (ir1 == true  && ir2 == false && ir3 == false && ir4 == false && ir5 == false))
		         {
			      //PORTA = 0b00000000;
			      //_delay_us(40);
			      PORTA = 0b10000000; // Smooth Left
			     }
		if((ir1 == true && ir2 == true && ir3 == true && ir4 == false && ir5 == false) || 
		   (ir1 == true && ir2 == true && ir3 == true && ir4 == true  && ir5 == false))
			    {
				PORTA = 0b10010000; // Sharp Left
			    }
		if((ir1 == false && ir2 == false && ir3 == false && ir4 == true  && ir5== false) || 
		   (ir1 == false && ir2 == false && ir3 == true  && ir4 == true  && ir5== false) ||
           (ir1 == false && ir2 == false && ir3 == false && ir4 == true  && ir5== true ) ||
		   (ir1 == false && ir2 == false && ir3 == false && ir4 == false && ir5== true ))
		        {
		        //PORTA = 0b00000000;
			    //_delay_us(40);
			    PORTA = 0b00100000; // Smooth Right
				}
		if((ir1 == false && ir2 == false && ir3 == true && ir4 == true && ir5== true ) ||
		   (ir1 == false && ir2 == true  && ir3 == true && ir4 == true && ir5== true ))
		       {
			    PORTA = 0b01100000; // Sharp right
		       }
	/*	if(ir1 == false && ir2 == false && ir3 == false && ir4 == false && ir5== false)
		{
	
	
				//PORTA = 0b00000000;
				//_delay_ms(700);
				PORTA = 0b01010000; // back
			
		}*/
		
		
		
	}
}