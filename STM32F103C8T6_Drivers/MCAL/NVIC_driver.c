/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : NVIC_driver.c 			                             */
/* Date          : Jun 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "NVIC_driver.h"

/**=============================================
  * @Fn				- MCAL_NVIC_SetPriorityGrouping
  * @brief 			- Set the priority grouping
  * @param [in] 	- priority_grouping: Configuration of priority grouping @ref priority_groups_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_SetPriorityGrouping(uint32 priority_grouping){
	uint32 reg_value;

	/* Make sure only bits 8-10 are set */
	priority_grouping &= NVIC_PRIGROUP_SET_MASK;

	/* Get current register status */
	reg_value = SCB->AIRCR;

	/* Convert VECTKEYSTAT to VECTKEY */
	reg_value ^= SCB_VECTKEY_MASK;

	/* Clear previous priority grouping configuration */
	reg_value &= NVIC_PRIGROUP_CLEAR_MASK;

	/* Add current configuration */
	reg_value |= priority_grouping;

	/* Set value back to register */
	SCB->AIRCR = reg_value;
}

/**=============================================
  * @Fn				- MCAL_NVIC_EnableIRQ
  * @brief 			- Enable IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_EnableIRQ(uint8 IRQn){
	/* Check which ISER register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

	NVIC->ISER[reg_index] = (1U<<IRQ_index);
}

/**=============================================
  * @Fn				- MCAL_NVIC_DisableIRQ
  * @brief 			- Disable IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_DisableIRQ(uint8 IRQn){
	/* Check which ICER register to write into */
	uint8 reg_index = IRQn/32;

	/* Get IRQn with respect to current register */
	uint8 IRQ_index = IRQn%32;

	NVIC->ICER[reg_index] = (1U<<IRQ_index);
}
