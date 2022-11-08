#include "stm32f10x.h"                  // Device header

int main(void)
{
	/* enable clock at port C*/
	RCC->APB2ENR |= (1 << 4); 
	/* configure Pin3 on GPIOC*/
	GPIOC->CRH |= (3 << 20); 		/*Output mode, max speed 50 MHz*/
	GPIOC->CRH &= ~(3 << 22);	 	/*General purpose output push-pull*/
	
	GPIOC->BSRR |= (1 << 13);
	while(1)
	{
		GPIOC->ODR |= (1 << 13);
		for(uint32_t i = 0 ; i <300000; i++);
		GPIOC->ODR &= ~(1 << 13);
		for(uint32_t i = 0 ; i <300000; i++);

	}
	return 0;
}