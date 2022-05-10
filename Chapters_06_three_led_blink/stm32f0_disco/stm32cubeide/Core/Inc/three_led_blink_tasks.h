/**
  ******************************************************************************
  * @file           : three_led_blink_tasks.h
  * @brief          :
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

#ifndef THREE_LED_BLINK_TASKS_H
#define THREE_LED_BLINK_TASKS_H

#include "bsp.h"
#include "cmsis_os.h"

//#include <SEGGER_SYSVIEW.h>
#define  SEGGER_SYSVIEW_PrintfHost

#define  BlinkTask1StackSize  128
#define  BlinkTask2StackSize  128
#define  BlinkTask3StackSize  128

void Task1(void *argument);
void Task2( void* argument);
void Task3( void* argument);
void lookBusy( void );

#endif
