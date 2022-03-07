#include <avr/io.h>
#include <avr/sfr_defs.h>

int main()
{
	DDRA = 11111111;
	DDRD = 00000000;
	
	int ir1,ir2,ir3,ir4,ir5;
	
	while(1){
		ir1 = bit_is_clear(PIND,3);
		ir2 = bit_is_clear(PIND,4);
		ir3 = bit_is_clear(PIND,5);
		if(ir2==1 && ir1==0 && ir3==0)
		{
			
			PORTA = 0b10100000;
			
		}
		if(ir2 == 0 && ir1 == 0 && ir3 == 0)
		{
			
			PORTA = 0b00000000;
		}
	}
	return 0;	
}