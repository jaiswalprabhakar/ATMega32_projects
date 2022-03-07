#include <avr/io.h>
#include <avr/sfr_defs.h>
int ir1,ir2,ir3,ir4,ir5;
int main()
{
	DDRA = 0xFF;
	DDRD = 0x00;
	
	while(1){
			
			
			ir1 = bit_is_clear(PIND,2);
			ir2 = bit_is_clear(PIND,3);
			ir3 = bit_is_clear(PIND,4);
			ir4 = bit_is_clear(PIND,5);
			ir5 = bit_is_clear(PIND,6);
			
			
			
			if(ir1 == 0 && ir2 == 0 && ir3 == 1 && ir4 == 0 && ir5 == 0){
				PORTA = 0b10100000; // Going Forward 
			}	
			if(ir1 == 0 && ir2 == 1 && ir3 == 0 && ir4 == 0 && ir5 == 0){
				PORTA = 0b10000000; // Simple Smooth Left
			}
			if(ir1 == 0 && ir2 == 1 && ir3 == 0 && ir4 == 0 && ir5 == 0){
				PORTA = 0b00100000; // Simple Smooth RIght
			}
			if(ir1 == 0 && ir2 == 1 && ir3 == 1 && ir4 == 1 && ir5 == 0){
				PORTA = 0b10100000; // If detected 3 middle THen Also Move Forward
			}
			if(ir1 == 0 && ir2 == 1 && ir3 == 1 && ir4 == 0 && ir5 == 0){
				PORTA = 0b10000000; // Smooth Left
			}
			if(ir1 == 0 && ir2 == 0 && ir3 == 0 && ir4 == 1 && ir5 == 0){
				PORTA = 0b00100000; // Smooth Right
			}
			if(ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4 == 0 && ir5 == 0){
				PORTA = 0b10010000; // Sharp Left 
			}
			if(ir1 == 0 && ir2 == 0 && ir3 == 1 && ir4 == 1 && ir5 == 1){
				PORTA = 0b01100000; // Sharp Right
			}
			if(ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4 == 1 && ir5 == 1){
				PORTA = 0x00;
			}
	}
}
// 0 1 -- 9 A B C D E F
// 0b00000010;
// 0x02