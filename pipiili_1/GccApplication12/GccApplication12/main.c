#include <avr/io.h>
#include <avr/sfr_defs.h>

int ir1,ir2,ir3,ir4,ir5;
int count = 0;
void get_ir_state(){
	ir1 = bit_is_clear(PIND,2);
	ir2 = bit_is_clear(PIND,3);
	ir3 = bit_is_clear(PIND,4);
	ir4 = bit_is_clear(PIND,5);
	ir5 = bit_is_clear(PIND,6);
	
}

int main()
{
	DDRA = 0xFF;
	DDRD = 0x00;
	
	while(1){
			ir1 = ir2 = ir3 = ir4 = ir5 = 0;
			
		get_ir_state();
			
			
			if(ir1 == 0 && ir2 == 0 && ir3 == 0 && ir4 == 0 && ir5 == 0){ // All Black - Go Straight
				PORTA = 0b10100000;
			}
			
			if((ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4==1 && ir5 ==1)) // All White - Go Straight
			{	
				PORTA = 0b10100000;
			}
			if(ir1 == 0 && ir2 == 1 && ir3 == 1 && ir4 == 1 && ir5 == 0){ // 3 MIddle White - Go Straight
				PORTA = 0b10100000;
			}
			if(ir1 == 0 && ir2 == 1 && ir3 == 0 && ir4 == 0 && ir5 == 0){ // ir2 - white - Go Smooth Left
				PORTA = 0b10000000;
			}
			if(ir1 == 0 && ir2 == 0 && ir3 == 0 && ir4 == 1 && ir5 == 0){ // ir4 - white - Go Smooth Right
				PORTA = 0b00100000;
			}
			if(ir1 == 0 && ir2 == 0 && ir3 == 0 && ir4 == 0 && ir5 == 1){ // ir5 = white - go smooth Right
				PORTA = 0b00100000;
			}
			if(ir1 == 1 && ir2 == 0 && ir3 == 0 && ir4 == 0 && ir5 == 0){ // ir1 - white - go smooth left
				PORTA = 0b10000000;
			}
			if(ir1 == 0 && ir2 == 0 && ir3 == 1 && ir4 == 0 && ir5 == 1){ //00101
				PORTA = 0b10100000;
			}
			if(ir1 == 1 && ir2 == 0 && ir3 == 1 && ir4 == 0 && ir5 == 1){ // 10101
				PORTA = 0b10100000;
			}
	} // End While Loop
	
		
}// ENd Main