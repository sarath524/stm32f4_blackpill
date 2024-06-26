/***************************************************************************//**
*   \file       main.c
*
*   \details    Blinking Onboard LED with 1 second delay using Timer Interrupt
*               - STM32 Timer Interrupt Tutorial
*
*   \author     EmbeTronicX
*
*   \This code is verified with STM32411CE Board
*
*******************************************************************************/

#include "stm32f401cc.h"
#include <stdbool.h>
#include <stdint.h>

/***************************************************************************//**

  \details  Timer 3 ISR

  \return   void

  \retval   none

*******************************************************************************/
//void TIM4_IRQHandler(void)
//{
//  /* if UIF flag is set */
//  if(TIM4->SR & TIM_SR_UIF)
//  {
////    led_on = !led_on;
//
//    if( (GPIOC->ODR & (1<<13))==0 )
//    {
//      /* Turn ON the LED of PC13 */
//
//      GPIOC->ODR |= (1<<13);
//
//
//      /* Turn OFF the LED of PC13 */
//
//    }
//    else
//    {
//      /* Turn OFF the LED of PC13 */
//    	   GPIOC->ODR &= ~(1<<13);
//    }
//
//    /* Clear the Interrupt Status */
//    TIM4->SR &= ~TIM_SR_UIF;
//  }
//}


static void delay( uint32_t ms )
{
  uint32_t i;
  for( i = 0; i <= ms; i++ )
  {
    /* Clear the count */
    TIM4->CNT = 0;

    /* Wait UIF to be set */
    while((TIM4->SR & (1<<0)) == 0);    /* This will generate 1ms delay */

    /* Reset UIF */
    TIM4->SR &= ~(1<<0);
  }
}

/***************************************************************************//**

  \details  This function enables the HSI clock as a system clock and generate
            the 16MHz. The Internal HSI Clock is 16MHz. So, we are not using PLL
            and not dividing, Multiplying. So, we will get the 16MHz as it is.

  \return   void

  \retval   none

*******************************************************************************/
static void SetSystemClockTo16Mhz(void)
{
  /* Enabling the HSI clock - If not enabled and ready */
  if( (RCC->CR & (1<<1)) == 0)
  {
    RCC->CR |= (1<<0);  /* HSION=1 */

    /* Waiting until HSI clock is ready */
    while( (RCC->CR & (1<<1)) == 0);
  }

  /* Select AHB prescaler to 1 */
  RCC->CFGR &= ~(15<<4);

  /* APB1 prescaler to 1 */
  RCC->CFGR &= ~(7<<10);

  /* APB2 prescaler to 1 */
  RCC->CFGR &= ~(7<<13);

  /* Select the HSI as system clock source */
  RCC->CFGR &= ~(3<<0);



}

/***************************************************************************//**

  \details  This function configures the timer 3 to generate the 1ms delay.

  \return   void

  \retval   none

*******************************************************************************/
static void ConfigureTimer3(void)
{
  /* Enable the APB clock FOR TIM4  */

  RCC->APB1ENR |= (1<<2);
  /* fCK_PSC / (PSC[15:0] + 1)
     (16 MHz / (15999+1)) = 1 KHz timer clock speed */
  /* Tried configuring the prescaler clock with 1MHz not working so switching with 1kHZ clock frequency*/
  TIM4->PSC  = 15999;

  /* (1 KHz / 1000) = 1Hz = 1s */
  /* So, this will generate the 1s delay */
  TIM4->ARR = 999;

  /* Finally enable TIM4 module */
  TIM4->CR1 = (1<<0);
}

/***************************************************************************//**

  \details  The main function.  It should not return.

  \return   void

  \retval   none

*******************************************************************************/
int main(void)
{

  /* Set System clock to 16 MHz using HSI */
  SetSystemClockTo16Mhz();

  /* Configure the Timer 3 */
  ConfigureTimer3();

  /* Enable the AHB clock all GPIO port C */
  RCC->AHB1ENR |= (1<<2);
  /* set all Port C as output */
  GPIOC->MODER |= (1<<26);

  /* Endless loop */
  while(1)
  {
	    if( (GPIOC->ODR & (1<<13))==0 )
	    {
	      /* Turn ON the LED of PC13 */

	      GPIOC->ODR |= (1<<13);

	      /* Turn OFF the LED of PC13 */
	    }
	    else
	    {
	      /* Turn OFF the LED of PC13 */
	    	   GPIOC->ODR &= ~(1<<13);
	    }
	    delay(1);
  }
}
/* Reference: https://embetronicx.com/tutorials/microcontrollers/stm32/simple-stm32-timer-tutorial-bare-metal-with-registers/ */

/* 						NOTE
 *
 * Here the Controller wants to continously check the UIF bit is HIGH or not
 *
 * That can be solved using TImer internal interrupt
 *
 * when the UIF is pulled HIGH the function will be executed until COntroller will be in ideal stage
 *
 * */
