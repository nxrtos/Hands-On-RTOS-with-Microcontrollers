# Digest from Chapter_06_stm32f0_disco_freeRTOS_three_led_blink.map



## memory pool for task's stack space

The memory pool used for FreeRTOS kernel to allocate RAM space for task's stack space. 

> .bss.ucHeap    0x0000000020000d60      0xc00 ./packs/FreeRTOS/portable/MemMang/heap_4.o

The size is defined by configTOTAL_HEAP_SIZE given in FreeRTOSConfig.h,  in this specific 3072=0xc00 .

DefaultTask's Stack caught at 0x20000f50, ucHeap+496 , started at  0x20000f60 = 0x20000f50 + 0x10, back up to ucHeap (0x20000d60) , total size 0x80 * 4 Bytes. Space 0x20000f60 to 0x20000Fd0, size up to  0x70, seems used for DefaultTask's TCB. 

Task1's Stack caught at 0x200011c0, ucHeap+1120, started at  0x200011d0 = 0x200011c0 + 0x10, back to  0x200011d0 - 0x200 = 0x20000Fd0 , total size 0x80 * 4 Bytes .  Space 0x200011d0 to 0x20001240, size up to  0x70, seems used for Task1's TCB. 

Task2's Stack caught at 0x20001470, ucHeap+1808, started at  0x20001480 = 0x20001470 + 0x10, back to 0x20001480 - 0x240 = 0x20001240.  total size 0x240 = 0x90 * 4 Bytes. Space 0x20001480 to 0x200014F0, size up to  0x70, seems used for Task2's TCB. 

Task3's Stack caught at 0x20001760, ucHeap+2560, started at 0x20001770 = 0x20001760+ 0x10, back to  0x20001770 - 0x280 = 0x200014F0. total size 0x280 = 0xA0 * 4 Bytes. Space 0x20001770 to 0x200017E0, size up to  0x70, seems used for Task3's TCB. 

Idle_Stack started at 0x0000000020000098, size 0x200 Byte, is not from ucHeap. 



## generic global or static data 

> .data           0x0000000020000000       0x18 load address 0x0000000008003bf4
>                 0x0000000020000000                . = ALIGN (0x4)
>                 0x0000000020000000                _sdata = .
>  *(.data)
>  *(.data*)
>  .data.SystemCoreClock
>                 0x0000000020000000        0x4 ./Core/Src/system_stm32f0xx.o
>                 0x0000000020000000                SystemCoreClock
>  .data.uxCriticalNesting
>                 0x0000000020000004        0x4 ./packs/FreeRTOS/portable/GCC/ARM_CM0/port.o
>  .data.LED_PORT
>                 0x0000000020000008        0x8 ./packs/STM32F051_Discovery/stm32f0_discovery.o
>                 0x0000000020000008                LED_PORT
>  .data.uwTickPrio
>                 0x0000000020000010        0x4 ./packs/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o
>                 0x0000000020000010                uwTickPrio
>  .data.uwTickFreq
>                 0x0000000020000014        0x1 ./packs/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o
>                 0x0000000020000014                uwTickFreq
>  *(.RamFunc)
>  *(.RamFunc*)
>                 0x0000000020000018                . = ALIGN (0x4)
>  *fill*         0x0000000020000015        0x3 
>                 0x0000000020000018                _edata = .
>
> .igot.plt       0x0000000020000018        0x0 load address 0x0000000008003c0c
>  .igot.plt      0x0000000020000018        0x0 stm32cubeide_1.5.0/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.10.3-2021.10.linux64_1.0.0.202111181127/tools/bin/../lib/gcc/arm-none-eabi/10.3.1/thumb/v6-m/nofp/crtbegin.o
>                 0x0000000020000018                . = ALIGN (0x4)

and 

> .bss            0x0000000020000018     0x196c load address 0x0000000008003c0c
>                 0x0000000020000018                _sbss = .
>                 0x0000000020000018                \_\_bss_start__ = _sbss
>  *(.bss)
>  .bss           0x0000000020000018       0x1c stm32cubeide_1.5.0/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.10.3-2021.10.linux64_1.0.0.202111181127/tools/bin/../lib/gcc/arm-none-eabi/10.3.1/thumb/v6-m/nofp/crtbegin.o
>  *(.bss*)
>  .bss.defaultTaskHandle
>                 0x0000000020000034        0x4 ./Core/Src/main.o
>                 0x0000000020000034                defaultTaskHandle
>  .bss.KernelState
>                 0x0000000020000038        0x4 ./packs/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.o
>  .bss.Idle_TCB.3
>                 0x000000002000003c       0x5c ./packs/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.o
>  .bss.Idle_Stack.2
>                 0x0000000020000098      0x200 ./packs/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.o
>  .bss.Timer_TCB.1
>                 0x0000000020000298       0x5c ./packs/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.o
>  .bss.Timer_Stack.0
>                 0x00000000200002f4      0x400 ./packs/FreeRTOS/CMSIS_RTOS_V2/cmsis_os2.o
>  .bss.xQueueRegistry
>                 0x00000000200006f4       0x40 ./packs/FreeRTOS/queue.o
>                 0x00000000200006f4                xQueueRegistry
>  .bss.pxCurrentTCB
>                 0x0000000020000734        0x4 ./packs/FreeRTOS/tasks.o
>                 0x0000000020000734                pxCurrentTCB
>  .bss.pxReadyTasksLists
>                 0x0000000020000738      0x460 ./packs/FreeRTOS/tasks.o
>  .bss.xDelayedTaskList1
>                 0x0000000020000b98       0x14 ./packs/FreeRTOS/tasks.o
>  .bss.xDelayedTaskList2
>                 0x0000000020000bac       0x14 ./packs/FreeRTOS/tasks.o
>  .bss.pxDelayedTaskList
>                 0x0000000020000bc0        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.pxOverflowDelayedTaskList
>                 0x0000000020000bc4        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xPendingReadyList
>                 0x0000000020000bc8       0x14 ./packs/FreeRTOS/tasks.o
>  .bss.xTasksWaitingTermination
>                 0x0000000020000bdc       0x14 ./packs/FreeRTOS/tasks.o
>  .bss.uxDeletedTasksWaitingCleanUp
>                 0x0000000020000bf0        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xSuspendedTaskList
>                 0x0000000020000bf4       0x14 ./packs/FreeRTOS/tasks.o
>  .bss.uxCurrentNumberOfTasks
>                 0x0000000020000c08        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xTickCount
>                 0x0000000020000c0c        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.uxTopReadyPriority
>                 0x0000000020000c10        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xSchedulerRunning
>                 0x0000000020000c14        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xPendedTicks
>                 0x0000000020000c18        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xYieldPending
>                 0x0000000020000c1c        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xNumOfOverflows
>                 0x0000000020000c20        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.uxTaskNumber
>                 0x0000000020000c24        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xNextTaskUnblockTime
>                 0x0000000020000c28        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xIdleTaskHandle
>                 0x0000000020000c2c        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.uxSchedulerSuspended
>                 0x0000000020000c30        0x4 ./packs/FreeRTOS/tasks.o
>  .bss.xActiveTimerList1
>                 0x0000000020000c34       0x14 ./packs/FreeRTOS/timers.o
>  .bss.xActiveTimerList2
>                 0x0000000020000c48       0x14 ./packs/FreeRTOS/timers.o
>  .bss.pxCurrentTimerList
>                 0x0000000020000c5c        0x4 ./packs/FreeRTOS/timers.o
>  .bss.pxOverflowTimerList
>                 0x0000000020000c60        0x4 ./packs/FreeRTOS/timers.o
>  .bss.xTimerQueue
>                 0x0000000020000c64        0x4 ./packs/FreeRTOS/timers.o
>  .bss.xTimerTaskHandle
>                 0x0000000020000c68        0x4 ./packs/FreeRTOS/timers.o
>  .bss.xLastTime.2
>                 0x0000000020000c6c        0x4 ./packs/FreeRTOS/timers.o
>  .bss.ucStaticTimerQueueStorage.1
>                 0x0000000020000c70       0xa0 ./packs/FreeRTOS/timers.o
>  .bss.xStaticTimerQueue.0
>                 0x0000000020000d10       0x50 ./packs/FreeRTOS/timers.o
>  .bss.ucHeap    0x0000000020000d60      0xc00 ./packs/FreeRTOS/portable/MemMang/heap_4.o
>  .bss.xStart    0x0000000020001960        0x8 ./packs/FreeRTOS/portable/MemMang/heap_4.o
>  .bss.pxEnd     0x0000000020001968        0x4 ./packs/FreeRTOS/portable/MemMang/heap_4.o
>  .bss.xFreeBytesRemaining
>                 0x000000002000196c        0x4 ./packs/FreeRTOS/portable/MemMang/heap_4.o
>  .bss.xMinimumEverFreeBytesRemaining
>                 0x0000000020001970        0x4 ./packs/FreeRTOS/portable/MemMang/heap_4.o
>  .bss.xNumberOfSuccessfulAllocations
>                 0x0000000020001974        0x4 ./packs/FreeRTOS/portable/MemMang/heap_4.o
>  .bss.xNumberOfSuccessfulFrees
>                 0x0000000020001978        0x4 ./packs/FreeRTOS/portable/MemMang/heap_4.o
>  .bss.xBlockAllocatedBit
>                 0x000000002000197c        0x4 ./packs/FreeRTOS/portable/MemMang/heap_4.o
>  .bss.uwTick    0x0000000020001980        0x4 ./packs/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o
>                 0x0000000020001980                uwTick
>  *(COMMON)
>                 0x0000000020001984                . = ALIGN (0x4)
>                 0x0000000020001984                _ebss = .
>                 0x0000000020001984                __bss_end__ = _ebss



## The pre-RTOS bare-metal heap and stack

> ._user_heap_stack
>                 0x0000000020001984      0x604 load address 0x0000000008003c0c
>                 0x0000000020001988                . = ALIGN (0x8)
>  \*fill*         0x0000000020001984        0x4 
>                 [!provide]                        PROVIDE (end = .)
>                 0x0000000020001988                PROVIDE (_end = .)
>                 0x0000000020001b88                . = (. + _Min_Heap_Size)
>  \*fill*         0x0000000020001988      0x200 
>                 0x0000000020001f88                . = (. + _Min_Stack_Size)
>  \*fill*         0x0000000020001b88      0x400 
>                 0x0000000020001f88                . = ALIGN (0x8)

The built-in RAM on stm32f051R8 is ranging from 0x20000000 to 0x20002000 (exclude) , total 8Kbyte .
