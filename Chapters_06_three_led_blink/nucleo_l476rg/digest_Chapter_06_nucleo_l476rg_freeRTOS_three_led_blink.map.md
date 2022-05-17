# Digest from Chapter_06_nucleo_l476rg_freeRTOS_three_led_blink.map



## memory pool for task's stack space

The memory pool used for FreeRTOS kernel to allocate RAM space for task's stack space. 

> .bss.ucHeap    0x0000000020000d60      0xc00 ./packs/FreeRTOS/portable/MemMang/heap_4.o

The size is defined by configTOTAL_HEAP_SIZE given in FreeRTOSConfig.h,  in this specific 3072=0xc00 .

Task1's Stack caught at 0x20001248 , ucHeap+1120, started at  0x20001258 = 0x20001248 + 0x10, back to  0x20001258 - 0x200 = 0x20001058 , total size 0x80 * 4 Bytes .  Space 0x20001258 to 0x200012c8, size up to  0x70, seems used for Task1's TCB. 

Task2's Stack caught at 0x200014f8, ucHeap+1808, started at  0x20001508 = 0x200014f8 + 0x10, back to 0x20001508 - 0x240 = 0x200012c8.  total size 0x240 = 0x90 * 4 Bytes. Space 0x20001508 to 0x20001578, size up to  0x70, seems used for Task2's TCB. 

Task3's Stack caught at 0x200017e8, ucHeap+2560, started at 0x200017f8 = 0x200017e8+ 0x10, back to  0x200017f8 - 0x280 = 0x20001578. total size 0x280 = 0xA0 * 4 Bytes. Space 0x200017f8 to 0x20001868, size up to  0x70, seems used for Task3's TCB. 


## DefaultTask's Stack Space
DefaultTask's Stack caught at 0x20000fd8, ucHeap+496 , started at  0x20000fe8 = 0x20000fd8 + 0x10, back up to ucHeap (0x20000de8) , total size 0x80 * 4 Bytes. Space 0x20000fe8 to 0x20001058, size up to  0x70, seems used for DefaultTask's TCB. 

## Idle Task's Stack Space

Idle_Stack started at 0x0000000020000118, size 0x200 Byte, is not from ucHeap. 

## ISR Stack Space
msp has been set to 0x20018000, and updated to 0x20017ff8 when entered main(), and evolved to 0x20017fe0 while osKernelStart();
It falls into bare metal pre-rtos stack region. 
Because osKernelStart(); will not to return to mail(), as so the initial ISR_Stack_Point can be reset to 0x20018000 to preserve maximum RAM space.

## generic global or static data 




## The pre-RTOS bare-metal heap and stack

>
._user_heap_stack
                0x00000000200019c4      0x604 load address 0x0000000008005d58
                0x00000000200019c8                . = ALIGN (0x8)
 *fill*         0x00000000200019c4        0x4 
                [!provide]                        PROVIDE (end = .)
                0x00000000200019c8                PROVIDE (_end = .)
                0x0000000020001bc8                . = (. + _Min_Heap_Size)
 *fill*         0x00000000200019c8      0x200 
                0x0000000020001fc8                . = (. + _Min_Stack_Size)
 *fill*         0x0000000020001bc8      0x400 
                0x0000000020001fc8                . = ALIGN (0x8)

The built-in RAM on STM32L476RGTx is ranging from 0x20000000 to 0x20018000 (exclude) , total 96 KByte .
RAM2 ranging from 0x10000000 to 0x10008000 (exclude) , total 32 KByte. (currently didn't use)