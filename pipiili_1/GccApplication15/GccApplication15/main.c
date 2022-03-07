/*
 * GccApplication4.c
 *
 * Created: 19-11-2019 17:46:18
 * Author : Prabhakar jaiswal
 */ 
/*
#include <avr/io.h>
#include <>
#define W 0
#define B 1
int ir1,ir2,ir3,ir3,ir4,ir5; 
void input();
void srt();
void left();
void right();
void stop();

void rotate(); 
void main(void)
{
    DDRD = 0x00;
	DDRA = 0xFF;
    while (1) 
    {
		
		input();
		if(ir1==B && ir2==B && ir3==W && ir4==B && ir5==B) srt();
		if(ir1==W && ir2==W && ir3==W && ir4==W && ir5==W) stop();
		if((ir1==B && ir2==B && ir3==W && ir4==W && ir5==B)||(ir1==B && ir2==B && ir3==W && ir4==W && ir5==W)) right();
		if((ir1==B && ir2==W && ir3==W && ir4==B && ir5==B)||(ir1==W && ir2==W && ir3==W && ir4==B && ir5==B)) left();
		if((ir1==B && ir2==B && ir3==B && ir4==B && ir5==B)) rotate();
    }
}

void input()
{
	ir1 = bit_is_clear(PIND,6);
	ir2 = bit_is_clear(PIND,5);
	ir3 = bit_is_clear(PIND,4);
	ir4 = bit_is_clear(PIND,3);
	ir5 = bit_is_clear(PIND,2);
	
}

void srt()
{
	PORTA | = 0b10100000;
}

void left()
{
	PORTA | = 0b10000000;
}
void right(){
	
	PORTA | = 0b00100000;
	
}
void stop(){
	PORTA | = 0x00;
}

void rotate(){
	PORTA | = 0b00100000;
}
*/
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>
int ir1,ir2,ir3,ir4,ir5;
int count = 0;
void get_ir_state(){
	ir1 = bit_is_clear(PIND,3);
	ir2 = bit_is_clear(PIND,4);
	ir3 = bit_is_clear(PIND,5);
	ir4 = bit_is_clear(PIND,2);
	ir5 = bit_is_clear(PIND,6);
	
}

int main()
{
	DDRA = 0xFF;
	DDRD = 0x00;
	
	while(1){
			ir1 = ir2 = ir3 = ir4 = ir5 = 0;
			
		get_ir_state();
			
			
			if((ir1 == 0 && ir2 == 1 && ir3 == 0)){
				PORTA = 0b10100000;
			}
			if((ir1 == 1 && ir2 == 0 && ir3 == 0)){
				PORTA = 0b10000000;
			}
			if((ir1 == 0 && ir2 == 0 && ir3 == 1)){
				PORTA = 0b00100000;
			}
			
			if(ir1 == 1 && ir2 == 1 && ir3 == 0)
			PORTA = 0b10000000;
			
			if(ir1 == 0 && ir2 == 1 && ir3 == 1)
			PORTA = 0b00100000;
			
			if(ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4 == 0 && ir5 == 0){
				PORTA = 0b10100000;
			}
			if((ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4==1 && ir5 ==1))
			{	
				PORTA = 0b10000000; // 
			}
			if(ir1 == 0 && ir2 == 0 && ir3 == 0 && ir4 == 0 && ir5 == 0){
				PORTA = 0b10100000;
			}
			
				
					
			
			/*if((ir1 == 0 && ir2 == 0 && ir3 == 0 && ir4==0 && ir5 ==0 )){
				PORTA = 0b01010000;
			}
			*/
	}
	
	
		
}