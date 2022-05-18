# Digest from Chapter_06_nucleo_l452rep_freeRTOS_three_led_blink.map



## memory pool for task's stack space

The memory pool used for FreeRTOS kernel to allocate RAM space for task's stack space. 

>  .bss.ucHeap    0x0000000020000de8      0xbb8 ./packs/FreeRTOS/portable/MemMang/heap_4.o


The size is defined by configTOTAL_HEAP_SIZE given in FreeRTOSConfig.h,  in this specific 3000=0xbb8 .

Task1's Stack TDB
Task2's Stack TDB
Task3's Stack TDB


## DefaultTask's Stack Space
DefaultTask's Stack TDB

## Idle Task's Stack Space

Idle_Stack started at 0x0000000020000118, size 0x200 Byte, is not from ucHeap. 

## ISR Stack Space
TDB, likely 0x20028000 - small * 4

## generic global or static data 




## The pre-RTOS bare-metal heap and stack

>
._user_heap_stack
                0x0000000020001f90      0x600 load address 0x0000000008006998
                0x0000000020001f90                . = ALIGN (0x8)
                [!provide]                        PROVIDE (end = .)
                0x0000000020001f90                PROVIDE (_end = .)
                0x0000000020002190                . = (. + _Min_Heap_Size)
 *fill*         0x0000000020001f90      0x200 
                0x0000000020002590                . = (. + _Min_Stack_Size)
 *fill*         0x0000000020002190      0x400 
                0x0000000020002590                . = ALIGN (0x8)


The built-in RAM on STM32L452xx is ranging from 0x20000000 to 0x20020000 (exclude) , total 128 KByte .
RAM2 ranging from 0x10000000 to 0x10008000 (exclude) , total 32 KByte. This memory is also mapped at address 0x20020000, offering a contiguous address.

refer stm32l452re.pdf