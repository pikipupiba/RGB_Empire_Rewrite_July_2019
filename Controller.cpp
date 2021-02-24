// 
// 
// 

#include "Controller.h"
#include "Tasks.h"

// connect to wifi – returns true if successful or false if not
// TODO: move this to Wifi_Class
//bool connect_wifi(void)
//{
	//START;

	//char* ssid = "Trap_House";
	//char* password = "ThIsHoUsEisatrap72";


	//boolean state = true;
	//int i = 0;

	//WiFi.begin(ssid, password);
	//Serial.println("");
	//Serial.println("Connecting to WiFi");

	//// Wait for connection
	//Serial.print("Connecting");
	//while (WiFi.status() != WL_CONNECTED)
	//{
	//	delay(250);
	//	Serial.print(".");
	//	if (i > 40) {
	//		state = false;
	//		break;
	//	}
	//	i++;
	//}
	//if (state) {
	//	Serial.println("");
	//	Serial.print("Connected to ");
	//	Serial.println(ssid);
	//	Serial.print("IP address: ");
	//	Serial.println(WiFi.localIP());
	//}
	//else {
	//	Serial.println("");
	//	Serial.println("Connection failed.");
	//}

	//MEM;
	//END;

	//return state;
//}

Controller::Controller():
	fixture(LED_Fixture(fixture_parameters)),
	animation_controller(Animation_Controller::create(&fixture)),
	display(Display::create()),
	physical_input(Physical_Input())
{
	START;

	create_tasks();	// Start all the independently managed tasks.

	// Print some info about the fixture and animation to make sure everything initialized correctly.
	fixture.print_info();
	animation_controller.print_info();

	physical_input.check();	// TODO: implement this

	//connect_wifi();

	//wifi_input.connect();	// TODO: implement this
	//wifi_input.check();	// TODO: implement this

	FastLED.setBrightness(255);

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
	//wifi_input.check();

	EVERY_N_MILLISECONDS(250)
	{
		display.update();	// Update the oled screen.
	}

	animation_controller.run();

	FastLED_Show_ESP32();

	END;
}
