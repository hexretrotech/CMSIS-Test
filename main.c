#include "stm32f10x.h"

#define F_CPU 7200000UL
#define TimerTick F_CPU/1-1 //10Hz 0.1S

int i;
uint8_t state = 0;
void InitAll(void)
{
	
	RCC->APB2ENR	|= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN | RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN ;
		
	GPIOA->CRH |= 0x8B0;
	
	GPIOC->CRH	&= ~GPIO_CRH_CNF13;	
	GPIOC->CRH   |= GPIO_CRH_MODE13_0;
	
	USART1->BRR = 0x1D4C;
	USART1->CR1  |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
	

	
	
	

	SysTick->LOAD=TimerTick;
	SysTick->VAL=TimerTick;
	SysTick->CTRL =	SysTick_CTRL_CLKSOURCE_Msk |
									SysTick_CTRL_TICKINT_Msk   |
									SysTick_CTRL_ENABLE_Msk;
	
   return;
}
 


int main(void)
{
	InitAll();
	
	while(1)
	{
   	
	}
}

void SysTick_Handler(void)
{
	
	USART1->DR = 0xAA;
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
