// 
// 
// 

#include "Tasks.h"

#define FASTLED_SHOW_CORE 0

// -- Task handles for use in the notifications
static TaskHandle_t FastLED_Show_Task_Handle = 0;
static TaskHandle_t user_Task_Handle = 0;

/** show() for ESP32
Call this function instead of FastLED.show(). It signals core 0 to issue a show,
then waits for a notification that it is done.
*/
void FastLED_Show_ESP32()
{
	START;

	yield();

	if (user_Task_Handle == 0) {

		yield();
		THING;
		// -- Store the handle of the current task, so that the show task can
		//    notify it when it's done
		user_Task_Handle = xTaskGetCurrentTaskHandle();

		yield();
		THING;

		// -- Trigger the show task
		xTaskNotifyGive(FastLED_Show_Task_Handle);

		yield();
		THING;

		// -- Wait to be notified that it's done
		const TickType_t xMaxBlockTime = pdMS_TO_TICKS(200);
		ulTaskNotifyTake(pdTRUE, xMaxBlockTime);
		user_Task_Handle = 0;

		yield();
		THING;
	}

	END;
}

/** show Task
This function runs on core 0 and just waits for requests to call FastLED.show()
*/
void FastLED_Show_Task(void* pvParameters)
{
	// -- run forever...
	for (;;) {

		// -- Wait for the trigger
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		// -- Do the show (synchronously)
		FastLED.show();

		// -- Notify the calling task
		xTaskNotifyGive(user_Task_Handle);

	}
}

void create_tasks()
{
	START;

	// Print the core the main code is running on.
	// Make sure to change FASTLED_SHOW_CORE if it is the same as this one.
	int core = xPortGetCoreID();
	Serial.print("Main code running on core ");
	Serial.println(core);

	// -- Create the FastLED show task
	xTaskCreatePinnedToCore(FastLED_Show_Task, "FastLED_Show_Task", 2048, NULL, 2, &FastLED_Show_Task_Handle, FASTLED_SHOW_CORE);

	END;
}