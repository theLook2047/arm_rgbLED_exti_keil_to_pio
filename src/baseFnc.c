#include <stm32f103xb_rcc.h>
#include <stm32f103xb_gpio.h>
#include <misc_103xb.h>
#include <stm32f103xb_exti.h>



void RCC_config(uint32_t RCC_APB2Periph, uint32_t RCC_APB1Periph)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph, ENABLE);
}




void GPIO_config(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef GPIOmode)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//user LED : A5
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIOmode;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}


void NVIC_Config(IRQn_Type IRQnum, uint8_t preemptNum, uint8_t subNum)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Enable the TIM2 global Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = (uint8_t)IRQnum;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = preemptNum;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = subNum;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&NVIC_InitStructure);
}


void EXTI_config(uint32_t EXTI_Line, EXTITrigger_TypeDef EXTI_Trigger)
{
	EXTI_InitTypeDef   EXTI_InitStructure;
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line;            // param
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger;      // param
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);                                                 
}



//void EXTI_Config(GPIO_TypeDef * GPIOx, uint32_t EXTI_Line, EXTITrigger_TypeDef EXTI_Trigger)
//{
//	GPIO_InitTypeDef   GPIO_InitStructure;
//	EXTI_InitTypeDef   EXTI_InitStructure;
//	int portSource=( (int)GPIOx-(int)GPIOA )/0x400;
//	int pos;
//	uint32_t tmpLine=EXTI_Line;
//	
//	for(pos=-1; tmpLine; tmpLine>>=1, ++pos);
//	
//	RCC_APB2PeriphClockCmd(0x4<<portSource | RCC_APB2Periph_AFIO, ENABLE);

//	/* Configure pin as input floating */
//	GPIO_InitStructure.GPIO_Pin = (uint16_t)EXTI_Line;    // param
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//	GPIO_Init(GPIOx, &GPIO_InitStructure);

//	/* Connect EXTIn Line to port pin */
//	GPIO_EXTILineConfig(portSource, (uint8_t)pos);      // params just decimal value;      

//	/* Configure EXTIn line */
//	EXTI_InitStructure.EXTI_Line = EXTI_Line;            // param
//	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger;      // param
//	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//	EXTI_Init(&EXTI_InitStructure);                                                 
//	
//	/* Enable and set EXTIn Interrupt to the lowest priority */
//	NVIC_Config(EXTI15_10_IRQn, 0, 0);
//}


