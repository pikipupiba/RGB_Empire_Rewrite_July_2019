// Controller.h

// The Controller class is responsible for creating all LED_Fixture and
// Animation objects, recieving input from the outside world, and using
// that input to coordinate all activities.

#ifndef _CONTROLLER_h
#define _CONTROLLER_h

//**********************//
//	Public Libraries	//
//**********************//
#include "arduino.h"
#include <FastLED.h>

//**********************//
//	Custom Classes		//
//**********************//
#include "LED_Fixture.h"
#include "Animation_Controller.h"
#include "Display.h"

//**********************//
//	Helper Files		//
//**********************//
#include "Bug.h"
#include "Physical_Input.h"
#include "UDP_Input.h"

class Controller
{
 protected:
	 static LED_Fixture* fixture;						// The object containing all our LEDs.
	 static Animation_Controller* animation_controller;	// The animation that is currently running.
	 static Display* display;
	 
 public:
	Controller();
	~Controller();

	static void run();			// The run() method is called every frame.

	// transition_to() is called to begin the process of transitioning to a new animation.
	//void transition_to(int new_animation_ID, int new_transition_type, float new_transition_time);


};

#endif

