# Digest from Chapter_06_nucleo_f767zi_freeRTOS_three_led_blink.map



## memory pool for task's stack space

The memory pool used for FreeRTOS kernel to allocate RAM space for task's stack space. 

> 
.bss.ucHeap    0x0000000020001244     0x3c00 ./packs/FreeRTOS/portable/MemMang/heap_4.o


The size is defined by configTOTAL_HEAP_SIZE given in FreeRTOSConfig.h,  in this specific 15360=0x3c00 .

Task1's Stack TDB
Task2's Stack TDB
Task3's Stack TDB

## DefaultTask's Stack Space
DefaultTask's Stack TDB

## Idle Task's Stack Space

Idle_Stack started at 0x20000574 , size 0x200 Byte, up to 0x20000774, is not from ucHeap. 
Idle_Task Stack Point caught TDB

## ISR Stack Space
TDB
Likely to 
## generic global or static data 




## The pre-RTOS bare-metal heap and stack

>
._user_heap_stack
                0x0000000020005434      0x604 load address 0x0000000008007e94
                0x0000000020005438                . = ALIGN (0x8)
 *fill*         0x0000000020005434        0x4 
                [!provide]                        PROVIDE (end = .)
                0x0000000020005438                PROVIDE (_end = .)
                0x0000000020005638                . = (. + _Min_Heap_Size)
 *fill*         0x0000000020005438      0x200 
                0x0000000020005a38                . = (. + _Min_Stack_Size)
 *fill*         0x0000000020005638      0x400 
                0x0000000020005a38                . = ALIGN (0x8)


The built-in RAM on STM32F767ZITx is ranging from 0x20000000 to 0x20080000 (exclude) , total 512 KByte .

>                0x0000000020080000                _estack 

refer to stm32f767zi.pdf for datasheet.
>
System SRAM up to 512 Kbytes:
– SRAM1 on AHB bus Matrix: 368 Kbytes
– SRAM2 on AHB bus Matrix: 16 Kbytes
– DTCM-RAM on TCM interface (Tighly Coupled Memory interface): 128 Kbytes for critical real-time data

>
Instruction RAM (ITCM-RAM) 16 Kbytes:
– It is mapped on TCM interface and reserved only for CPU Execution/Instruction
useful for critical real-time routines
