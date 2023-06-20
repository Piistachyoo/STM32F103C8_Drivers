/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "ss_driver.h"
#include "NVIC_driver.h"

#define delay_duration	1500

void clock_init();
void my_wait(int x);

int main(void)
{
	MCAL_NVIC_EnableIRQ(EXTI0_IRQ);
	MCAL_NVIC_EnableIRQ(EXTI1_IRQ);
	MCAL_NVIC_EnableIRQ(EXTI2_IRQ);
	MCAL_NVIC_EnableIRQ(EXTI3_IRQ);
	MCAL_NVIC_EnableIRQ(EXTI4_IRQ);
	MCAL_NVIC_EnableIRQ(EXTI5_IRQ);
	MCAL_NVIC_EnableIRQ(EXTI10_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI0_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI1_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI2_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI3_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI4_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI5_IRQ);
	MCAL_NVIC_DisableIRQ(EXTI10_IRQ);
	while(1){

	}
}

void clock_init(){
	// Enable External oscillator HSE
	RCC->CR |= (1UL<<16);
	// Set External oscillator HSE as clock source
	RCC->CFGR |= 0x01UL;
	// Wait until HSE is the clock source
	while(0x01 != ((RCC->CFGR >> 2) & 0x03UL));
	// Disable Internal osciallator HSI
	RCC->CR &= ~(1UL<<0);

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void my_wait(int x){
	uint16 i, j;
	for(i = 0; i < x; i++){
		for(j = 0; j < 255; j++);
	}
}
