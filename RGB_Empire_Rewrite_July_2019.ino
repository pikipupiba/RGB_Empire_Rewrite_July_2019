// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       RGB_Empire_Rewrite_July_2019.ino
    Created:	7/8/2019 4:56:08 PM
    Author:     DESKTOP-UV9PIGM\pikipupiba
*/

//**********************//
//	Helper Files		//
//**********************//
#include "Bug.h"

//**********************//
//	Custom Libraries	//
//**********************//
#include "Controller.h"

// Create the pointer to our controller
Controller* controller;


// The setup() function runs once each time the micro-controller starts
void setup()
{
	delay(1500);

	Serial.begin(115200);

	// Delay to allow uploader time to fix unstable software.
	// Reduce or remove this for production.
	delay(1500);

	START;

	// Create the controller object
	// It initializes everything based on the values in Fixture_Parameters.h
	controller = new Controller();

	MEM;
	END;
}


void loop()
{
	controller->run();

	BUG1(Bug::fps(5));

}