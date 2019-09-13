#include "Animation_Controller.h"

Animation_Controller::Animation_Controller(LED_Fixture* new_fixture)
	:fixture(new_fixture)
{
	START;

	transition_type = _Fade;
	transitioning = false;
	transition_total_time = 5000;
	transition_start_time = 0;

	LED_Fixture::print_arrangement_info(Default_Strip);

	start_animation();

	current_animation->print_arrangement_info();

	MEM;
	END;
}

Animation_Controller Animation_Controller::create(LED_Fixture* new_fixture)
{
	START;
	END;

	return Animation_Controller(new_fixture);
}


void Animation_Controller::print_info()
{
	START;
	END;
}

void Animation_Controller::run()
{
	START;

	erase_prev_frame();

	EVERY_N_SECONDS(15)
	{
		static bool z = true;
		if (z)
		{
			change_animation(_Artnet);

			//z = false;
		}
		else
		{
			change_animation(_Glitter);
		}

		z = !z;
	}

	if (transitioning)
	{
		if(millis() - transition_start_time > transition_total_time)
		{
			delete current_animation;

			current_animation = next_animation;

			next_animation = nullptr;

			transitioning = false;
		}
		else
		{
			next_animation->run();
		}
	}
	
	current_animation->run();

	show();

	END;
}

void Animation_Controller::start_animation()
{
	START;

	//delete current_animation;

	current_animation = Animation::create(_Default, LED_Fixture::get_arrangements());

	END;
}

void Animation_Controller::change_animation(Animation_Name new_animation_name)
{
	START;

	if (!transitioning)
	{
		//delete mask;

		transitioning = true;

		transition_start_time = millis();

		next_animation = Animation::create(new_animation_name, LED_Fixture::get_arrangements());

		if (transition_type == _Dissolve || transition_type == _Wipe)
		{
			mask = new bool[current_animation->num_leds];
			num_dissolved = 0;

			for (int i = 0; i < current_animation->num_leds; i++)
			{
				mask[i] = false;
			}
		}
	}
	END;
}

// Surely there is a better way to do this that doesn't require so many comparisons?
// Make the input classes friend class of the animation class!
void Animation_Controller::change_animation_variables(Animation_Variables new_vars)
{
	//current_animation->vars.brightness = (new_vars.brightness == NULL) ? current_animation->vars.brightness : new_vars.brightness;
	//current_animation->vars.brightness_speed = (new_vars.brightness_speed == NULL) ? current_animation->vars.brightness_speed : new_vars.brightness_speed;
	//current_animation->vars.brightness_acceleration = (new_vars.brightness_acceleration == NULL) ? current_animation->vars.brightness_acceleration : new_vars.brightness_acceleration;
	//current_animation->vars.brightness_offset = (new_vars.brightness_offset == NULL) ? current_animation->vars.brightness_offset : new_vars.brightness_offset;

	//current_animation->vars.acceleration = (new_vars.acceleration == NULL) ? current_animation->vars.acceleration : new_vars.acceleration;

	//switch (vars.strip_display_mode)
	//{
	//case Parallel:
	//	for (auto& led_set : leds) {
	//		led_set->fill_rainbow(vars.hue, vars.hue_offset);
	//	}
	//	break;
	//case Sequential:
	//{
	//	int offset = 0;

	//	for (auto& led_set : leds) {
	//		led_set->fill_rainbow(vars.hue + offset, vars.hue_offset);

	//		offset += led_set->size() % (int)vars.hue_offset;
	//	}
	//}

	//break;
	//default:
	//	for (auto& led_set : leds) {
	//		led_set->fill_rainbow(vars.hue, vars.hue_offset);
	//	}
	//}
}

void Animation_Controller::erase_prev_frame()
{
	START;

	fixture->g_leds.fill_solid(CRGB::Black);

	END;
}

// Show the current_animation leds based on it's led_arrangements
void Animation_Controller::show()
{
	START;

	if (transitioning)
	{
		switch (transition_type)
		{
		case _Fade:
			transition_fade();
			break;
		case _Wipe:
			transition_wipe();
			break;
		case _Dissolve:
			transition_dissolve();
			break;
		default:
			transition_fade();
		}
	}
	else
	{
		int cur_led_num = 0;

		CRGB* current_next_frame = current_animation->next_frame();
		CRGBSet current_next_frame_set = CRGBSet(current_next_frame, current_animation->num_leds);

		for (LED_Arrangement& arrangement : current_animation->led_arrangements->arrangements)
		{
			for (LED_Group& group : arrangement.led_groups)
			{
				for (CRGBSet& arr_led_set : group.leds)
				{
					//arr_led_set = next_frame_set(cur_led_num, cur_led_num + arr_led_set.len);

					int i = 0;

					for (auto& led : arr_led_set)
					{
						//Serial.println(cur_led_num + i);
						led = current_animation->leds[cur_led_num + i++];
						//Serial.println(arr_led_set.len);
					}

					THING;
				}

				cur_led_num += abs(group.leds[0].len);
				//Serial.println(cur_led_num);
			}
		}
	}

	END;
}

void Animation_Controller::transition_fade()
{
	START;

	int cur_led_num = 0;

	CRGB* current_next_frame = current_animation->next_frame();
	CRGBSet current_next_frame_set = CRGBSet(current_next_frame, current_animation->num_leds);

	CRGB* next_next_frame = next_animation->next_frame();
	CRGBSet next_next_frame_set = CRGBSet(next_next_frame, next_animation->num_leds);

	float ratio = (float)(transition_total_time - (millis() - transition_start_time)) / transition_total_time;

	for (LED_Arrangement& arrangement : current_animation->led_arrangements->arrangements)
	{
		for (LED_Group& group : arrangement.led_groups)
		{
			for (CRGBSet& arr_led_set : group.leds)
			{
				//arr_led_set = next_frame_set(cur_led_num, cur_led_num + arr_led_set.len);

				int i = 0;

				for (CRGB& led : arr_led_set)
				{
					//Serial.println(cur_led_num + i);
					THING;

					led = next_animation->leds[cur_led_num + i].fadeLightBy(255 * ratio);
					led += current_animation->leds[cur_led_num + i++].fadeLightBy(255 * (1 - ratio));
					//Serial.println(arr_led_set.len);
				}

				THING;
			}

			cur_led_num += abs(group.leds[0].len);
			//Serial.println(cur_led_num);
		}
	}

	END;
}

void Animation_Controller::transition_wipe()
{
	int cur_led_num = 0;

	CRGB* current_next_frame = current_animation->next_frame();
	CRGBSet current_next_frame_set = CRGBSet(current_next_frame, current_animation->num_leds);


	CRGB* next_next_frame = next_animation->next_frame();
	CRGBSet next_next_frame_set = CRGBSet(next_next_frame, next_animation->num_leds);


	float ratio = (float)(transition_total_time - (millis() - transition_start_time)) / transition_total_time;

	for (LED_Arrangement& arrangement : current_animation->led_arrangements->arrangements)
	{
		for (LED_Group& group : arrangement.led_groups)
		{
			for (CRGBSet& arr_led_set : group.leds)
			{
				//arr_led_set = next_frame_set(cur_led_num, cur_led_num + arr_led_set.len);

				int i = 0;

				for (CRGB& led : arr_led_set)
				{
					if (i < abs(arr_led_set.len) * (1 - ratio))
					{
						led = next_animation->leds[cur_led_num + i];
					}
					else
					{
						led = current_animation->leds[cur_led_num + i];
					}

					i++;
				}

				THING;
			}

			cur_led_num += abs(group.leds[0].len);
			//Serial.println(cur_led_num);
		}
	}
}

void Animation_Controller::transition_dissolve()
{
	START;

	int cur_led_num = 0;

	CRGB* current_next_frame = current_animation->next_frame();
	CRGBSet current_next_frame_set = CRGBSet(current_next_frame, current_animation->num_leds);


	CRGB* next_next_frame = next_animation->next_frame();
	CRGBSet next_next_frame_set = CRGBSet(next_next_frame, next_animation->num_leds);


	float ratio = (float)(transition_total_time - (millis() - transition_start_time)) / transition_total_time;

	int new_num_dissolved = current_animation->num_leds * (1 - ratio);

	while (new_num_dissolved > num_dissolved)
	{
		int index = random(0, current_animation->num_leds - 1);

		//Serial.println(num_dissolved);

		if (mask[index])
		{
			//Serial.println(index);

			if (random(0, 1))
			{
				
				while (mask[index])
				{
					index++;

					if (index >= current_animation->num_leds)
					{
						index = 0;
					}
				}
			}
			else
			{
				
				while (mask[index])
				{
					index--;

					if (index < 0)
					{
						index = current_animation->num_leds - 1;
					}
				}
			}
			
		}
		
		mask[index] = true;
		
		num_dissolved++;
	}

	for (LED_Arrangement& arrangement : current_animation->led_arrangements->arrangements)
	{
		for (LED_Group& group : arrangement.led_groups)
		{
			for (CRGBSet& arr_led_set : group.leds)
			{
				//arr_led_set = next_frame_set(cur_led_num, cur_led_num + arr_led_set.len);

				int i = 0;

				for (CRGB& led : arr_led_set)
				{
					if (mask[i])
					{
						led = next_animation->leds[cur_led_num + i];
					}
					else
					{
						led = current_animation->leds[cur_led_num + i];
					}
					i++;
				}

				THING;
			}

			cur_led_num += abs(group.leds[0].len);
			//Serial.println(cur_led_num);
		}
	}

	END;
}
