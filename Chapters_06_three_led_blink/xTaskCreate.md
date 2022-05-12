# [xTaskCreate](https://www.freertos.org/a00125.html)

[[Task Creation](https://www.freertos.org/a00019.html)] 

task. h 

```c
 BaseType_t xTaskCreate(    TaskFunction_t pvTaskCode,                            
                            const char * const pcName,
                            configSTACK_DEPTH_TYPE usStackDepth, 
                            void *pvParameters,                            
                            UBaseType_t uxPriority,   
                            TaskHandle_t *pxCreatedTask
                       );
```

Create a new [task](https://www.freertos.org/a00015.html) and add it to the list of tasks that are ready to run. [configSUPPORT_DYNAMIC_ALLOCATION](https://www.freertos.org/a00110.html#configSUPPORT_DYNAMIC_ALLOCATION) must be set to 1 in FreeRTOSConfig.h, or left undefined (in which case it will default to 1), for this RTOS API function to be available.

Each task requires RAM that is used to hold the task state, and used by the task as its stack.  If a task is created using `xTaskCreate()` then the required RAM is automatically allocated from the [FreeRTOS heap](https://www.freertos.org/a00111.html).  If a task is created using [xTaskCreateStatic()](https://www.freertos.org/xTaskCreateStatic.html) then the RAM is provided by the application writer, so it can be statically allocated at compile time.  See the [Static Vs Dynamic allocation](https://www.freertos.org/Static_Vs_Dynamic_Memory_Allocation.html) page for more information.

If you are using [FreeRTOS-MPU](https://www.freertos.org/FreeRTOS-MPU-memory-protection-unit.html) then we recommend that you use [xTaskCreateRestricted()](https://www.freertos.org/xTaskCreateRestricted.html) instead of `xTaskCreate()`.

| Parameters:     |                                                              |
| --------------- | ------------------------------------------------------------ |
| pvTaskCode      | Pointer to the task entry function (just the name of the function that implements the task, see the example below). <br/>Tasks are normally implemented as an infinite loop; the function which implements the task must never attempt to return or exit.  Tasks can, however, delete themselves. |
| *pcName*        | A descriptive name for the task. This is mainly used to facilitate 		debugging, but can also be used to obtain a task handle. <br/>The maximum length of a task's name is defined by configMAX_TASK_NAME_LEN in FreeRTOSConfig.h. |
| *usStackDepth*  | The number of words (not bytes!) [to allocate](https://www.freertos.org/a00111.html) for use as the task's stack. For example, if the stack is 16-bits wide and usStackDepth is 100, then 200 bytes will be allocated for use as the task's stack.  <br/>As another example, if the stack is 32-bits wide and usStackDepth is 400 then 1600 bytes will be allocated for use as the task's stack. <br/>The stack depth multiplied by the stack width must not exceed the maximum value that can be contained in a variable of type `size_t`.<br/>See the FAQ [How big should the stack be?](https://www.freertos.org/FAQMem.html#StackSize) |
| *pvParameters*  | A value that is passed as the parameter to the created task. <br/>If `pvParameters` is set to the address of a variable then the variable must still exist when the created task executes - so it is not valid to pass the address of a stack variable. |
| *uxPriority*    | The [priority](https://www.freertos.org/RTOS-task-priority.html) at which the created task will execute.<br/>Systems that include MPU support can optionally create a task in a privileged (system) mode by setting the bit `portPRIVILEGE_BIT` in `uxPriority`. For example, to create a privileged task at priority 2 set  `uxPriority` to (2 | `portPRIVILEGE_BIT` ). <br />Priorities are asserted to be less than `configMAX_PRIORITIES`. If `configASSERT` is undefined, priorities are silently capped at (`configMAX_PRIORITIES` - 1). |
| *pxCreatedTask* | Used to pass a handle to the created task out of the `xTaskCreate()`function.  `pxCreatedTask` is optional and can be set to NULL. |

 

| **Returns:** |                                                              |
| ------------ | ------------------------------------------------------------ |
|              | If the task was created successfully then `pdPASS` is returned.  <br />Otherwise `errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY` is returned. |

**Example usage:**

```C
/* Task to be created. */
void vTaskCode( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
    pvParameters value in the call to xTaskCreate() below. 
    configASSERT( ( ( uint32_t ) pvParameters ) == 1 );

    for( ;; )
    {
        /* Task code goes here. */
    }
}

/* Function that creates a task. */
void vOtherFunction( void )
{
BaseType_t xReturned;
TaskHandle_t xHandle = NULL;

    /* Create the task, storing the handle. */
    xReturned = xTaskCreate(
                    vTaskCode,       /* Function that implements the task. */
                    "NAME",          /* Text name for the task. */
                    STACK_SIZE,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    tskIDLE_PRIORITY,/* Priority at which the task is created. */
                    &xHandle );      /* Used to pass out the created task's handle. */

    if( xReturned == pdPASS )
    {
        /* The task was created.  Use the task's handle to delete the task. */
        vTaskDelete( xHandle );
    }
}
```

