#include "function.h"
#include "stm32f10x.h"

uint8_t modeR[8] = {0b1111, 0b0100, 0b1000, 0b1000, 0b0000, 0b0111, 0b0011, 0b1011};

void APinConf(int pin, int mode, int port)
{
	int SPort = 1;
	switch(port)
	{
		case 1:
			if(pin > 7)
			{
				GPIOA->CRH &= 0b0000 << ((pin - 10) * 4);
				GPIOA->CRH &= modeR[mode] << ((pin - 10) * 4);
			}
			else
			{
				GPIOA->CRL &= 0b0000 << (pin * 4);
				GPIOA->CRL &= modeR[mode] << (pin * 4);
			}
			break;
		case 2:
			if(pin > 7)
			{
				GPIOB->CRH &= 0b0000 << ((pin - 10) * 4);
				GPIOB->CRH &= modeR[mode] << ((pin - 10) * 4);
			}
			else
			{
				GPIOB->CRL &= 0b0000 << (pin * 4);
				GPIOB->CRL &= modeR[mode] << (pin * 4);
			}
			break;
		case 3:
			if(pin > 7)
			{
				GPIOC->CRH &= 0b0000 << ((pin - 10) * 4);
				GPIOC->CRH &= modeR[mode] << ((pin - 10) * 4);
			}
			else
			{
				GPIOC->CRL &= 0b0000 << (pin * 4);
				GPIOC->CRL &= modeR[mode] << (pin * 4);
			}
			break;
	}
	
}
