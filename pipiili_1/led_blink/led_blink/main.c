#include <avr/io.h>
#include <util/delay.h>
int main()
{
	DDRA = 0b10000001;
	while(1)
	{
		PORTA = 0b00000001;
		_delay_ms(1000);
		PORTA = 0b00000000;
		_delay_ms(1000);
		
		
	}
}