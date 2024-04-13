/*
 * stm32f401cc.h
 *
 *  Created on: Mar 29, 2024
 *      Author: yadav
 */

#ifndef STM32F401CC_H_
#define STM32F401CC_H_
#include <stdint.h>

#define _vo volatile
/* Peripheral Base addresses*/
//#define PERIPHERAL_BASEADDR 0x

#define AHB1_BASEADDR	0x40020000
#define APB1_BASEADDR   0x40000000
#define APB2_BASEADDR	0x40010000
/* GPIO's base addresses */
#define GPIOA_BASEADDR (AHB1_BASEADDR + 0x0000)
#define GPIOB_BASEADDR (AHB1_BASEADDR + 0x0400)
#define GPIOC_BASEADDR (AHB1_BASEADDR + 0x0800)
#define GPIOD_BASEADDR (AHB1_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR (AHB1_BASEADDR + 0x1000)
#define GPIOH_BASEADDR (AHB1_BASEADDR + 0x1C00)


#define TIM2_BASEADDR (APB1_BASEADDR + 0x0000)
#define TIM3_BASEADDR (APB1_BASEADDR + 0x0400)
#define TIM4_BASEADDR (APB1_BASEADDR + 0x0800)
#define TIM5_BASEADDR (APB1_BASEADDR + 0x0C00)

#define TIM10_BASEADDR (APB2_BASEADDR + 0x4400)

#define RCC_BASEADDR (AHB1_BASEADDR + 0x3800)
#define FLASH_R_BASE (AHB1_BASEADDR + 0x3C00)

/* structure for the GPIO*/
typedef struct{
	_vo uint32_t  MODER;
	_vo uint32_t OTYPER;
	_vo uint32_t OSPEEDR;
	_vo uint32_t PUPDR;
	_vo uint32_t IDR;
	_vo uint32_t ODR;
	_vo uint32_t BSRR;
	_vo uint32_t LCKR;
	_vo uint32_t AFRL;
	_vo uint32_t AFRH;

}Gpiodef_t;

#define GPIOA 	((Gpiodef_t*)GPIOA_BASEADDR)
#define GPIOB ((Gpiodef_t*)GPIOB_BASEADDR)
#define GPIOC ((Gpiodef_t*)GPIOC_BASEADDR)
#define GPIOD ((Gpiodef_t*)GPIOD_BASEADDR)
#define GPIOE ((Gpiodef_t*)GPIOE_BASEADDR)
#define GPIOF ((Gpiodef_t*)GPIOF_BASEADDR)
#define GPIOH ((Gpiodef_t*)GPIOH_BASEADDR)


/* RCC register map */


typedef struct{

	_vo uint32_t CR;			/* RCC clock control register, Address offset: 0x00 */
	_vo uint32_t PLLCFGR;		/* RCC PLL configuration register, Address offset: 0x04 */
	_vo uint32_t CFGR;			/* RCC clock configuration register, Address offset: 0x08 */
	_vo uint32_t CIR;			/* RCC clock interrupt register, Address offset: 0x0C */
	_vo uint32_t AHB1RSTR;		/* RCC AHB1 peripheral reset register, Address offset: 0x10 */
	_vo uint32_t AHB2RSTR;		/* RCC AHB2 peripheral reset register, Address offset: 0x14 */
	_vo uint32_t AHB3RSTR;		/* RCC AHB3 peripheral reset register, Address offset: 0x18 */
	uint32_t  	Reserved0;		/* Reserved , Address offset: 0x1C */
	_vo uint32_t APB1RSTR;		/* RCC APB1 peripheral reset register, Address offset: 0x20 */
	_vo uint32_t APB2RSTR;		/* RCC APB2 peripheral reset register, Address offset: 0x24 */
	uint32_t  	Reserved1;		/* Reserved , Address offset: 0x28 */
	uint32_t  	Reserved2;		/* Reserved , Address offset: 0x2C */
	_vo uint32_t AHB1ENR;		/* RCC AHB1 peripheral clock register, Address offset: 0x30 */
	_vo uint32_t AHB2ENR;		/* RCC AHB2 peripheral clock register, Address offset: 0x34 */
	_vo uint32_t AHB3ENR;		/* RCC AHB3 peripheral clock register, Address offset: 0x38 */
	uint32_t  	Reserved3;		/* Reserved , Address offset: 0x3C */
	_vo uint32_t APB1ENR;		/* RCC APB1 peripheral clock register, Address offset: 0x40 */
	_vo uint32_t APB2ENR;		/* RCC APB2 peripheral clock register, Address offset: 0x44 */
	uint32_t  	Reserved4;		/* Reserved , Address offset: 0x48 */
	uint32_t  	Reserved5;		/* Reserved , Address offset: 0x4C */
	_vo uint32_t AHB1LPENR;		/* RCC  AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	_vo uint32_t AHB2LPENR;		/* RCC  AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	_vo uint32_t AHB3LPENR;		/* RCC  AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
	uint32_t  	Reserved6;		/* Reserved , Address offset: 0x5C */
	_vo uint32_t APB1LPENR;		/* RCC  APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	_vo uint32_t APB2LPENR;		/* RCC  APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	uint32_t  	Reserved7;		/* Reserved , Address offset: 0x68 */
	uint32_t  	Reserved8;		/* Reserved , Address offset: 0x6C */
	_vo uint32_t BDCR;			/* RCC Backup domain control register, Address offset: 0x70 */
	_vo uint32_t CSR;			/* RCC clock control & status register, Address offset: 0x74 */
	uint32_t  	Reserved9;		/* Reserved , Address offset: 0x78 */
	uint32_t  	Reserved10;		/* Reserved , Address offset: 0x7C */
	_vo uint32_t SSCGR;			/* RCC clock control & status register, Address offset: 0x80 */
	_vo uint32_t PLLI2SCFGR;	/* RCC PLLI2S configuration register, Address offset: 0x70 */
	_vo uint32_t PLLSAICFGR;	/* RCC  PLL configuration register, Address offset: 0x70 */
	_vo uint32_t DCKCFGR;		/* RCC  Dedicated Clock Configuration Register, Address offset: 0x70 */
}RCC_Refdef_t;

#define RCC ((RCC_Refdef_t*)RCC_BASEADDR)
_vo RCC_Refdef_t *Rcc = ((RCC_Refdef_t*)RCC_BASEADDR);


/*Timer structure*/
typedef struct
{
	_vo uint32_t TIM_CR1;
	_vo uint32_t TIM_CR2;
	_vo uint32_t TIM_SMCR;
	_vo uint32_t TIM_DIER;
	_vo uint32_t TIM_SR;
	_vo uint32_t TIM_EGR;
	_vo uint16_t TIM_CCMR1H;
	_vo uint16_t TIM_CCMR1L;
	_vo uint16_t TIM_CCMR2H;
	_vo uint16_t TIM_CCMR2L;
	_vo uint32_t TIM_CCER;
	_vo uint32_t TIM_CNT;
	_vo uint32_t TIM_PSC;
	_vo uint32_t TIM_ARR;
	uint32_t  	Reserved0;
	_vo uint32_t TIM_CCR1;
	_vo uint32_t TIM_CCR2;
	_vo uint32_t TIM_CCR3;
	_vo uint32_t TIM_CCR4;
	uint32_t  	Reserved1;
	_vo uint32_t TIM_DCR;
	_vo uint32_t TIM_DMAR;
	_vo uint32_t TIM_OR;

}Timer_Regdef_t;

_vo Timer_Regdef_t *TIM2 = ((Timer_Regdef_t*)TIM10_BASEADDR);

#define TIM3 ((Timer_Regdef_t*)TIM3_BASEADDR)



/**
  * @brief FLASH Registers
  */

typedef struct
{
  _vo uint32_t ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
  _vo uint32_t KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
  _vo uint32_t OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
  _vo uint32_t SR;       /*!< FLASH status register,           Address offset: 0x0C */
  _vo uint32_t CR;       /*!< FLASH control register,          Address offset: 0x10 */
  _vo uint32_t OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
  _vo uint32_t OPTCR1;   /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#endif /* STM32F401CC_H_ */
