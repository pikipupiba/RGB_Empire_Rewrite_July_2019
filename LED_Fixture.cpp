// 
// 
// 

#include "LED_Fixture.h"

std::vector<LED_Strip> LED_Fixture::led_strips;

//**********************//
//	Protected Methods	//
//**********************//

void LED_Fixture::create_strips()
{
	START;

	fixture_num_leds = 0;
	int num_leds_so_far = 0;
	num_strips = fixture_parameters.num_strips;

	// Can use template metaprogramming to fix this section.
	/*for (int i = 0; i < num_strips; i++)
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

		led_strips.push_back(LED_Strip
			(i,
				new CRGBSet(g_leds(fixture_num_leds, num_leds_so_far - 1)),
				strip_parameters[i]));

		fixture_num_leds = num_leds_so_far;
	}*/
	// DONE IT!
	stripLoop<fixture_parameters.num_strips>(num_leds_so_far);

	FastLED.setMaxPowerInVoltsAndMilliamps(volts, milli_amps);

	g_leds.fill_solid(CRGB::Black);

	MEM;

	END;
}

void LED_Fixture::print_info()
{
	for (auto& strip: led_strips)
	{
		strip.print_info();
	}
}

//**********************//
//	Public Methods		//
//**********************//

LED_Fixture::LED_Fixture()
{
	START;

	create_strips();

	//initilize_vars();

	END;

}

LED_Fixture::~LED_Fixture()
{
}

LED_Fixture LED_Fixture::create()
{
	START;

	END;

	return LED_Fixture();
}

LED_Arrangements* LED_Fixture::get_arrangements()
{
	START;

	LED_Arrangements* temp_arrangements = new LED_Arrangements;

	for (auto& strip : led_strips)
	{
		temp_arrangements->arrangements.push_back(strip.led_arrangements.arrangements[Default_Strip]);
	}

	END;

	return temp_arrangements;
}

void LED_Fixture::print_arrangement_info(Strip_Display_Mode new_display_mode)
{
	START;

	for (auto& strip : led_strips)
	{
		strip.print_arrangement_info(new_display_mode);
	}

	END;
}

template <int pin>
void LED_Fixture::setStrip(int num_leds_so_far, int new_num_leds)
{
	FastLED.addLeds<WS2812B, pin, GRB>
		(g_leds, num_leds_so_far, new_num_leds).setCorrection(TypicalLEDStrip);

}

template<int n>
void LED_Fixture::stripLoop(int num_leds_so_far)
{

	setStrip<strip_parameters[n - 1].strip_pin>(num_leds_so_far, strip_parameters[n-1].num_leds);
	num_leds_so_far += strip_parameters[n - 1].num_leds;

	led_strips.push_back(
		LED_Strip
		(n-1,
		new CRGBSet(g_leds(fixture_num_leds, num_leds_so_far - 1)),
		strip_parameters[n-1])
	);

	fixture_num_leds = num_leds_so_far;

	stripLoop<n - 1>(num_leds_so_far);
}

template<>
void LED_Fixture::stripLoop<0>(int num_leds_so_far) {};
 