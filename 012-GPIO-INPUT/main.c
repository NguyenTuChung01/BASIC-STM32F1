#include "stm32f10x.h"                  			// Device header
#include "stdint.h"

void delay(void);

int main()
{
	RCC->APB2ENR |= (1 << 2); 									/*enable port A*/
	RCC->APB2ENR |= (1 << 4);										/*enable port C*/
	GPIOA->CRL &=(unsigned int)~(0xF << 0); 		/*reset portC 0 */
	GPIOA->CRL |= (0x2 << 2);										/*set portC 0 input push pull */
	GPIOC->CRH &= (unsigned int)~(0xF << 20);		/*Reset pin PC13*/
	GPIOC->CRH |= (0x3 << 20); 									/*Set output push-pull*/ 
	while(1)
	{
		if(GPIOA->IDR & 0x1)
		{
			GPIOC->ODR &= (unsigned int)~(0x1 << 13);
			delay();
		}
		else
		{
			GPIOC->ODR |= (0x1 << 13);
			delay();
		}
	}
}

void delay()
{
	volatile uint32_t i = 100000;
	while(i)
	{
		i--;
	}
}
