/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers                               	 */
/* File          : lcd.c     	                      				 	 */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "lcd.h"

GPIO_PinConfig_t Pin_Cfg ;

void delay_ms(uint32 time) {
	uint32 i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void LCD_GPIO_init() {
	Pin_Cfg.GPIO_PinNumber = RS_PIN;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = RW_PIN;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = EN_PIN;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	//============================
	// SET THE NEXT 8 PINS AS INPUT
	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_0;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_1;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_2;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_3;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_4;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_5;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_6;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_7;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	Pin_Cfg.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	MCAL_GPIO_WritePin(LCD_PORT, EN_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_RESET);

}

void LCD_clear_screen() {
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick() {
	MCAL_GPIO_WritePin(LCD_PORT, EN_PIN, GPIO_PIN_SET);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_PORT, EN_PIN, GPIO_PIN_RESET);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_INIT() {

	delay_ms(20);
	// SET THE FIRST 3 PINS AS OUPUT
	LCD_GPIO_init();
	delay_ms(15);

	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_check_lcd_isbusy() {

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_0;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_1;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_2;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_3;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_4;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_5;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_6;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	Pin_Cfg.GPIO_PinNumber = GPIO_PIN_7;
	Pin_Cfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_PORT, &Pin_Cfg);

	MCAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_RESET);

	LCD_lcd_kick();

	MCAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_RESET);


}

void LCD_WRITE_COMMAND(unsigned char command) {

	MCAL_GPIO_WritePort(LCD_PORT, command);

	MCAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_RESET);

	delay_ms(1);
	LCD_lcd_kick();

}

void LCD_WRITE_CHAR(unsigned char character) {

	MCAL_GPIO_WritePort(LCD_PORT, character);

	MCAL_GPIO_WritePin(LCD_PORT, RW_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RS_PIN, GPIO_PIN_SET);

	delay_ms(1);
	LCD_lcd_kick();
}

void LCD_WRITE_STRING(char *string) {
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) {
			LCD_GOTO_XY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}
