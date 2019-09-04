// Tasks.h

// This file is used to define any functions that run based on tasks.

#ifndef _TASKS_h
#define _TASKS_h

#include "arduino.h"
#include <FastLED.h>
#include "Bug.h"

/** show() for ESP32
Call this function instead of FastLED.show(). It signals core 0 to issue a show,
then waits for a notification that it is done.
*/
void FastLED_Show_ESP32();

/** show Task
This function runs on core 0 and just waits for requests to call FastLED.show()
*/
void FastLED_Show_Task(void* pvParameters);

void create_tasks();


#endif

