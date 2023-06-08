/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : main.c                           				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "STM32F103x8.h"
#include "gpio_driver.h"
#include "lcd.h"
#include "keypad.h"

void clock_init();
void gpio_init();

void my_wait(int x){
	uint8 i, j;
	for(i = 0; i < x; i++){
		for(j = 0; j < 255; j++);
	}
}

int main(void)
{
	clock_init();
	//gpio_init();
	LCD_INIT();
	Keypad_init();
	char temp;
	while(1){
		temp = Keypad_getkey();
		if(temp != 'A'){
			LCD_WRITE_CHAR(temp);
		}
//		my_wait(50);

	}
}

void clock_init(){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}

void gpio_init(){

	GPIO_PinConfig_t PINA1 = {.GPIO_PinNumber = GPIO_PIN_1,
							  .GPIO_MODE = GPIO_MODE_INPUT_PU};

	GPIO_PinConfig_t PINA2 = {.GPIO_PinNumber = GPIO_PIN_2,
							   .GPIO_MODE = GPIO_MODE_INPUT_PD};

	GPIO_PinConfig_t PINB0 = {.GPIO_PinNumber = GPIO_PIN_0,
							  .GPIO_MODE = GPIO_MODE_OUTPUT_PP,
							  .GPIO_OUTPUT_SPEED = GPIO_SPEED_2M };

	GPIO_PinConfig_t PINB1 = {.GPIO_PinNumber = GPIO_PIN_1,
							   .GPIO_MODE = GPIO_MODE_OUTPUT_PP,
							   .GPIO_OUTPUT_SPEED = GPIO_SPEED_2M };


	MCAL_GPIO_Init(GPIOA, &PINA1);
	MCAL_GPIO_Init(GPIOA, &PINA2);
	MCAL_GPIO_Init(GPIOB, &PINB0);
	MCAL_GPIO_Init(GPIOB, &PINB1);

}
