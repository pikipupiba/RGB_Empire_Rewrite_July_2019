// 
// 
// 

#include "Controller.h"
#include "Tasks.h"

void Controller::create_fixture()
{

}

Controller::Controller()
{

	setup_physical_input();		// initialize physical buttons and knobs.
	setup_UDP_input();			// initialize UDP Input ports.

	create_tasks();				// Start all the independently managed tasks.

	create_fixture();

	FastLED_Show_ESP32();

	//Debug.Display_Memory(" after controller initialization.");

}

Controller::~Controller()
{
}

void Controller::run()
{

	check_physical_input();

	check_UDP_input();

	current_animation.run();

	FastLED_Show_ESP32();
}


