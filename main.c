#include <stdint.h>
#include <stdbool.h>

#include "Board/Board.h"

#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


void demoTask1( void *pvArg);
void demoTask2( void *pvArg);

int main(void)
{
    Board_init();
    xTaskCreate(demoTask1, (const portCHAR *)"Demo Task 1",
                configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    xTaskCreate(demoTask2, (const portCHAR *)"Demo Task 2",
                configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();
    return 0;
}

void demoTask1(void *pvArg)
{
    for (;;)
    {
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void demoTask2(void *pvArg)
{
    for (;;)
    {
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
}
