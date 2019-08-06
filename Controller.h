// Controller.h

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
	 LED_Fixture fixture;
	 Animation current_animation;
	 Animation next_animation;

	 
 public:
	void init();

	void run();

	void check_inputs();
	void check_UDP();

	void transition_to(int new_animation_ID, int new_transition_type);


};

#endif

