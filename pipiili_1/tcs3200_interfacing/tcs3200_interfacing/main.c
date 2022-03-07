#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>


int MeasureR();
int MeasureG();
int MeasureB();
int MeasureC();

void TCSSelectRed()
{
	PORTA &= ~(1 << PINA1);
	PORTA &= ~(1 << PINA2);
	
}

void TCSSelectGreen()
{
	PORTA = (1 << PINA1) | (1 << PINA2);
	//TCSS2High();
	//TCSS3High();
}

void TCSSelectBlue()
{
	PORTA &= ~(1 << PINA1);
	PORTA |= (1 << PINA2);
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
	
	
	
	//Stop Timer
	TCCR1B=0x00;
    float f;
	f= 16000000/TCNT1;
	return f;
}








 int main()
{
	//DDRD = 0x00;
	DDRA = 0xFF;
	DDRB = 0x00;
	PORTA |= (1 <<PINA3) | (1 << PINA4);
	
	
	
	

	while(1)
	{
		  int count_r ;
		  int count_b;
		  int count_g ;
		  char result;
		  int r,g,b;

		
		
	      for(int i=0; i< 10;++i)
		  {
	
			r=MeasureR();
			g=MeasureG();
			b=MeasureB();

		  
		   
		   			
		   if((r<g) && (r<b))
			{
				//smallest=r;
				count_r++ ;
				//else
				//smallest=g;
			}
			else if ((g<b) && (g<r))
			{
			//	smallest=g;
			   count_g++;
			}
			
			
			else
			{
				//smallest=b;
			    count_b++;
			}
			
//			char small[10]={};
//			 small[i]= smallest;
           
		  }    
		  
		  
		      if(count_r>count_b && count_r> count_g)
			   {
			    result=r;
		       } 
			  else if(count_g>count_b && count_g>count_r)
			   {
				  result=g;
			   }
			   else  
			    {
				  result=b;
				}  
			
		
	
		
			
			if(result==g)
			{
				PORTA = (1<< PINA5);
			}
			else if(result==r)
			{
			   PORTA = (1 << PINA6);	
			}
			else if(result == b)
			{
			   PORTA = (1 << PINA7);	
			}
						
	 
	}

}

int MeasureR()
{
	TCSSelectRed();
	int r;

	_delay_ms(1);
	r=TCSMeasure();

	_delay_ms(1);
	r+=TCSMeasure();

	_delay_ms(1);
	r+=TCSMeasure();
	
	return r/3.3;

}

int MeasureG()
{
	TCSSelectGreen();
	int r;

	_delay_ms(1);
	r=TCSMeasure();

	_delay_ms(1);
	r+=TCSMeasure();

	_delay_ms(10);
	r+=TCSMeasure();
	
	return r/3;

}

int MeasureB()
{
	TCSSelectBlue();
	int r;

	_delay_ms(1);
	r=TCSMeasure();

	_delay_ms(1);
	r+=TCSMeasure();

    _delay_ms(1);
	r+=TCSMeasure();
	
	return r/4.2;

}

int MeasureC()
{
	TCSSelectClear();
	int r;

	_delay_ms(10);
	r=TCSMeasure();

	_delay_ms(1);
	r+=TCSMeasure();

	_delay_ms(10);
	r+=TCSMeasure();
	
	return r;
}
