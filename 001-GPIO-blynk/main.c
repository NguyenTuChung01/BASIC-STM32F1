#include "stm32f10x.h"                  // Device header
#include "stdint.h"
void delay(void);

int main(void)
{
	SystemInit();
	/* enable clock at port C*/
	RCC->APB2ENR |= (0x1 << 4); 
	/* configure Pin3 on GPIOC*/
	GPIOC->CRH &= ~(0xF << 20);		/*Reset pin PC13*/
	GPIOC->CRH |= (0x3 << 20); 		/*Set output push-pull*/ 
	GPIOC->ODR |= (0x1 << 13);		/**/
	
	while(1)
	{
		GPIOC->ODR &= ~(0x1 << 13);
		delay();
		GPIOC->ODR |= (0x1 << 13);
		delay();
	}
}

void delay()
{
	volatile uint32_t i = 1000000;
	while(i)
	{
		i--;
	}
}

