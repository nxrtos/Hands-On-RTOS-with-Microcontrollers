# Digest from Chapter_06_nucleo_f722ze_freeRTOS_three_led_blink.map



## memory pool for task's stack space

The memory pool used for FreeRTOS kernel to allocate RAM space for task's stack space. 

> .bss.ucHeap    0x0000000020000d60      0xc00 ./packs/FreeRTOS/portable/MemMang/heap_4.o

The size is defined by configTOTAL_HEAP_SIZE given in FreeRTOSConfig.h,  in this specific 3072=0xc00 .

Task1's Stack caught at 0x20001658, ucHeap+1124, started at  0x20001668 = 0x20001658 + 0x10, back to  0x20001668 - 0x200 = 0x20001468 , total size 0x80 * 4 Bytes .  Space 0x20001668 to 0x200016d8, size up to  0x70, seems used for Task1's TCB. 

Task2's Stack caught at 0x20001908, ucHeap+1812, started at  0x20001918 = 0x20001908 + 0x10, back to 0x20001918 - 0x240 = 0x200016d8.  total size 0x240 = 0x90 * 4 Bytes. Space 0x20001918 to 0x20001988, size up to  0x70, seems used for Task2's TCB. 

Task3's Stack caught at 0x20001bf8, ucHeap+2564, started at 0x20001c08 = 0x20001bf8 + 0x10, back to  0x20001c08 - 0x280 = 0x20001988. total size 0x280 = 0xA0 * 4 Bytes. Space 0x20001988 to 0x200019f8, size up to  0x70, seems used for Task3's TCB. 


## DefaultTask's Stack Space
DefaultTask's Stack caught at 0x200013e8, ucHeap+500 , started at  0x200013f4 = 0x200013e8 + 0x0c, back up to ucHeap (0x200011f4) , total size 0x80 * 4 Bytes. Space 0x200013f4 to 0x20001464, size up to  0x70, seems used for DefaultTask's TCB. 

## Idle Task's Stack Space

Idle_Stack started at 0x20000524, size 0x200 Byte, up to 0x20000724, is not from ucHeap. 
Idle_Task Stack Point caught at 0x20000700, within 0x20000724 down to 0x20000524. 

## ISR Stack Space
msp has been set to 0x20040000, and updated to 0x2003fff8 when entered main(), and evolved to 0x20017fe0 while osKernelStart();
It falls into bare metal pre-rtos stack region. 
Because osKernelStart(); will not to return to mail(), as so the initial ISR_Stack_Point can be reset to 0x20018000 to preserve maximum RAM space.

## generic global or static data 




## The pre-RTOS bare-metal heap and stack

>
._user_heap_stack
                0x0000000020004e18      0x600 load address 0x0000000008006320
                0x0000000020004e18                . = ALIGN (0x8)
                [!provide]                        PROVIDE (end = .)
                0x0000000020004e18                PROVIDE (_end = .)
                0x0000000020005018                . = (. + _Min_Heap_Size)
 *fill*         0x0000000020004e18      0x200 
                0x0000000020005418                . = (. + _Min_Stack_Size)
 *fill*         0x0000000020005018      0x400 
                0x0000000020005418                . = ALIGN (0x8)



The built-in RAM on STM32F722ZETx is ranging from 0x20000000 to 0x20040000 (exclude) , total 256 KByte .

refer to stm32f722ic.pdf for datasheet.
>
System SRAM up to 256 Kbytes:
– SRAM1 on AHB bus Matrix: 176 Kbytes
– SRAM2 on AHB bus Matrix: 16 Kbytes
– DTCM-RAM on TCM interface: 64 Kbytes for critical real-time data
