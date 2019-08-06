// 
// 
// 

#include "Controller.h"
#include "Tasks.h"

void ControllerClass::init()
{

	Setup_Physical_Input();		// initialize physical buttons and knobs.
	Setup_UDP_Input();			// initialize UDP Input ports.

	Create_Tasks();				// Start all the independently managed tasks.

	Create_Fixture();

	FastLED_Show_ESP32();

	//Debug.Display_Memory(" after controller initialization.");

}

void ControllerClass::run()
{
}


ControllerClass Controller;

