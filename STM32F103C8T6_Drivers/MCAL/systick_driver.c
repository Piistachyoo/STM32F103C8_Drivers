/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : systick_driver.c			                             */
/* Date          : Jun 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "systick_driver.h"

static void (*STK_Callback)(void);
static uint8 Running_Mode; // Flag to determine the SysTick running mode

void MCAL_STK_Delay(uint32 delay_ticks){
	/* Read previous reload value */
	uint32 prev_reload = STK->LOAD;

	/* Read previous SysTick Configuration */
	uint32 prev_cfg = STK->CTRL;

	/* Disable interrupt */
	STK->CTRL &= ~(STK_INTERRUPT_MASK);

	/* Set new reload value */
	MCAL_STK_SetReload(delay_ticks);

	/* Start timer */
	MCAL_STK_StartTimer();

	/* Wait for flag to be set */
	while( ( (STK->CTRL >> 16) & 0x01UL ) == 0);

	/* Stop timer */
	MCAL_STK_StopTimer();

	/* Restore previous configuration and reload value */
	STK->LOAD = prev_reload;
	STK->CTRL = prev_cfg;
}

/**=============================================
  * @Fn				- MCAL_STK_Config
  * @brief 			- Configures the SysTick clock and interrupt
  * @param [in] 	- _cfg: Pointer to struct containing systick configuration
  * @param [out] 	- None
  * @retval 		- None
  * Note			- This function stops the timer and you have to re-enable it
  */
void MCAL_STK_Config(STK_config_t *_cfg){
	uint32 reg_copy;

	/* Mask input parameters to get rid of unneeded bits */
	_cfg->interrupt_config  &= STK_INTERRUPT_MASK;
	_cfg->clock_config 		&= STK_CLK_MASK;

	/* Apply configuration */
	reg_copy = (_cfg->interrupt_config) | (_cfg->clock_config);
	STK->CTRL = reg_copy;

	/* Set reload value */
	MCAL_STK_SetReload(_cfg->reload_value);

	/* Set callback function if interrupt is enabld */
	if(STK_INTERRUPT_ENABLED == _cfg->interrupt_config){
		MCAL_STK_SetCallback(_cfg->Callback_Function);
	}
	else{ /* Do Nothing */ }

	/* Determine running mode of the SysTick timer */
	Running_Mode = _cfg->running_mode;
}

/**=============================================
  * @Fn				- MCAL_STK_SetReload
  * @brief 			- Sets the reload value of the SysTick timer
  * @param [in] 	- value: Value to be set as reload value
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_STK_SetReload(uint32 value){
	/* Mask reload value to 24 bits */
	value &= STK_RELOAD_MASK;

	STK->LOAD = value;
}

/**=============================================
  * @Fn				- MCAL_STK_SetCallback
  * @brief 			- Sets the callback function of the systick timer interrupt
  * @param [in] 	- pfCallback: Pointer to the callback function
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_STK_SetCallback(void (*pfCallback)(void)){
	STK_Callback = pfCallback;
}

/**=============================================
  * @Fn				- MCAL_STK_StartTimer
  * @brief 			- Starts the SysTick timer
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- MCAL_STK_Config should be called first to configure the SysTick timer unless you want to use the default values
  */
void MCAL_STK_StartTimer(){
	/* Clear count register */
	STK->VAL = 0;

	/* Set the enable bit */
	STK->CTRL |= 0x01UL;
}

/**=============================================
  * @Fn				- MCAL_STK_StopTimer
  * @brief 			- Stops the SysTick timer
  * @param [in] 	- None
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_STK_StopTimer(){
	/* Reset the enable bit */
	STK->CTRL &= ~(0x01UL);
}

void SysTick_Handler(void){

	/* If SysTick running mode is one shot, disable the SysTick timer */
	if(STK_ONE_SHOT_MODE == Running_Mode){
		MCAL_STK_StopTimer();
	}
	else{ /* Do Nothing */ }

	/* Call the callback function */
	if(NULL != STK_Callback){
		STK_Callback();
	}
	else{ /* Do Nothing */ }
}
