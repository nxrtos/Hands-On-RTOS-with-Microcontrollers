# Chapters06_stm32f0_disco_freeRTOS_three_led_blink_tasks



## Chapter\_06\_stm32f0\_disco\_freeRTOS\_three\_led\_blink.ioc

project derived from Chapters05_06_stm32f0_disco_freeRTOS, by separating led_blink tasks to dedicated file from main.c

three\_led\_blink\_tasks.h/c are created.

## FreeRTOS Package 

extra tweaks had done on FreeRTOS configuration as the shared FreeRTOS Package upgraded to version 10.3.1, which higher then generated code. 

## SEGGER Package

SEGGER Package is disabled as the SEGGER_SYSVIEW takes too much RAM exceeded STM32F051 supplied. 

Maybe a good tweak in SEGGER_SYSVIEW_Conf.h can fix it.

## LED remap

The project has green led, blue led and red led in playing. As there are only green led and blue led built in board, LED_RED has remapped to LED_GREEN in bsp.h for quick make up. 

## More Hardware Information

More hardware information can be find for [**STM32F0 Discovery**](https://www.st.com/en/evaluation-tools/stm32f0discovery.html) board.
