/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : NVIC_driver.h 			                             */
/* Date          : Jun 20, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_NVIC_DRIVER_H_
#define INC_NVIC_DRIVER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "STM32F103x8.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------



//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------

#define SCB_VECTKEY_MASK			0xFFFF0000UL
#define NVIC_PRIGROUP_SET_MASK		0x700UL
#define NVIC_PRIGROUP_CLEAR_MASK	0xFFFFF8FFUL

// @ref priority_groups_define
#define NVIC_PRIO_16GRP_0SUBGRP		0x300U
#define NVIC_PRIO_8GRP_2SUBGRP		0x400U
#define NVIC_PRIO_4GRP_4SUBGRP		0x500U
#define NVIC_PRIO_2GRP_8SUBGRP		0x600U
#define NVIC_PRIO_0GRP_8SUBGRP		0x700U

// @ref Interrupt_Requests_Numbers_define
#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ	40
#define EXTI11_IRQ	40
#define EXTI12_IRQ	40
#define EXTI13_IRQ	40
#define EXTI14_IRQ	40
#define EXTI15_IRQ	40

/*
 * =============================================
 * APIs Supported by "NVIC"
 * =============================================
 */

/**=============================================
  * @Fn				- MCAL_NVIC_SetPriorityGrouping
  * @brief 			- Set the priority grouping
  * @param [in] 	- priority_grouping: Configuration of priority grouping @ref priority_groups_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_SetPriorityGrouping(uint32 priority_grouping);

/**=============================================
  * @Fn				- MCAL_NVIC_EnableIRQ
  * @brief 			- Enable IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_EnableIRQ(uint8 IRQn);

/**=============================================
  * @Fn				- MCAL_NVIC_DisableIRQ
  * @brief 			- Disable IRQn
  * @param [in] 	- IRQn: Number of interrupt request as defined in vector table or in @ref Interrupt_Requests_Numbers_define
  * @param [out] 	- None
  * @retval 		- None
  * Note			- None
  */
void MCAL_NVIC_DisableIRQ(uint8 IRQn);

/**=============================================
  * @Fn				-
  * @brief 			-
  * @param [in] 	-
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
uint8 MCAL_NVIC_GetPendingIRQ(uint8 IRQn);

/**=============================================
  * @Fn				-
  * @brief 			-
  * @param [in] 	-
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
void MCAL_NVIC_SetPendingIRQ(uint8 IRQn);

/**=============================================
  * @Fn				-
  * @brief 			-
  * @param [in] 	-
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
void MCAL_NVIC_ClearPendingIRQ(uint8 IRQn);

/**=============================================
  * @Fn				-
  * @brief 			-
  * @param [in] 	-
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
uint8 MCAL_NVIC_GetActive(uint8 IRQn);

/**=============================================
  * @Fn				-
  * @brief 			-
  * @param [in] 	-
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
void MCAL_NVIC_SetPriority(uint8 IRQn, uint8 priority);

/**=============================================
  * @Fn				-
  * @brief 			-
  * @param [in] 	-
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
uint8 MCAL_NVIA_GetPriority(uint8 IRQn);

/**=============================================
  * @Fn				-
  * @brief 			-
  * @param [in] 	-
  * @param [out] 	-
  * @retval 		-
  * Note			-
  */
void MCAL_NVIC_SystemReset(void);

#endif /* INC_NVIC_DRIVER_H_ */
