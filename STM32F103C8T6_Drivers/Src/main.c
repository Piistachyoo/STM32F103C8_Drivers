/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "led_driver.h"
#include "systick_driver.h"

volatile uint32 stk_timer = 1;
volatile uint8 stk_flag = 0;


void clock_init();

int main(void)
{
	LED_cfg_t LED1;
	LED_cfg_t LED2;
	LED_cfg_t LED3;
	LED1.LED_Mode = LED_Active_High;
	LED1.LED_Port = GPIOA;
	LED1.LED_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	LED1.LED_Pin.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	LED1.LED_Pin.GPIO_PinNumber = GPIO_PIN_0;
	LED_Init(&LED1);
	LED2.LED_Mode = LED_Active_High;
	LED2.LED_Port = GPIOA;
	LED2.LED_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	LED2.LED_Pin.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	LED2.LED_Pin.GPIO_PinNumber = GPIO_PIN_1;
	LED_Init(&LED2);
	LED3.LED_Mode = LED_Active_High;
	LED3.LED_Port = GPIOA;
	LED3.LED_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	LED3.LED_Pin.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	LED3.LED_Pin.GPIO_PinNumber = GPIO_PIN_2;
	LED_Init(&LED3);

	while(1){
		LED_TurnOn(&LED1);
		MCAL_STK_Delay1ms(1000);
		LED_TurnOn(&LED2);
		MCAL_STK_Delay1ms(1000);
		LED_TurnOn(&LED3);
		MCAL_STK_Delay1ms(2000);
		LED_TurnOff(&LED3);
		MCAL_STK_Delay1ms(500);
		LED_TurnOff(&LED2);
		MCAL_STK_Delay1ms(500);
		LED_TurnOff(&LED1);
		MCAL_STK_Delay1ms(500);
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

