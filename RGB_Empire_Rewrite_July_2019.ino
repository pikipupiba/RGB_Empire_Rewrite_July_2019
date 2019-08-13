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
#include "Debug.h"

//**********************//
//	Custom Libraries	//
//**********************//
#include "Controller.h"

Controller *controller;


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
void setup()
{
	delay(3000);

	Serial.begin(115200);

	//Serial.println("start");

	controller = new Controller();

}


void loop()
{
	//Serial.println("loop");


	controller->run();

	fps(5);

}