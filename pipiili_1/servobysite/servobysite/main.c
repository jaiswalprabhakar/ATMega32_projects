#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRD |= 0xFF;
	TCCR1A |= 1<<WGM11 | 1<<COM1A1 | 1<<COM1A0 | 1<<COM1B1 | 1<<COM1B0 ;
	TCCR1B |= 1<<WGM13 | 1<<WGM12 | 1<<CS10;
	ICR1 = 19999;
	

	//OCR1A = ICR1 - 2000; //18000

	while (1)
	{
		OCR1A = 19100;
		OCR1B = 19100;
		_delay_ms(1000);
		/*OCR1A = 18300;
		OCR1B = 18300;
		_delay_ms(1000);*/
		OCR1A = 17800;
		OCR1B = 17800;
		_delay_ms(1000);
		
		
	}
}