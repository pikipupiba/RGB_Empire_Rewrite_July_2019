// 
// 
// 

#include "LED_Fixture.h"

//**********************//
//	Protected Methods	//
//**********************//

void LED_Fixture::create_strips()
{
	Serial.println("bleh");

	fixture_num_leds = 0;
	int num_leds_so_far = 0;
	num_strips = fixture_parameters.num_strips;

	for (int i = 0; i < num_strips; i++)
	{
		if (i == 0)
		{
			FastLED.addLeds<WS2812B, strip_parameters[0].strip_pin, GRB>
				(g_leds, num_leds_so_far, strip_parameters[i].num_leds).setCorrection(TypicalLEDStrip);

			num_leds_so_far += strip_parameters[i].num_leds;
		}
		else if (i == 1)
		{
			FastLED.addLeds<WS2812B, strip_parameters[1].strip_pin, GRB>
				(g_leds, num_leds_so_far, strip_parameters[i].num_leds).setCorrection(TypicalLEDStrip);

			num_leds_so_far += strip_parameters[i].num_leds;
		}
		else if (i == 2)
		{
			FastLED.addLeds<WS2812B, strip_parameters[2].strip_pin, GRB>
				(g_leds, num_leds_so_far, strip_parameters[i].num_leds).setCorrection(TypicalLEDStrip);

			num_leds_so_far += strip_parameters[i].num_leds;
		}
		else if (i == 3)
		{
			FastLED.addLeds<WS2812B, strip_parameters[3].strip_pin, GRB>
				(g_leds, num_leds_so_far, strip_parameters[i].num_leds).setCorrection(TypicalLEDStrip);

			num_leds_so_far += strip_parameters[i].num_leds;
		}
		else if (i == 4)
		{
			FastLED.addLeds<WS2812B, strip_parameters[4].strip_pin, GRB>
				(g_leds, num_leds_so_far, strip_parameters[i].num_leds).setCorrection(TypicalLEDStrip);

			num_leds_so_far += strip_parameters[i].num_leds;
		}
		else if (i == 5)
		{
			FastLED.addLeds<WS2812B, strip_parameters[5].strip_pin, GRB>
				(g_leds, num_leds_so_far, strip_parameters[i].num_leds).setCorrection(TypicalLEDStrip);

			num_leds_so_far += strip_parameters[i].num_leds;
		}
		else if (i == 6)
		{
			FastLED.addLeds<WS2812B, strip_parameters[6].strip_pin, GRB>
				(g_leds, num_leds_so_far, strip_parameters[i].num_leds).setCorrection(TypicalLEDStrip);

			num_leds_so_far += strip_parameters[i].num_leds;
		}
		else if (i == 7)
		{
			FastLED.addLeds<WS2812B, strip_parameters[7].strip_pin, GRB>
				(g_leds, num_leds_so_far, strip_parameters[i].num_leds).setCorrection(TypicalLEDStrip);

			num_leds_so_far += strip_parameters[i].num_leds;
		}

		led_strips[i] = new LED_Strip
			(i,
				new CRGBSet(g_leds(fixture_num_leds, num_leds_so_far - 1)),
				strip_parameters[i]);

		fixture_num_leds = num_leds_so_far;
	}

	FastLED.setMaxPowerInVoltsAndMilliamps(volts, milli_amps);

	g_leds.fill_solid(CRGB::Black);
}

void LED_Fixture::print_info()
{
	for (int i = 0; i < num_strips; i++)
	{
		led_strips[i]->print_info();
	}
}

//**********************//
//	Public Methods		//
//**********************//

LED_Fixture::LED_Fixture()
{

	create_strips();

	//initilize_vars();

}

LED_Fixture::~LED_Fixture()
{
}


