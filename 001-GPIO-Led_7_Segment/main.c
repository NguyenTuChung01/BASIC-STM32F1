#include "stm32f10x.h"                  // Device header
#include "stdint.h"

void delay(void);

int main(void)
{
	SystemInit();
	/* enable clock at port B*/
	RCC->APB2ENR |= (0x1 << 3); 
	/* configure Pin3 on GPIOC*/
	GPIOB->CRL &= ~(0xFFFFFFF << 0);		/*Reset pin PB0-6*/
	/*Set PB0-6 output push-pull and max speed 50Mhz*/ 
	GPIOB->CRL |= (0x3 << 0); 	/* PB0 */
	GPIOB->CRL |= (0x3 << 4); 	/* PB1 */
	GPIOB->CRL |= (0x3 << 8); 	/* PB2 */
	GPIOB->CRL |= (0x3 << 12); 	/* PB3 */
	GPIOB->CRL |= (0x3 << 16); 	/* PB4 */
	GPIOB->CRL |= (0x3 << 20); 	/* PB5 */
	GPIOB->CRL |= (0x3 << 24); 	/* PB6 */
	/*Turn of pin PB0 -> PB6*/
	GPIOB->ODR |= (0x7F << 0);		
	/*
	0: 0b 100 0000 -> 0x40
	1: 0b 111 1001 -> 0x79
	2: 0b 010 0100 -> 0x24
	3: 0b 011 0000 -> 0x30
	4: 0b 001 1001 -> 0x19
	5: 0b 001 0010 -> 0x12
	6: 0b 000 0010 -> 0x02
	7: 0b 111 1000 -> 0x78
	8: 0b 000 1000 -> 0x00
	9: 0b 001 0000 -> 0x10
	*/ 
	uint8_t Display_7_Seg[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78,0x00, 0x10};
	
	uint8_t i = 0;
	while(1)
	{
		if(i == 9)
		{
			i = 0;
		}
		else
		{
			GPIOB->ODR = Display_7_Seg[i];
			delay();
			i++;
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

