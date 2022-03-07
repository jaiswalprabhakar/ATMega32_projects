#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


int MeasureR();
int MeasureG();
int MeasureB();
int MeasureC();

void TCSSelectRed()
{
	PORTA &= ~(1 << PINA0);
	PORTA &= ~(1 << PINA1);
	
}

void TCSSelectGreen()
{
	PORTA = (1 << PINA0) | (1 << PINA1);
	//TCSS2High();
	//TCSS3High();
}

void TCSSelectBlue()
{
	PORTA &= ~(1 << PINA0);
	PORTA |= (1 << PINA1);
	//TCSS2Low();
	//TCSS3High();
}

void TCSSelectClear()
{
	PORTA |= (1 << PINA0);
	PORTA &= ~(1 << PINA1);
	//TCSS2High();
	//TCSS3Low();
}

int TCSMeasure()
{
	if(bit_is_set(PINB,4)==0)
	{
		while(bit_is_set(PINB,4)==0);   //Wait for rising edge
	}

	while(bit_is_set(PINB,4)==1);   //Wait for falling edge
	
	

	TCNT1=0x0000;//Reset Counter

	TCCR1B=(1<<CS10); //Prescaller = F_CPU/1 (Start Counting)

	while(bit_is_set(PINB,4)==0);   //Wait for rising edge
	int R=TCNT1;
	//float f=8000000/R;
	
	//Stop Timer
	TCCR1B=0x00;

	return R;
}

int main(void)
{
	DDRB = 0x00;
	DDRA = 0b00001111;

	
	
	
	
	

	while(1)
	{
		
			int r,g,b;
			

			r=MeasureR();
			g=MeasureG();
			b=MeasureB();
			
			int smallest;


	
			
			
			
			if((r>g) && (r>b))
			{
				smallest=r;
				//else
				//smallest=g;
			}
			else if ((g>b) && (g>r))
			{
				smallest=g;
			}
			
			
			else
			{
				smallest=b;
			}
			
			
			
			if(smallest==g)
			{
				PORTA = (1 << PINA4);
			}
			else if(smallest==r)
			{
			   PORTA = (1 << PINA5);	
			}
			else if(smallest == b)
			{
			   PORTC = (1 << PINA6);	
			}
						
	  //_delay_ms(5);
	}

}

int MeasureR()
{
	TCSSelectRed();
	int r;

	//_delay_ms(1);
	r=TCSMeasure();

	/*_delay_ms(1);
	r+=TCSMeasure();
	//_delay_ms(10);
	r+=TCSMeasure();
	*/
	return r;

}

int MeasureG()
{
	TCSSelectGreen();
	int r;

	//_delay_ms(10);
	r=TCSMeasure();

	/*_delay_ms(1);
	r+=TCSMeasure();
	//_delay_ms(10);
	r+=TCSMeasure();
	*/
	return r;

}

int MeasureB()
{
	TCSSelectBlue();
	int r;

	//_delay_ms(10);
	r=TCSMeasure();

	/*_delay_ms(1);
	r+=TCSMeasure();
	//_delay_ms(10);
	r+=TCSMeasure();
	*/
	return r;

}

int MeasureC()
{
	TCSSelectClear();
	int r;

	//_delay_ms(10);
	r=TCSMeasure();

	/*_delay_ms(1);
	r+=TCSMeasure();
	//_delay_ms(10);
	r+=TCSMeasure();
	*/
	return r;
}


