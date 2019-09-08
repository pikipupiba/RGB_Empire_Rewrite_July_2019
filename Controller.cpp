// 
// 
// 

#include "Controller.h"
#include "Tasks.h"


Controller::Controller():
	fixture(LED_Fixture::create()),
	animation_controller(Animation_Controller::create(&fixture)),
	display(Display::create()),
	physical_input(Physical_Input())
{
	START;

	//setup_physical_input();		// initialize physical buttons and knobs.
	setup_UDP_input();			// initialize UDP Input ports.

	create_tasks();				// Start all the independently managed tasks.

	fixture.print_info();

	animation_controller.print_info();

	physical_input.check();

	FastLED.setBrightness(100);

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

	physical_input.check();

	check_UDP_input();

	display.update();

	animation_controller.run();

	FastLED_Show_ESP32();

	END;
}


