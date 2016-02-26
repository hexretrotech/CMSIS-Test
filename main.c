#include "stm32f10x.h"

#define F_CPU 7200000UL
#define TimerTick F_CPU/1-1 //10Hz 0.1S
int i;
uint8_t state = 0;
void InitAll(void)
{
	
   RCC->APB2ENR	|= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_IOPAEN;	
   GPIOC->CRH	&= ~GPIO_CRH_CNF13;	
 
   GPIOC->CRH   |= GPIO_CRH_MODE13_0;	
	
	
	/* EXTI->IMR |= EXTI_IMR_MR1;
	GPIOA->CRL |= 0x10;
	AFIO->EXTICR[0] |= AFIO_EXTICR1_EXTI1_PA;
	EXTI->FTSR |= EXTI_FTSR_TR1;
	EXTI->RTSR |= EXTI_RTSR_TR1;
	NVIC_EnableIRQ (EXTI1_IRQn);
	EXTI->IMR |= EXTI_IMR_MR1;
	*/
	//NVIC_EnableIRQ(SysTick_IRQn);
	SysTick->LOAD=TimerTick;
SysTick->VAL=TimerTick;
SysTick->CTRL=	SysTick_CTRL_CLKSOURCE_Msk |
                SysTick_CTRL_TICKINT_Msk   |
                SysTick_CTRL_ENABLE_Msk;
   return;
}
 
int main(void)
{
InitAll();
	GPIOC->BSRR =GPIO_BSRR_BS13;
while(1)
	{
   	
}
	}

/*void EXTI1_IRQHandler(void)
{
	
		GPIOC->BSRR =GPIO_BSRR_BS13;
		for(i=0; i<10000; i++);
   	
	
 EXTI->PR |= EXTI_PR_PR1;
}
*/
void SysTick_Handler(void)
{
	if(state == 1)
	{
		GPIOC->BSRR =GPIO_BSRR_BR13;
		state = 0;
	}
	else
	{
		GPIOC->BSRR =GPIO_BSRR_BS13;
		state = 1;
	}
}
