// Fixture_Properties.h

// This should be the only file you need to change when installing the chip into a new fixture.

// I'm thinking there are several ways to define a fixture and it's properties:
// 1: 100% manually by defining all neccessary variables.
// 2: 50% manually by using preset configurations.
// 3: 0% manually by parsing a fixture_ID into all relevant parameters.


#ifndef _FIXTURE_PROPERTIES_h
#define _FIXTURE_PROPERTIES_h

#include "arduino.h"
#include "My_Enums.h"


constexpr int num_strips = 8;			// You will also need to change the Strip_Parameter array size in Fixture_Parameters in My_Enums.h
constexpr int total_num_leds = 1152;	// TODO: make this programatic

constexpr int volts = 5;
constexpr int milli_amps = 100000;		// Maximum power output of the connected power supply. Setting this properly will prevent brown outs!

// { strip_pin, num_leds, leds_per_meter, shape, length_in_leds, width_in_leds }
constexpr Strip_Parameters strip_parameters[num_strips] = 
{
	{21,	144,	144,	Linear,	144,	1},
	{19,	144,	144,	Linear,	144,	1},
	{18,	144,	144,	Linear,	144,	1},
	{15,	144,	144,	Linear,	144,	1},
	{2,		144,	144,	Linear,	144,	1},
	{0,		144,	144,	Linear,	144,	1},
	{4,		144,	144,	Linear,	144,	1},
	{5,		144,	144,	Linear,	144,	1}
};

// { num_strips, total_num_leds, volts, milliamps, strip_parameters[] }
constexpr Fixture_Parameters fixture_parameters =
{
	num_strips,	total_num_leds,	volts,	milli_amps,
	strip_parameters

};

#endif

