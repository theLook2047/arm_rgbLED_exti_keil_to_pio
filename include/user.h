#include <stm32f103xb_gpio.h>
#include <stm32f103xb_exti.h>
											

void RCC_config(uint32_t RCC_APB2Periph, uint32_t RCC_APB1Periph);
void GPIO_config(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef GPIOmode);

void NVIC_Config(IRQn_Type IRQnum, uint8_t preemptNum, uint8_t subNum);
void EXTI_config(uint32_t EXTI_Line, EXTITrigger_TypeDef EXTI_Trigger);
//void EXTI_Config(GPIO_TypeDef * GPIOx, uint32_t EXTI_Line, EXTITrigger_TypeDef EXTI_Trigger);


//sysTick////////////////////////////////////////////
void delay_us(unsigned int);	
void delay_ms(unsigned int);
unsigned long millis();
unsigned long micros();
void sysTick_Init(uint32_t ticks);



;