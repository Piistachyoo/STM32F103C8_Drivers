/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : main.c 			                            		 */
/* Date          : Jul 19, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "USART_driver.h"
#include "bootloader.h"
#include "systick_driver.h"
#include "lcd_driver.h"

void UART_init(void);


int main(){

	LCD_t myLCD = {.Mode = LCD_4BIT, .GPIO_PORT = GPIOA, .Rows = LCD_2ROWS, .Display_Mode = LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON,
			.Entry_Mode = LCD_ENTRY_MODE_INC_SHIFT_OFF, .D4_PIN = GPIO_PIN_0, .D5_PIN = GPIO_PIN_1, .D6_PIN = GPIO_PIN_2, .D7_PIN = GPIO_PIN_3
	};
	LCD_Init(&myLCD);
	LCD_Send_String(&myLCD, "TEST!");
	while(1){

	}
	return 0;
}

void UART_init(void){
	USART_cfg_t myUART;
	myUART.BaudRate = UART_BaudRate_115200;
	myUART.HwFlowCtl = UART_HwFlowCtl_NONE;
	myUART.IRQ_Enable = UART_IRQ_Enable_NONE;
	myUART.P_IRQ_CallBack = NULL;
	myUART.Parity = UART_Parity_NONE;
	myUART.Payload_Length = UART_Payload_Length_8B;
	myUART.StopBits = UART_StopBits_1;
	myUART.USART_Mode = UART_Mode_TX_RX;
	MCAL_USART_Init(USART1, &myUART);
}
