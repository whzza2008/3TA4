/**
  ******************************************************************************
  * @file    Lab2/stm32f4xx_it.c
  * @author Rert Li
  * @version 
  * @date    August 2014
  * @brief   
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "main.h"

/** @addtogroup Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

extern __IO uint8_t UBPressed;
extern __O uint16_t factor;
__O uint16_t weop=0;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}


/******************************************************************************/
/*            STM32F4xx Peripherals Interrupt Handlers                        */
/******************************************************************************/

/**
  * @brief  This function handles TIM2 global interrupt request.
  * @param  None
  * @retval None
  */
void TIM2_IRQHandler(void)
{
	
  if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET)
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);

    /* LED4 toggling with frequency = 4.57 Hz */
    
    /* this if loop determines whether one LED or both of them blinks */
		if(factor == 0)
		{
		STM_EVAL_LEDOn(LED3);
		STM_EVAL_LEDToggle(LED4);
		}
		else
		{
			STM_EVAL_LEDOff(LED4);STM_EVAL_LEDOff(LED3);
			weop = (weop+1)%4;
			if(weop == 2){STM_EVAL_LEDToggle(LED3);}
			else if(weop == 3){STM_EVAL_LEDOff(LED4);STM_EVAL_LEDOff(LED3);}
			else if(weop == 0){STM_EVAL_LEDToggle(LED4);}
			else {STM_EVAL_LEDOff(LED4);STM_EVAL_LEDOff(LED3);}
			/*if(weop == 0){STM_EVAL_LEDOn(LED3);}
			else if (weop ==1){STM_EVAL_LEDOff(LED4);}
			else if (weop ==2){STM_EVAL_LEDOn(LED4);}
			else {STM_EVAL_LEDOff(LED3); weop =0;}*/
			
		
		
		
		}
		TIM_SetCounter(TIM2, 0x0000);
  }
}

 

void EXTI0_IRQHandler(void){
	/* add user-button handling code here */

	/* don't execute the ISR until the button is released */
//	while (STM_EVAL_PBGetState(BUTTON_USER) == Bit_SET);
	
	UBPressed = 1;
	
	EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
}




/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f429_439xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/


/**
  * @}
  */ 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
