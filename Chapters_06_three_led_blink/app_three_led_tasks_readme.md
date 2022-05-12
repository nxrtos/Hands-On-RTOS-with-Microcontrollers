# three_led_blink_tasks

This demo project presents three tasks running in parallel, each to drive a led blinking. 

In conceptual there are 3 leads, named green blue and red for each. They are blinking on each different time interval. 

The three tasks are created by invoke `xTaskCreate(...)` FreeRTOS API.  For each task created through  `xTaskCreate(...)` , a chunk of RAM space was allocated fro FreeRTOS heap for task's stack space, exclusive owned by the task along the life cycle.

Some assisted codes in the program help to identify these task's stack space.



## FreeRTOS Package 

extra tweaks had done on FreeRTOS configuration as the shared FreeRTOS Package upgraded to version 10.3.1, which higher then generated code. 

