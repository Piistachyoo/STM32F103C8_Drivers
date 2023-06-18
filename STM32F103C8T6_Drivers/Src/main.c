/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "ss_driver.h"

#define delay_duration	1500

void clock_init();
void my_wait(int x);

int main(void)
{
	clock_init();
	SS_cfg_t SSD1;
	SSD1.PINS[0].PIN.GPIO_PinNumber = GPIO_PIN_0;
	SSD1.PINS[1].PIN.GPIO_PinNumber = GPIO_PIN_1;
	SSD1.PINS[2].PIN.GPIO_PinNumber = GPIO_PIN_2;
	SSD1.PINS[3].PIN.GPIO_PinNumber = GPIO_PIN_3;
	SSD1.PINS[4].PIN.GPIO_PinNumber = GPIO_PIN_4;
	SSD1.PINS[5].PIN.GPIO_PinNumber = GPIO_PIN_5;
	SSD1.PINS[6].PIN.GPIO_PinNumber = GPIO_PIN_6;
	SSD1.PINS[7].PIN.GPIO_PinNumber = GPIO_PIN_7;
	SSD1.Active_Mode = SS_Common_Cathode;
	for(int i = 0; i < 8; i++){
		SSD1.PINS[i].PORT = GPIOA;
		SSD1.PINS[i].PIN.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		SSD1.PINS[i].PIN.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	}
	SS_Init(&SSD1);
	SS_Display_Number(&SSD1, SS_ZERO, SS_DOT_ON);
	while(1){
		SS_Display_Number(&SSD1, SS_ZERO, SS_DOT_ON);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_ONE, SS_DOT_OFF);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_TWO, SS_DOT_ON);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_THREE, SS_DOT_OFF);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_FOUR, SS_DOT_ON);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_FIVE, SS_DOT_OFF);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_SIX, SS_DOT_ON);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_SEVEN, SS_DOT_OFF);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_EIGHT, SS_DOT_ON);
		my_wait(1000);
		SS_Display_Number(&SSD1, SS_NINE, SS_DOT_OFF);
		my_wait(1000);
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
