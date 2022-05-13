/**
  ******************************************************************************
  * @file           : three_led_blink_tasks.h
  * @brief          :
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef THREE_LED_BLINK_TASKS_ON_FREERTOS_H
#define THREE_LED_BLINK_TASKS_ON_FREERTOS_H

#include "bsp.h"
#include "cmsis_os.h"

//#include <SEGGER_SYSVIEW.h>
#define  SEGGER_SYSVIEW_PrintfHost

#define  BlinkTask1StackSize  0x80
#define  BlinkTask2StackSize  0x90
#define  BlinkTask3StackSize  0xA0

void Task1(void *argument);
void Task2( void* argument);
void Task3( void* argument);
void lookBusy( void );
void start_three_led_blink_tasks(void);

#endif
