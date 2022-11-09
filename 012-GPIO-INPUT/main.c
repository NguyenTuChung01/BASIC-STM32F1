#include "stm32f10x.h"                  			// Device header
#include "stdint.h"
int main()
{
	RCC->APB2ENR |= (1 << 2); 									/*enable port A*/
	RCC->APB2ENR |= (1 << 4);										/*enable port C*/
	GPIOA->CRL &=(unsigned int)~(0xF << 0); 		/*reset portC 0 */
	GPIOA->CRL |= (0x2 << 2);										/*set portC 0 input push pull */
	while(1)
	{
	}
}