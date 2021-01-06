#include "stm32f1xx.h"


static volatile unsigned long tickMicros;
static unsigned TimingDelay;


void TimingDelay_Decrement()
{
	if(TimingDelay != 0x00) 
		TimingDelay--;
	
	++tickMicros;	
} 	
		
void delay_us(unsigned int nTime) 
{
	TimingDelay = nTime/10;
	while(TimingDelay != 0) ;
}
	
void delay_ms(unsigned int nTime)
{
	TimingDelay = nTime * 100;
	while(TimingDelay != 0) ;
}
		
unsigned long millis()
{
	return tickMicros/100;
}
 
unsigned long micros()
{
	return tickMicros;
}


void sysTick_Init(uint32_t ticks)
{
	while(SysTick_Config(ticks))
	;
}