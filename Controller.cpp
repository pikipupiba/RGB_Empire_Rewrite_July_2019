// 
// 
// 

#include "Controller.h"
#include "Tasks.h"

Controller::Controller():
	fixture(LED_Fixture(fixture_parameters)),
	animation_controller(Animation_Controller::create(&fixture))
	//display(Display::create()),
	//physical_input(Physical_Input())
{
	START;

	create_tasks();	// Start all the independently managed tasks.

	// Print some info about the fixture and animation to make sure everything initialized correctly.
	fixture.print_info();
	animation_controller.print_info();

	//physical_input.check();	// TODO: implement this

	if (Wifi_Class::connected == false)
	{
		Wifi_Class::start_wifi(&animation_controller);
	}

	//wifi_input.connect();	// TODO: implement this
	//wifi_input.check();	// TODO: implement this

	FastLED.setBrightness(35);

	MEM;

	END;
}

Controller::~Controller()
{
	
}

void Controller::run()
{
	START;

	// Check for input from buttons and wifi.
	//physical_input.check();
	Wifi_Class::get_udp_input();

	//EVERY_N_MILLISECONDS(250)
	//{
	//	display.update();	// Update the oled screen.
	//}

	//delay(20);

	animation_controller.run();

	FastLED_Show_ESP32();

	END;
}
