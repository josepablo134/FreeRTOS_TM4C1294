#include <stdint.h>
#include <stdbool.h>

#include "Board/Board.h"

// FreeRTOS includes
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


// Demo Task declarations
void demoTask1( void *pvArg);
void demoTask2( void *pvArg);

// Main function
int main(void)
{
    Board_init();
    // Create demo tasks
    xTaskCreate(demoTask1, (const portCHAR *)"Task 1",
                configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    xTaskCreate(demoTask2, (const portCHAR *)"Task 2",
                configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();
    // Code should never reach this point
    return 0;
}

void demoTask1(void *pvParameters)
{
    for (;;)
    {
        vTaskDelay(100);
    }
}

void demoTask2(void *pvParameters)
{
    for (;;)
    {
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
