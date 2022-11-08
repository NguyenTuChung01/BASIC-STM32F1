#include "stm32f10x.h"                  // Device header

int main(void)
{
	/* enable clock at port C*/
	RCC->APB2ENR |= (1 << 4); 
	/* configure Pin3 on GPIOC*/
	GPIOC->CRH |= ( (1 << 20) | (1 << 21) ); 		/*Output mode, max speed 50 MHz*/
	GPIOC->CRH &= ~( (1 << 22) | (1 << 23) );	 	/*General purpose output push-pull*/
	while(1)
	{
		int i;
		GPIOC->BSRR |= (1 << 13);
		for(i = 0; i <10000; i++);
		GPIOC->BSRR &= ~(1 << 13);
		for(i = 0; i <= 10000; i++);

	}
	return 0;
}