/**
  ******************************************************************************
  * @file           : three_led_blink_tasks.c
  * @brief          :
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#include "three_led_blink_tasks_on_freertos.h"

//#include <SEGGER_SYSVIEW.h>
#define  SEGGER_SYSVIEW_PrintfHost

void Task1(void *argument)
{
  int  local_array[10];

  SEGGER_SYSVIEW_PrintfHost("local location %d\n", local_array);
  SEGGER_SYSVIEW_PrintfHost("local location %d\n", &local_array[9]);

  BSP_LED_Init(LED_GREEN);
  BSP_LED_Off(LED_GREEN);
  while(1)
  {
	SEGGER_SYSVIEW_PrintfHost("hey there!\n");
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
  int  local_array[10];

  SEGGER_SYSVIEW_PrintfHost("local location %d\n", local_array);
  SEGGER_SYSVIEW_PrintfHost("local location %d\n", &local_array[9]);

  BSP_LED_Init(LED_BLUE);
  BSP_LED_Off(LED_BLUE);
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
  int  local_array[10];

  SEGGER_SYSVIEW_PrintfHost("local location %d\n", local_array);
  SEGGER_SYSVIEW_PrintfHost("local location %d\n", &local_array[9]);

  BSP_LED_Init(LED_RED);
  BSP_LED_Off(LED_RED);
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

void lookBusy(void)
{
  volatile uint32_t __attribute__((unused)) dontCare = 0;
  for(int i = 0; i < 50E3; i++)
  {
	dontCare = i % 4;
  }
  SEGGER_SYSVIEW_PrintfHost("looking busy\n");
}

void start_three_led_blink_tasks(void)
{
  if (xTaskCreate(Task1, "task1", BlinkTask1StackSize, NULL, tskIDLE_PRIORITY + 2, NULL) != pdPASS)
  {
	while(1);
  }
  if (xTaskCreate(Task2, "task2", BlinkTask2StackSize, NULL, tskIDLE_PRIORITY + 1, NULL) != pdPASS)
  {
	while(1);
  }
  if (xTaskCreate(Task3, "task3", BlinkTask3StackSize, NULL, tskIDLE_PRIORITY + 1, NULL) != pdPASS)
  {
	while(1);
  }
}
