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

/*****************************Processor Based Register**************************************/

#define NVIC_BASEADDR	0xE000E100


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

/*APB2 Mapped Registers*/

#define TIM1_BASEADDR 	(APB2_BASEADDR + 0x0000)
#define USART1_BASEADDR (APB2_BASEADDR + 0x1000)
#define USART6_BASEADDR (APB2_BASEADDR + 0x1400)
#define ADC1_BASEADDR 	(APB2_BASEADDR + 0x2000)
#define SDI0_BASEADDR 	(APB2_BASEADDR + 0x2C00)
#define SPI1_BASEADDR 	(APB2_BASEADDR + 0x3000)
#define SPI4_BASEADDR 	(APB2_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR (APB2_BASEADDR + 0x3800)
#define EXTI_BASEADDR 	(APB2_BASEADDR + 0x3C00)
#define TIM9_BASEADDR 	(APB2_BASEADDR + 0x4000)
#define TIM10_BASEADDR 	(APB2_BASEADDR + 0x4400)
#define TIM11_BASEADDR 	(APB2_BASEADDR + 0x4800)


#define RCC_BASEADDR (AHB1_BASEADDR + 0x3800)
#define FLASH_R_BASE (AHB1_BASEADDR + 0x3C00)



/*****************************Processor Based Register structure**************************************/


typedef struct{
	_vo uint32_t ISER[8];
    uint32_t RESERVED0[24];
	_vo uint32_t ICER[8];
    uint32_t RESERVED1[24];
	_vo uint32_t ISPR[8];
    uint32_t RESERVED2[24];
	_vo uint32_t ICPR[8];
    uint32_t RESERVED3[24];
    _vo uint32_t IABR[8];                 /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
	uint32_t RESERVED5[56];
	_vo uint8_t IP[250];
	_vo uint32_t STIR;

}Nvicdef_t;

#define NVIC ((Nvicdef_t*)NVIC_BASEADDR)





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

#define GPIOA ((Gpiodef_t*)GPIOA_BASEADDR)
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


/*Timer structure*/
typedef struct
{
	_vo uint32_t CR1;
	_vo uint32_t CR2;
	_vo uint32_t SMCR;
	_vo uint32_t DIER;
	_vo uint32_t SR;
	_vo uint32_t EGR;
	_vo uint16_t CCMR1H;
	_vo uint16_t CCMR1L;
	_vo uint16_t CCMR2H;
	_vo uint16_t CCMR2L;
	_vo uint32_t CCER;
	_vo uint32_t CNT;
	_vo uint32_t PSC;
	_vo uint32_t ARR;
	uint32_t  	Reserved0;
	_vo uint32_t CCR1;
	_vo uint32_t CCR2;
	_vo uint32_t CCR3;
	_vo uint32_t CCR4;
	uint32_t  	Reserved1;
	_vo uint32_t DCR;
	_vo uint32_t DMAR;
	_vo uint32_t OR;
}Timer_Regdef_t;

_vo Timer_Regdef_t *TIM2 = ((Timer_Regdef_t*)TIM10_BASEADDR);

#define TIM2 ((Timer_Regdef_t*)TIM3_BASEADDR)
#define TIM3 ((Timer_Regdef_t*)TIM3_BASEADDR)
#define TIM4 ((Timer_Regdef_t*)TIM4_BASEADDR)
#define TIM5 ((Timer_Regdef_t*)TIM5_BASEADDR)

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


typedef struct
{
	_vo uint32_t MEMRMP;  	/*!< SYSCFG memory remap register,   						Address offset: 0x00 */
	_vo uint32_t PMC;     	/*!< SYSCFG peripheral mode configuration register,   		Address offset: 0x04 */
	_vo uint32_t EXTICR1; 	/*!< SYSCFG external interrupt configuration register 1,   	Address offset: 0x08 */
	_vo uint32_t EXTICR2; 	/*!< SYSCFG external interrupt configuration register 2,   	Address offset: 0x0C */
	_vo uint32_t EXTICR3; 	/*!< SYSCFG external interrupt configuration register 3,   	Address offset: 0x10 */
	_vo uint32_t EXTICR4; 	/*!< SYSCFG external interrupt configuration register 4,   	Address offset: 0x14 */
	uint32_t Reserved0;  	/*!< SYSCFG access control register,   						Address offset: 0x18 */
	uint32_t Reserved1;  	/*!< SYSCFG access control register,   						Address offset: 0x1C */
	_vo uint32_t CMPCR;   	/*!< SYSCFG Compensation cell control register,   			Address offset: 0x20 */

} SYSCFG_TypeDef;

#define SYSCFG				((SYSCFG_TypeDef *) SYSCFG_BASEADDR)

typedef struct
{
	_vo uint32_t IMR;  		/*!< EXTI Interrupt mask register,				Address offset: 0x00 */
	_vo uint32_t EMR;   	/*!< EXTI Event mask register,   				Address offset: 0x04 */
	_vo uint32_t RTSR; 		/*!< EXTI Rising trigger selection register,   	Address offset: 0x08 */
	_vo uint32_t FTSR; 		/*!< EXTI Falling trigger selection register,   Address offset: 0x0C */
	_vo uint32_t SWIER; 	/*!< EXTI Software interrupt event register,   	Address offset: 0x10 */
	_vo uint32_t PR; 		/*!< EXTI Pending register,   					Address offset: 0x14 */
} EXTI_TypeDef;

#define EXTI				((EXTI_TypeDef *) EXTI_BASEADDR)

typedef struct
{
	_vo uint32_t SR;  		/*!< ADC Status register,							Address offset: 0x00 */
	_vo uint32_t CR[2];   	/*!< ADC Control register 1 ,Control register 2   	Address offset: 0x04, 0x08 */
	_vo uint32_t SMPR[2]; 	/*!< ADC Sample time register register,   			Address offset: 0x0C, 0x10 */
	_vo uint32_t JOFR[4]; 	/*!< ADC injected channel data offset register,  	Address offset: 0x14 - 0x20 */
	_vo uint32_t HTR; 		/*!< ADC watchdog higher threshold register,   		Address offset: 0x24 */
	_vo uint32_t LTR; 		/*!< ADC watchdog lower threshold register,   		Address offset: 0x28 */
	_vo uint32_t SQR[3]; 	/*!< ADC regular sequence register,   				Address offset: 0x2C-0X34 */
	_vo uint32_t JSQR; 		/*!< ADC injected sequence register,   				Address offset: 0x38 */
	_vo uint32_t JDR[4]; 	/*!< ADC injected data register,			 	 	Address offset: 0x3C - 0x48 */
	_vo uint32_t DR; 		/*!< ADC regular data  register,  			 		Address offset: 0x4C */

} ADC_TypeDef;

#define ADC 			((ADC_TypeDef*)ADC1_BASEADDR)


typedef struct
{
	_vo uint32_t SR;  	/*!< USART status register,						Address offset: 0x00 */
	_vo uint32_t DR;   	/*!< USART data register,						Address offset: 0x04 */
	_vo uint32_t BRR; 	/*!< USART Baud Rate register,  				Address offset: 0x08 */
	_vo uint32_t CR1; 	/*!< Control register 1,						Address offset: 0x0C */
	_vo uint32_t CR2; 	/*!< Control register 2,   						Address offset: 0x10 */
	_vo uint32_t CR3; 	/*!< Control register 3,						Address offset: 0x14 */
	_vo uint32_t GTPR; 	/*!< USART Guard time and prescaler register,   Address offset: 0x18 */

}usart_TypeDef;


#define USART ((usart_TypeDef*)USART1_BASEADDR)

#endif /* STM32F401CC_H_ */
