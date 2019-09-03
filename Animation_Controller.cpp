#include "Animation_Controller.h"

Animation_Controller::Animation_Controller()
{
}


void Animation_Controller::print_info()
{
}

void Animation_Controller::run()
{
	START;

	if (transitioning)
	{
		transition_current_time += transition_speed;

		if (transition_current_time > transition_total_time)
		{
			delete current_animation;

			current_animation = next_animation;

			//next_animation = NULL;

			transition_current_time = 0;
			transitioning = false;

			current_animation->run();
		}
		else
		{
			float ratio = transition_total_time / (transition_total_time - transition_current_time);

			//current_animation->run_scaled(ratio);

			//next_animation->run_scaled(1 - ratio);
		}
	}
	else
	{
		current_animation->run();
	}

	END;
}

void Animation_Controller::start_animation()
{
	START;

	delete current_animation;

	current_animation = Animation::create(_Default, LED_Fixture::get_arrangements);

	END;
}

void Animation_Controller::change_animation(Animation_Name new_animation_name)
{
	START;

	transitioning = true;

	transition_current_time = 0;

	next_animation = Animation::create(new_animation_name);

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

}
