// Controller.h

// The Controller class is responsible for creating all LED_Fixture, Display,
// Input, and Animation_Controller objects, recieving input from the outside world,
// and using that input to coordinate all activities.

#ifndef _CONTROLLER_h
#define _CONTROLLER_h

//**********************//
//	Public Libraries	//
//**********************//
#include "arduino.h"

// Had to define this in FastLED_esp32.h for some reason it didn't work here.
#define FASTLED_ESP32_I2S true

#include <FastLED.h>

//**********************//
//	Custom Classes		//
//**********************//
#include "LED_Fixture.h"
#include "Animation_Controller.h"
#include "Display.h"
#include "Physical_Input.h"
#include "Wifi_Class.h"

//**********************//
//	Helper Files		//
//**********************//
#include "Bug.h"

class Controller
{
 protected:
	 LED_Fixture fixture;						// The object containing all our LEDs.
	 Animation_Controller animation_controller;	// The animation that is currently running.
	 Display display;							// The oled screen object.

	 Physical_Input physical_input;	// The object that interacts with the buttons.
	 Wifi_Class wifi_input;			// The object for sending and recieving wifi data.
	 
 public:
	Controller();
	~Controller();

	void run();	// The run() method is called every frame.
};

#endif

