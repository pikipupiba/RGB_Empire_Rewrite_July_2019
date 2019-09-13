// 
// 
// 

#include "Controller.h"
#include "Tasks.h"

// connect to wifi – returns true if successful or false if not
bool connect_wifi(void)
{
	START;

	char* ssid = "Trap_House";
	char* password = "ThIsHoUsEisatrap72";


	boolean state = true;
	int i = 0;

	WiFi.begin(ssid, password);
	Serial.println("");
	Serial.println("Connecting to WiFi");

	// Wait for connection
	Serial.print("Connecting");
	while (WiFi.status() != WL_CONNECTED) {
		delay(250);
		Serial.print(".");
		if (i > 20) {
			state = false;
			break;
		}
		i++;
	}
	if (state) {
		Serial.println("");
		Serial.print("Connected to ");
		Serial.println(ssid);
		Serial.print("IP address: ");
		Serial.println(WiFi.localIP());
	}
	else {
		Serial.println("");
		Serial.println("Connection failed.");
	}

	MEM;
	END;

	return state;
}

Controller::Controller():
	fixture(LED_Fixture::create()),
	animation_controller(Animation_Controller::create(&fixture)),
	display(Display::create()),
	physical_input(Physical_Input())
{
	START;

	//setup_physical_input();		// initialize physical buttons and knobs.
	//setup_UDP_input();			// initialize UDP Input ports.

	create_tasks();				// Start all the independently managed tasks.

	fixture.print_info();

	animation_controller.print_info();

	physical_input.check();

	connect_wifi();

	FastLED.setBrightness(80);

	//FastLED_Show_ESP32();

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

	//check_UDP_input();

	display.update();

	animation_controller.run();

	FastLED_Show_ESP32();

	END;
}
