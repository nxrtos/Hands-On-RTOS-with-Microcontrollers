# Chapters05_06_stm32f0_disco_freeRTOS



## Chapters05_06_stm32f0_disco_freeRTOS.ioc

project started from Chapters05_06_stm32f0_disco_freeRTOS.ioc, by selecting ***stmf0 discovery*** board, and enable **freertos** with CMSIS-RTOSv2 API.

Generated code from Chapters05_06_stm32f0_disco_freeRTOS.ioc, then shift the packages to consolidated location through virtual and linked folder/files. 

## FreeRTOS Package 

extra tweaks had done on FreeRTOS configuration as the shared FreeRTOS Package upgraded to version 10.3.1, which higher then generated code. 



## SEGGER Package

SEGGER Package is disabled as the SEGGER_SYSVIEW takes too much RAM exceeded STM32F051 supplied. 

Maybe a good tweak in SEGGER_SYSVIEW_Conf.h can fix it.



## LED remap

The project has green led, blue led and red led in playing. As there are only green led and blue led built in board, LED_RED has remapped to LED_GREEN in bsp.h for quick make up. 



## More Hardware Information

More hardware information can be find for [**STM32F0 Discovery**](https://www.st.com/en/evaluation-tools/stm32f0discovery.html) board.
