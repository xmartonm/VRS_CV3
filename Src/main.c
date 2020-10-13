/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "assignment.h"


int main(void)
{
  //Systick init
  LL_Init1msTick(8000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(8000000);	


  /* Enable clock for GPIO port A*/
  RCC_AHBENR_REG |= (uint32_t)(1 << 17);

  /* GPIOA pin 3 and 4 setup */

  //PIN3 - button - input
  *GPIOA_MODER_REG &= ~(uint32_t)(0x3 << 6); 	//NASTAVIME INPUT
  *GPIOA_PUPDR_REG |= (1 << 6);					//NASTAVIME PULLUP

  //PIN4 - led - output
  *GPIOA_MODER_REG &= ~(uint32_t)(0x3 << 8);	//NASTAVIME OUTPUT
  *GPIOA_MODER_REG |= (uint32_t)(1 << 8);     	//NASTAVIME OUTPUT
  *GPIOA_OTYPER_REG &= ~(1 << 4);				//NASTAVIME OUTPUT PUSH-PULL
  *GPIOA_OSPEEDER_REG &= ~(0x3 << 8);			//NASTAVIME LOW SPEED
  *GPIOA_PUPDR_REG &= ~(0x3 << 8); 				//NASTAVIME NO-PULLUP NO-PULLDOWN

  EDGE_TYPE type = NONE;

  int tmp = 0;

  while (1)
  {

	  type = edgeDetect(BUTTON_GET_STATE, 5);

	  if(type == RISE){
		  if(tmp == 1){
			  tmp = 0;
		  }else
		  {
			  tmp = 1;
		  }

	  }

//	  if(type == RISE)tmp = 1;
//	  if(type == FALL)tmp = 0;

	  if(tmp == 1){
		  LED_ON;
	  }else{
		  LED_OFF;
	  }

	//  LL_mDelay(100);
  }

}

uint8_t old_state = 0;
int rise_active = 0;
int poc_rise = 0;

int fall_active = 0;
int poc_fall = 0;

EDGE_TYPE edgeDetect(uint8_t state, uint8_t samples) {

	if(!old_state && state)rise_active = 1;
	if(state && rise_active ==1)poc_rise++;
	if(poc_rise >= samples){   // ==???
		poc_rise = 0;
		rise_active = 0;
		old_state = state;
		return RISE;
	}

	if(old_state && !state)fall_active = 1;
	if(!state && fall_active ==1)poc_fall++;
	if(poc_fall >= samples){
		poc_fall = 0;
		fall_active = 0;
		old_state = state;
		return FALL;
	}

	if((!state && rise_active ==1) || (state && fall_active ==1)){
		poc_rise = 0;
		rise_active = 0;
		poc_fall = 0;
	    fall_active = 0;
		old_state = state;
		return NONE;
	}

	old_state = state;
	return NONE;
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
