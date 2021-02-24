// LED_Fixture.h

// The LED Fixture is a container class that gives the Controller a single object
// to control and the Animation class one object to display on.

// As of right now, there is only one fixture per ESP32.

// There should also be methods that can alter how animations are displayed on the fixture.
// An example would be whether an animation runs in parallel on the strips or serially.

#ifndef _LED_FIXTURE_h
#define _LED_FIXTURE_h


#include "arduino.h"
#include "FastLED.h"
#include "vector"

#include "Fixture_Parameters.h"
#include "LED_Strip.h"

class LED_Fixture
{
 protected:

	 Fixture_Parameters fixture_params;

	 Shape shape;

	 Fixture_Display_Mode fixture_display_mode;

	 CRGBArray<fixture_parameters.total_num_leds> g_leds;

	 std::vector<LED_Strip> led_strips;

	 friend class Animation_Controller;

	 void create_strips();

 public:
	LED_Fixture(Fixture_Parameters new_fixture_params);
	~LED_Fixture();

	void print_arrangement_info(Strip_Display_Mode new_display_mode);

	void print_info();

	template <int pin>
	void setStrip(int num_leds_so_far, int new_num_leds);

	template<int n>
	void stripLoop(int num_leds_so_far);

	LED_Arrangement* make_arrangement(Fixture_Display_Mode new_fixture_display_mode);
	LED_Arrangement* make_arrangement();
};


#endif

