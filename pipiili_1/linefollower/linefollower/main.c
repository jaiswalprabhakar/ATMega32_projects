

#include <avr/io.h>
#include <avr/sfr_defs.h>
int ir1,ir2,ir3,ir4,ir5;
int main()
{
	DDRA = 0xFF;
	DDRD = 0x00;
	
	while(1){
			
			
			ir1 = bit_is_clear(PIND,3);
			ir2 = bit_is_clear(PIND,4);
			ir3 = bit_is_clear(PIND,5);
			
			if(ir1 == 0 && ir2 == 1 && ir3 == 0){
				PORTA = 0b10100000;
			}
			if((ir1 == 1 && ir2 == 0 && ir3 == 0)){
				PORTA = 0b10000000;
			}
			if((ir1 == 0 && ir2 == 0 && ir3 == 1)){
				PORTA = 0b00100000;
			}
			if(ir1==1 && ir2==1 && ir3==1 ) PORTA=0b10100000;
			
			if(ir1 == 1 && ir2 == 1 && ir3 == 0)
			PORTA = 0b10000000;
			
			if(ir1 == 0 && ir2 == 1 && ir3 == 1)
			PORTA = 0b00100000;
			
			
	}
}