/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* Project       : STM32F103C8T6_Drivers  	                             */
/* File          : STM32F103x8.h 			                             */
/* Date          : Jun 8, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef INC_STM32F103X8_H_
#define INC_STM32F103X8_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include <stdlib.h>
#include "Platform_Types.h"

//----------------------------------------------
// Section: Base addresses for Memories
//----------------------------------------------

#define FLASH_MEMORY_BASE					0x08000000UL
#define SYSTEM_MEMORY_BASE					0x1FFFF000UL
#define SRAM_MEMORY_BASE					0x20000000UL
#define PERIPHERALS_BASE					0x40000000UL
#define Cortex_M3_Internal_Peripherals_Base	0xE0000000UL


//----------------------------------------------
// Section: Base addresses for Cortex-M3 Peripherals
//----------------------------------------------

#define NVIC_BASE							0xE000E100UL
#define SCB_BASE							0xE000ED00UL
#define STK_BASE							0xE000E010UL

	/* NVIC: */
#define NVIC_ISER0			(*(vuint32_t*)(NVIC_BASE + 0x000))
#define NVIC_ISER1			(*(vuint32_t*)(NVIC_BASE + 0x004))
#define NVIC_ISER2			(*(vuint32_t*)(NVIC_BASE + 0x008))
#define NVIC_ICER0			(*(vuint32_t*)(NVIC_BASE + 0x080))
#define NVIC_ICER1			(*(vuint32_t*)(NVIC_BASE + 0x084))
#define NVIC_ICER2			(*(vuint32_t*)(NVIC_BASE + 0x088))
#define NVIC_ISPR0			(*(vuint32_t*)(NVIC_BASE + 0x100))
#define NVIC_ISPR1			(*(vuint32_t*)(NVIC_BASE + 0x104))
#define NVIC_ISPR2			(*(vuint32_t*)(NVIC_BASE + 0x108))
#define NVIC_ICPR0			(*(vuint32_t*)(NVIC_BASE + 0x180))
#define NVIC_ICPR1			(*(vuint32_t*)(NVIC_BASE + 0x184))
#define NVIC_ICPR2			(*(vuint32_t*)(NVIC_BASE + 0x188))
#define NVIC_IABR0			(*(vuint32_t*)(NVIC_BASE + 0x200))
#define NVIC_IABR1			(*(vuint32_t*)(NVIC_BASE + 0x204))
#define NVIC_IABR2			(*(vuint32_t*)(NVIC_BASE + 0x208))

#define NVIC_IPR0			(*(vuint32_t*)(NVIC_BASE + 0x300))
#define NVIC_IPR2			(*(vuint32_t*)(NVIC_BASE + 0x320))
#define NVIC_STIR			(*(vuint32_t*)(NVIC_BASE + 0xE00))



/*
	 SCB

#define SCB_CPUID			(*(vuint32_t*)(SCB_BASE))
#define SCB_ICSR			(*(vuint32_t*)(SCB_BASE + 0x04))
#define SCB_VTOR			(*(vuint32_t*)(SCB_BASE + 0x08))
#define SCB_AIRCR			(*(vuint32_t*)(SCB_BASE + 0x0C))
#define SCB_SCR				(*(vuint32_t*)(SCB_BASE + 0x10))
#define SCB_CCR				(*(vuint32_t*)(SCB_BASE + 0x14))
#define SCB_SHPR1			(*(vuint32_t*)(SCB_BASE + 0x18))
#define SCB_SHPR2			(*(vuint32_t*)(SCB_BASE + 0x1C))
#define SCB_SHPR3			(*(vuint32_t*)(SCB_BASE + 0x20))
#define SCB_SHCRS			(*(vuint32_t*)(SCB_BASE + 0x24))
#define SCB_CFSR			(*(vuint32_t*)(SCB_BASE + 0x28))
#define SCB_HFSR			(*(vuint32_t*)(SCB_BASE + 0x2C))
#define SCB_MMAR			(*(vuint32_t*)(SCB_BASE + 0x34))
#define SCB_BFAR			(*(vuint32_t*)(SCB_BASE + 0x38))



	 SysTick
#define STK_CTRL			(*(vuint32_t*)(STK_BASE + 0x00))
#define STK_LOAD			(*(vuint32_t*)(STK_BASE + 0x04))
#define STK_VAL				(*(vuint32_t*)(STK_BASE + 0x08))
#define STK_CALIB			(*(vuint32_t*)(STK_BASE + 0x0C))
*/

//----------------------------------------------
// Section: Base addresses for AHB Peripherals
//----------------------------------------------

	/* RCC: */
#define RCC_BASE	0x40021000UL

//----------------------------------------------
// Section: Base addresses for APB2 Peripherals
//----------------------------------------------

	/* GPIO:
	 * Ports A, B fully included in LQFP48 Package
	 * Ports C, D Partially included in LQFP48 Package
	 * Ports E, F, G not included in LQFP48 Package    */
#define GPIOA_BASE	0x40010800UL
#define GPIOB_BASE	0x40010C00UL
#define GPIOC_BASE	0x40011000UL
#define GPIOD_BASE	0x40011400UL
#define GPIOE_BASE	0x40011800UL
#define GPIOF_BASE	0x40011C00UL
#define GPIOG_BASE	0x40012000UL

		/* EXTI: */
#define EXTI_BASE	0x40010400UL

		/* AFIO */
#define AFIO_BASE	0x40010000UL

//----------------------------------------------
// Section: Base addresses for APB1 Peripherals
//----------------------------------------------



//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

		/* NVIC */
typedef struct{
	vuint32_t ISER[3];
	uint32 RESERVED0[29];
	vuint32_t ICER[3];
	uint32 RESERVED1[29];
	vuint32_t ISPR[3];
	uint32 RESERVED2[29];
	vuint32_t ICPR[3];
	uint32 RESERVED3[29];
	vuint32_t IABR[3];
	uint32 RESERVED4[61];
	vuint8_t IP[80];
	uint32 RESERVED5[684];
	vuint32_t STIR;
}NVIC_TypeDef;

		/* SCB */
typedef struct{
	vuint32_t CPUID;
	vuint32_t ICSR;
	vuint32_t VTOR;
	vuint32_t AIRCR;
	vuint32_t SCR;
	vuint32_t CCR;
	vuint8_t  SHP[12];
	vuint32_t SHCSR;
	vuint32_t CFSR;
	vuint32_t HFSR;
	uint32	  RESERVED;
	vuint32_t MMAR;
	vuint32_t BFAR;
}SCB_TypeDef;

		/* STK */
typedef struct{
	vuint32_t CTRL;
	vuint32_t LOAD;
	vuint32_t VAL;
	vuint32_t CALIB;
}STK_TypeDef;

		/* GPIO */
typedef struct{
	vuint32_t CRL;
	vuint32_t CRH;
	vuint32_t IDR;
	vuint32_t ODR;
	vuint32_t BSRR;
	vuint32_t BRR;
	vuint32_t LCKR;
}GPIO_TypeDef;

		/* RCC */
typedef struct{
	vuint32_t CR;
	vuint32_t CFGR;
	vuint32_t CIR;
	vuint32_t APB2RSTR;
	vuint32_t APB1RSTR;
	vuint32_t AHBENR;
	vuint32_t APB2ENR;
	vuint32_t APB1ENR;
	vuint32_t BDCR;
	vuint32_t CSR;
}RCC_TypeDef;

		/* EXTI */
typedef struct{
	vuint32_t IMR;
	vuint32_t EMR;
	vuint32_t RTSR;
	vuint32_t FTSR;
	vuint32_t SWIER;
	vuint32_t PR;
}EXTI_TypeDef;

		/* AFIO */
typedef struct{
	vuint32_t EVCR;
	vuint32_t MAPR;
	vuint32_t EXTICR[4];
	uint32	  RESERVED0;
	vuint32_t MAPR2;
}AFIO_TypeDef;

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Peripheral instants
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC		((NVIC_TypeDef*)NVIC_BASE)
#define SCB			((SCB_TypeDef* )SCB_BASE )
#define STK			((STK_TypeDef* )STK_BASE )

#define GPIOA		((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB		((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC		((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD		((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE		((GPIO_TypeDef*)GPIOE_BASE)
#define GPIOF		((GPIO_TypeDef*)GPIOF_BASE)
#define GPIOG		((GPIO_TypeDef*)GPIOG_BASE)

#define RCC			((RCC_TypeDef*)RCC_BASE)

#define EXTI		((EXTI_TypeDef*)EXTI_BASE)

#define AFIO		((AFIO_TypeDef*)AFIO_BASE)

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Clock enable macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define	RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= (1<<2))
#define	RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= (1<<3))
#define	RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= (1<<4))
#define	RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= (1<<5))
#define	RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= (1<<6))
#define	RCC_GPIOF_CLK_EN()	(RCC->APB2ENR |= (1<<7))
#define	RCC_GPIOG_CLK_EN()	(RCC->APB2ENR |= (1<<8))

#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= (1<<0))

//======================================================//

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: NVIC IRQ enable/disable Macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC_IRQ6_EXTI0_Enable()		(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Enable()		(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable()		(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable()		(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable()		(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Enable()		(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Enable()	(NVIC_ISER1 |= (1<<8))


#define NVIC_IRQ6_EXTI0_Disable()		(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_Disable()		(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Disable()		(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Disable()		(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Disable()		(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_Disable()	(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_15_Disable()	(NVIC_ICER1 |= (1<<8))


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Section: Generic macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#endif /* INC_STM32F103X8_H_ */
