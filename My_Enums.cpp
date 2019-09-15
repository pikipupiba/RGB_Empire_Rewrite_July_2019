#include "My_Enums.h"

int LED_Arrangement::get_num_groups()
{
	START;

	int cur_group_num = -1;
	int total_num_groups = 0;


	for (auto& group : led_groups)
	{
		if (group.group_number != cur_group_num)
		{
			total_num_groups++;

			cur_group_num = group.group_number;
		}
	}

	Serial.println("number of Groups in arrangement = " + (String)total_num_groups);

	num_groups = total_num_groups;

	END;

	return total_num_groups;
}

int LED_Arrangement::get_size()
{
	START;

	int group_num_leds = 0;
	int cur_group_num = 0;
	int total_num_leds = 0;

	for (auto& group : led_groups)
	{
		if (group.group_number != cur_group_num)
		{
			total_num_leds += group_num_leds;

			group_num_leds = 0;

			cur_group_num = group.group_number;
		}


		for (auto& led_set : group.leds)
		{
			if (abs(led_set.len) > group_num_leds)
			{
				group_num_leds = abs(led_set.len);
			}
		}

	}

	total_num_leds += group_num_leds;

	Serial.println("number of LEDs in arrangement = " + (String)total_num_leds);

	size = total_num_leds;

	END;

	return total_num_leds;
}

int LED_Arrangements::get_num_groups()
{
	return 0;
}

int LED_Arrangements::get_size()
{
	START;

	//int num_leds = 0;

	//for (auto& arrangement : arrangements)
	//{
	//	num_leds += arrangement.get_size();

	//}

	int group_num_leds = 0;
	int cur_group_num = 0;
	int total_num_leds = 0;

	for (auto& arrangement : arrangements)
	{
		for (auto& group : arrangement.led_groups)
		{
			if (group.group_number != cur_group_num)
			{
				total_num_leds += group_num_leds;

				group_num_leds = 0;

				cur_group_num = group.group_number;
			}


			for (auto& led_set : group.leds)
			{
				if (abs(led_set.len) > group_num_leds)
				{
					group_num_leds = abs(led_set.len);
				}
			}

		}
	}

	total_num_leds += group_num_leds;

	Serial.println("number of LEDs in arrangements = " + (String)total_num_leds);

	size = total_num_leds;

	END;

	return total_num_leds;
}

int LED_Arrangements::get_artnet_size()
{
	START;

	int num_leds = 0;

	for (auto& arrangement : arrangements)
	{
		for (auto& group : arrangement.led_groups)
		{
			for (auto& led_set : group.leds)
			{
				num_leds = abs(led_set.len);
			}
		}
	}

	END;

	return num_leds;
}

LED_Arrangement LED_Arrangements::compress()
{
	LED_Arrangement temp_arrangement;
	LED_Group temp_group;
	int max_group_number = -1;

	for (auto& arrangement : arrangements)
	{
		for (auto& group : arrangement.led_groups)
		{
			if (group.group_number > max_group_number)
			{
				temp_group.group_number = group.group_number;
				temp_arrangement.led_groups.push_back(temp_group);

				max_group_number = group.group_number;
			}

			temp_arrangement.led_groups[group.group_number].add_to_group(group);
		}
	}

	for (auto& group : temp_arrangement.led_groups)
	{
		group.size = group.get_size();
	}

	return temp_arrangement;
}

int LED_Group::get_size()
{
	START;

	int group_num_leds = 0;
	int cur_group_num = 0;
	int total_num_leds = 0;

	for (auto& led_set : leds)
	{
		if (abs(led_set.len) > group_num_leds)
		{
			total_num_leds = abs(led_set.len);
		}
	}

	//Serial.println("number of LEDs in group = " + (String)total_num_leds);

	END;

	return total_num_leds;
}

void LED_Group::add_to_group(LED_Group new_group)
{
	for (auto& led_set : new_group.leds)
	{
		leds.push_back(led_set);
	}
}

//Animation_Variable::Animation_Variable(Variable_Name new_name, Bounded_Variable new_value, Bounded_Variable new_speed, Bounded_Variable new_acceleration, Bounded_Variable new_offset, End_Of_Range new_eor)
//	:name(new_name),
//	value(new_value),
//	speed(new_speed),
//	acceleration(new_acceleration),
//	offset(new_offset),
//	eor(new_eor)
//{
//}

//Animation_Variable::Animation_Variable(Variable_Name new_name, float new_value, float new_speed, float new_offset, float new_min, float new_max, End_Of_Range new_eor)
//	:name(new_name),
//	value(Bounded_Variable(new_value, new_min, new_max, _Loop)),
//	speed(Bounded_Variable(new_speed, 0, 10, _Stop)),
//	acceleration(Bounded_Variable(0, 0, 1, _Stop)),
//	offset(Bounded_Variable(new_offset, 0, 1000, _Stop)),
//	eor(new_eor)
//{
//	START;
//
//	switch (new_eor)
//	{
//	case _Default_EOR:
//	case _Loop:
//		value = Bounded_Variable(new_value, new_min, new_max, _Loop);
//		speed = Bounded_Variable(new_speed, 0, 10, _Stop);
//		acceleration = Bounded_Variable(0, 0, 1, _Stop);
//		offset = Bounded_Variable(new_offset, 0, 1000, _Stop);
//		break;
//	case _Bounce:
//		value = Bounded_Variable(new_value, new_min, new_max, _Bounce);
//		speed = Bounded_Variable(new_speed, 0, 10, _Stop);
//		acceleration = Bounded_Variable(0, 0, 1, _Stop);
//		offset = Bounded_Variable(new_offset, 0, 1000, _Stop);
//		break;
//	case _Stop:
//		value = Bounded_Variable(new_value, new_min, new_max, _Stop);
//		speed = Bounded_Variable(new_speed, 0, 10, _Stop);
//		acceleration = Bounded_Variable(0, 0, 1, _Stop);
//		offset = Bounded_Variable(new_offset, 0, 1000, _Stop);
//		break;
//	default:
//		value = Bounded_Variable(new_value, new_min, new_max, new_eor);
//		speed = Bounded_Variable(new_speed, 0, 10, new_eor);
//		acceleration = Bounded_Variable(0, 0, 1, _Stop);
//		offset = Bounded_Variable(new_offset, 0, 1000, _Stop);
//	}
//
//	END;
//}

Animation_Variable::Animation_Variable(Variable_Name new_name, float new_value, float new_speed, float new_acceleration, float new_offset, float new_min, float new_max, End_Of_Range new_eor)
	:name(new_name),
	value(Bounded_Variable(new_value, new_min, new_max, new_eor)),
	speed(Bounded_Variable(new_speed, -10, 10, _Stop)),
	acceleration(Bounded_Variable(new_acceleration, -1, 1, _Stop)),
	offset(Bounded_Variable(new_offset, -1000, 1000, _Stop)),
	eor(new_eor)
{
	START;

	switch (eor)
	{
	case _Default_EOR:
	case _Loop:
		value = Bounded_Variable(new_value, new_min, new_max, _Loop);
		speed = Bounded_Variable(new_speed, -10, 10, _Stop);
		acceleration = Bounded_Variable(new_acceleration, -1, 1, _Stop);
		offset = Bounded_Variable(new_offset, -1000, 1000, _Stop);
		break;
	case _Bounce:
		value = Bounded_Variable(new_value, new_min, new_max, _Bounce);
		speed = Bounded_Variable(new_speed, -10, 10, _Bounce);
		acceleration = Bounded_Variable(new_acceleration, -1, 1, _Bounce);
		offset = Bounded_Variable(new_offset, -1000, 1000, _Bounce);
		break;
	case _Stop:
		value = Bounded_Variable(new_value, new_min, new_max, _Stop);
		speed = Bounded_Variable(new_speed, -10, 10, _Stop);
		acceleration = Bounded_Variable(new_acceleration, -1, 1, _Stop);
		offset = Bounded_Variable(new_offset, -1000, 1000, _Stop);
		break;
	default:
		value = Bounded_Variable(new_value, new_min, new_max, new_eor);
		speed = Bounded_Variable(new_speed, -10, 10, new_eor);
		acceleration = Bounded_Variable(new_acceleration, -1, 1, _Stop);
		offset = Bounded_Variable(new_offset, -1000, 1000, _Stop);
	}

	END;
}

void Animation_Variable::update()
{
	START;

	value.value += speed.value * speed_scale_factor;
	speed.value += acceleration.value * speed_scale_factor;

	//if (name == _vPosition && value.value > value.max)
	//{
	//	P(name);
	//	P(value.value);
	//	P(speed.value);
	//}

	if (value.is_at_eor())
	{
		switch (eor)
		{
		case _Default_EOR:	// same as loop
		case _Loop:
			// do nothing
			break;

		case _Bounce:
			if (value.value == value.min)
			{
				speed.make_positive();
				acceleration.make_positive();
			}
			else if (value.value == value.max)
			{

				speed.make_negative();
				acceleration.make_negative();
			}
			break;

		case _Stop:
			speed.value = 0;
			acceleration.value = 0;
			break;

		default:	// same as _Loop
			;// do nothing
		}
	}
	if (speed.is_at_eor())
	{
		switch (speed.eor)
		{
		case _Default_EOR:	// same as loop
		case _Loop:
			// do nothing
			break;

		case _Bounce:
			if (speed.value == speed.min)
			{
				acceleration.make_positive();
			}
			else if (speed.value == speed.max)
			{
				acceleration.make_negative();
			}
			break;

		case _Stop:
			acceleration.value = 0;
			break;

		default:	// same as _Loop
			;// do nothing
		}
	}

	END;
}

Bounded_Variable::Bounded_Variable(float new_value, float new_min, float new_max, End_Of_Range new_eor)
	:value(new_value),
	min(new_min),
	max(new_max),
	eor(new_eor)
{
	START;
	END;
}

bool Bounded_Variable::is_at_eor()
{
	START;

	if (value < min)
	{
		switch (eor)
		{
		case _Default_EOR:	// same as loop
		case _Loop:
			value = max;
			break;
		case _Bounce:
			value = min;
			break;
		case _Stop:
			value = min;
		default:	// same as _Loop
			value = max;
		}
		END;

		return true;
	}
	else if (value > max)
	{
		switch (eor)
		{
		case _Default_EOR:	// same as loop
		case _Loop:
			value = min;
			break;
		case _Bounce:
			value = max;
			break;
		case _Stop:
			value = max;
		default:	// same as _Loop
			value = min;
		}

		END;

		return true;
	}
	else
	{
		END;

		return false;
	}

}

void Bounded_Variable::make_positive()
{
	START;

	value = value < 0 ? -value : value;

	END;
}

void Bounded_Variable::make_negative()
{
	START;

	value = value > 0 ? -value : value;

	END;
}


Animation_Variables::Animation_Variables(float new_range_start, float new_range_end)
	:range_start(new_range_start),
	range_end(new_range_end),
	brightness(Animation_Variable(_vBrightness,	255,0,	0, 0, 0, 255,	_Bounce)),
	position(Animation_Variable(	_vPosition,	0,	0.2,0, 0, range_start, range_end,	_Bounce)),
	hue(Animation_Variable(				_vHue,	0,	1,	0, 5, 0, 255,	_Loop)),
	size(Animation_Variable(			_vSize,	4, 0,	0, 0, 1, 20,	_Bounce)),
	density(Animation_Variable(		_vDensity,	5,	0,	0, 0, 0, 1000,	_Bounce)),
	fade(Animation_Variable(			_vFade,	80, 0,	0, 0, 0, 255,	_Bounce))
	
{
	START;

	END;
}
