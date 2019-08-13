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
#include <WiFi.h>
#include <WiFiUdp.h>

//**********************//
//	Custom Libraries	//
//**********************//
#include "LED_Fixture.h"
#include "Animation.h"

//**********************//
//	Helper Files		//
//**********************//
#include "Physical_Input.h"
#include "UDP_Input.h"

class Controller
{
 protected:
	 LED_Fixture* fixture;			// The object containing all our LEDs.
	 Animation* current_animation;	// The animation that is currently running.
	 Animation* next_animation;		// The animation that we are transitioning to.

	 void create_fixture();			// The method that creates our LED_Fixture object.
	 
 public:
	Controller();
	~Controller();

	void run();			// The run() method is called every frame.

	// transition_to() is called to begin the process of transitioning to a new animation.
	//void transition_to(int new_animation_ID, int new_transition_type, float new_transition_time);


};

#endif

