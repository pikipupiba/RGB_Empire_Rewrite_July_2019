// 
// 
// 

#include "LED_Strip.h"
#include "Create_Arrangements.h"

void LED_Strip::print_info()
{
	Serial.print("Strip #");
	Serial.print(strip_index);
	Serial.println(" Information:");

	Serial.print("   ");
	Serial.print(num_leds);
	Serial.println(" LEDs");

	Serial.print("   ");
	Serial.print(leds_per_meter);
	Serial.println(" LEDs / meter");
}


LED_Strip::LED_Strip(int new_strip_index, CRGBSet* new_leds, Strip_Parameters new_strip_parameters)
	:strip_index(new_strip_index),
	leds(new_leds),
	num_leds(new_strip_parameters.num_leds),
	leds_per_meter(new_strip_parameters.leds_per_meter),
	shape(new_strip_parameters.shape),
	length_in_leds(new_strip_parameters.length_in_leds),
	width_in_leds(new_strip_parameters.width_in_leds)
{

	int current_position = 0;

	led_arrangements = create_arrangements(new_strip_parameters);

	
}

LED_Strip::~LED_Strip()
{
	
}

LED_Arrangement* LED_Strip::get_led_arrangement(Display_Mode new_display_mode)
{
	return nullptr;
}
