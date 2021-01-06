#include "user.h"
#include <stm32f103xb_rcc.h>



int main(void)
{
	RCC_config(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO , 0);
	GPIO_config(GPIOA, GPIO_Pin_4 | GPIO_Pin_1, GPIO_Mode_IN_FLOATING);	
	GPIO_config(GPIOB, GPIO_Pin_0, GPIO_Mode_IN_FLOATING);	
	GPIO_config(GPIOC, GPIO_Pin_12 | GPIO_Pin_11 | GPIO_Pin_10, GPIO_Mode_Out_PP);	
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1); 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource4); 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource0);  
	
	EXTI_config(EXTI_Line0 | EXTI_Line1 | EXTI_Line4, EXTI_Trigger_Rising);	
	NVIC_Config(EXTI0_IRQn, 0, 0);	
	NVIC_Config(EXTI1_IRQn, 0, 0);	
	NVIC_Config(EXTI4_IRQn, 0, 0);	
	
	GPIOC->BSRR |= GPIO_Pin_12 | GPIO_Pin_11 | GPIO_Pin_10; // LED OFF(PULLUP)
	
	
	while (1) {}


}





