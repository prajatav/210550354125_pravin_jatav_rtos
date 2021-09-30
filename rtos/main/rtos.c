#include<stdio.h>
#include "freetos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos/task.h"
void *const timer_id;
TimerHandle_t timer_handle;
void tone_task(void *data)
{
    while(1)
    {
        printf(" task1 started \n");
        //...............//
        printf(" task1 ended \n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);

    }
}

void ttwo_task(void *data)
{
    while(1)
    {
        printf(" task2 started \n");
        //...............//
        printf(" task2 ended \n");
        vTaskDelay(2000/ portTICK_PERIOD_MS);

    }
}

void tthree_task(void *data)
{
    while(1)
    {
        printf(" task3 started \n");
        //...............//
        printf(" task3 ended \n");
        vTaskDelay(5000/ portTICK_PERIOD_MS);

    }

void task3(void *params)
{
    timer_handle = xTimerCreate("timer",(10000 / portTICK_PERIOD_MS),pdFALSE,timer_id, callback);

    xTimerStart(my_timer_handle, 1);
    while (1)
    {
        printf("task3\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
void callback(TimerHandle_t xTimer)
{
    printf("Callback\n");
}
