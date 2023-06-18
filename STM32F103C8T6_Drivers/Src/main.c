/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "led_driver.h"

#define delay_duration	1500

void clock_init();
void my_wait(int x);

int main(void)
{
	clock_init();
	LED_cfg_t LEDA0;
	LED_cfg_t LEDB0;
	LEDA0.LED_Port = GPIOA;
	LEDA0.LED_Pin.GPIO_PinNumber = GPIO_PIN_0;
	LEDA0.LED_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	LEDA0.LED_Pin.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	LEDA0.LED_Mode = LED_Active_High;
	LEDB0.LED_Port = GPIOB;
	LEDB0.LED_Pin.GPIO_PinNumber = GPIO_PIN_0;
	LEDB0.LED_Pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	LEDB0.LED_Pin.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	LEDB0.LED_Mode = LED_Active_High;
	LED_Init(&LEDA0);
	LED_Init(&LEDB0);
	while(1){
		LED_Toggle(&LEDA0);
		my_wait(delay_duration);
		LED_Toggle(&LEDB0);
		my_wait(delay_duration);
		LED_Toggle(&LEDA0);
		my_wait(delay_duration);
		LED_Toggle(&LEDB0);
		my_wait(delay_duration);
	}
}

void clock_init(){
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
