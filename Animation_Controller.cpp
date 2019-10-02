#include "Animation_Controller.h"

Animation_Controller::Animation_Controller(LED_Fixture* new_fixture)
	:fixture(new_fixture)
{
	START;

	transition_type = _tt_Fade;
	transitioning = false;
	transition_total_time = 4000;
	transition_start_time = 0;

	fixture->print_arrangement_info(_sdm_Default);

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

	speed_scale_factor = FastLED.getFPS() > 0 ? float(100.0 / FastLED.getFPS()) : 1;

	erase_prev_frame();

	EVERY_N_SECONDS(10)
	{
		//change_animation(Animation_Name(random8(0,NUM_AUTOPLAY_ANIMATIONS)));
	}

	if (transitioning)
	{
		if(millis() - transition_start_time > transition_total_time)
		{
			delete current_animation;

			current_animation = next_animation;

			next_animation = nullptr;

			transitioning =  false;
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

	current_animation = Animation::create(_Default, fixture);

	END;
}

void Animation_Controller::change_animation(Animation_Name new_animation_name)
{
	START;

	if (!transitioning)
	{
		//delete mask;

		transition_type = Transition_Type(random8(0, 3));

		transitioning = true;

		transition_start_time = millis();

		next_animation = Animation::create(new_animation_name, fixture);

		if (transition_type == _tt_Dissolve || transition_type == _tt_Wipe)
		{
			mask = new bool[current_animation->num_leds];
			num_tDissolved = 0;

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
//void Animation_Controller::change_animation_variables(Animation_Variables_Old new_vars)
//{
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
//}

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
		case _tt_Fade:
			transition_Fade();
			break;
		case _tt_Wipe:
			transition_Wipe();
			break;
		case _tt_Dissolve:
			transition_Dissolve();
			break;
		default:
			transition_Fade();
		}
	}
	else
	{
		int cur_led_num = 0;

		THING;

		CRGB* current_next_frame = current_animation->next_frame();
		CRGBSet current_next_frame_set = CRGBSet(current_next_frame, current_animation->num_leds);

		THING;

		for (auto& group : current_animation->arrangement->led_groups)
		{
			//P(group->group_number);
			//P(group->size);

			for (auto& arr_led_set : group->leds)
			{
				int i = 0;

				//P(cur_led_num);

				for (auto& led : *arr_led_set)
				{
					led = current_animation->leds[cur_led_num + i++];
				}
			}
			cur_led_num += group->size;
		}
	}

	END;
}

void Animation_Controller::transition_Fade()
{
	START;

	int cur_led_num = 0;

	CRGB* current_next_frame = current_animation->next_frame();
	CRGBSet current_next_frame_set = CRGBSet(current_next_frame, current_animation->num_leds);

	CRGB* next_next_frame = next_animation->next_frame();
	CRGBSet next_next_frame_set = CRGBSet(next_next_frame, next_animation->num_leds);

	float ratio = (float)(transition_total_time - (millis() - transition_start_time)) / transition_total_time;

	if (ratio < 0)
	{
		ratio = 0;
	}

	for (auto& group : current_animation->arrangement->led_groups)
	{

		for (auto& arr_led_set : group->leds)
		{
			int i = 0;

			for (auto& led : *arr_led_set)
			{
				led = next_animation->leds[cur_led_num + i].nscale8_video(255 * (1 - ratio));
				led += current_animation->leds[cur_led_num + i].nscale8_video(255 * ratio);

				i++;
			}
		}
		cur_led_num += group->size;
	}

	END;
}

void Animation_Controller::transition_Wipe()
{
	int cur_led_num = 0;

	int cur_group_num = 0;

	CRGB* current_next_frame = current_animation->next_frame();
	CRGBSet current_next_frame_set = CRGBSet(current_next_frame, current_animation->num_leds);


	CRGB* next_next_frame = next_animation->next_frame();
	CRGBSet next_next_frame_set = CRGBSet(next_next_frame, next_animation->num_leds);

	float ratio = (float)(transition_total_time - (millis() - transition_start_time)) / transition_total_time;

	if (ratio < 0)
	{
		ratio = 0;
	}

	for (auto& group : current_animation->arrangement->led_groups)
	{
		for (auto& arr_led_set : group->leds)
		{
			int i = 0;

			for (auto& led : *arr_led_set)
			{
				if (i < abs(arr_led_set->len) * (1 - ratio))
				{
					led = next_animation->leds[cur_led_num + i];
				}
				else
				{
					led = current_animation->leds[cur_led_num + i];
				}

				i++;
			}
		}
		cur_led_num += group->size;
	}
}

void Animation_Controller::transition_Dissolve()
{
	START;

	int cur_led_num = 0;

	CRGB* current_next_frame = current_animation->next_frame();
	CRGBSet current_next_frame_set = CRGBSet(current_next_frame, current_animation->num_leds);


	CRGB* next_next_frame = next_animation->next_frame();
	CRGBSet next_next_frame_set = CRGBSet(next_next_frame, next_animation->num_leds);


	float ratio = (float)(transition_total_time - (millis() - transition_start_time)) / transition_total_time;

	ratio = (float)((float)ease16InOutQuad(int((float)UINT16_MAX * ratio)) / (float)UINT16_MAX);

	int new_num_tDissolved = current_animation->num_leds * (1 - ratio);

	while (new_num_tDissolved > num_tDissolved)
	{
		int index = random(0, current_animation->num_leds - 1);

		//Serial.println(num_tDissolved);

		if (mask[index])
		{
			//Serial.println(index);

			if (random(0, 2))
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
		
		num_tDissolved++;
	}

	for (auto& group : current_animation->arrangement->led_groups)
	{
		for (auto& arr_led_set : group->leds)
		{
			int i = 0;

			for (auto& led : *arr_led_set)
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
		}
		cur_led_num += group->size;
	}

	END;
}