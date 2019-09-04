// 
// 
// 

#include "Controller.h"
#include "Tasks.h"


Controller::Controller():
	fixture(LED_Fixture::create()),
	animation_controller(Animation_Controller::create()),
	display(Display::create())
{
	START;

	setup_physical_input();		// initialize physical buttons and knobs.
	setup_UDP_input();			// initialize UDP Input ports.

	create_tasks();				// Start all the independently managed tasks.

	fixture.print_info();

	animation_controller.print_info();

	FastLED.setBrightness(255);

	FastLED_Show_ESP32();

	MEM;

	END;
}

Controller::~Controller()
{
	
}

void Controller::run()
{
	START;

	check_physical_input();

	check_UDP_input();

	//change();

	animation_controller.run();

	FastLED_Show_ESP32();

	END;
}


