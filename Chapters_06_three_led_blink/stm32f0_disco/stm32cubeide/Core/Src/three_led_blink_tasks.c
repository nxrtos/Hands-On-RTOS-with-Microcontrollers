/**
  ******************************************************************************
  * @file           : three_led_blink_tasks.c
  * @brief          :
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#include "three_led_blink_tasks.h"

//#include <SEGGER_SYSVIEW.h>
#define  SEGGER_SYSVIEW_PrintfHost

void Task1(void *argument)
{
  BSP_LED_Init(LED_GREEN);
  while(1)
  {
//	SEGGER_SYSVIEW_PrintfHost("hey there!\n");
	BSP_LED_Toggle(LED_GREEN);
	//HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
	//GreenLed.On();
	vTaskDelay(105/ portTICK_PERIOD_MS);
	BSP_LED_Toggle(LED_GREEN);
	//HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
	//GreenLed.Off();
	vTaskDelay(100/ portTICK_PERIOD_MS);
  }
}
void Task2( void* argument )
{
  BSP_LED_Init(LED_BLUE);
  while(1)
  {
	SEGGER_SYSVIEW_PrintfHost("task 2 says 'Hi!'\n");
	BSP_LED_Toggle(LED_BLUE);
	//HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	//BlueLed.On();
	vTaskDelay(200 / portTICK_PERIOD_MS);
	BSP_LED_Toggle(LED_BLUE);
	//HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	//BlueLed.Off();
	vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

void Task3( void* argument )
{
  BSP_LED_Init(LED_BLUE);
  while(1)
  {
	lookBusy();

	SEGGER_SYSVIEW_PrintfHost("task3\n");
	BSP_LED_Toggle(LED_RED);
	//HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
	//RedLed.On();
	vTaskDelay(500/ portTICK_PERIOD_MS);
	BSP_LED_Toggle(LED_RED);
	//HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	//RedLed.Off();
	vTaskDelay(500/ portTICK_PERIOD_MS);
  }
}

void lookBusy( void )
{
  volatile uint32_t __attribute__((unused)) dontCare = 0;
  for(int i = 0; i < 50E3; i++)
  {
	dontCare = i % 4;
  }
  SEGGER_SYSVIEW_PrintfHost("looking busy\n");
}
