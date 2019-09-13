// 
// 
// 

#include "Physical_Input.h"


void Physical_Input::best_button_on_pressed()
{
}

Physical_Input::Physical_Input()
	:enabled(true),
	best_button(EasyButton(_Best_Button_Pin)),
	rotary_button(EasyButton(_Rotary_Button_Pin))//,
	//encoder(Encoder(_Rotary_Pin_A, _Rotary_Pin_B))
{
	

}



void Physical_Input::setup()
{
	best_button.onPressed(Physical_Input::best_button_on_pressed);
}

void Physical_Input::check()
{
	best_button.read();
	rotary_button.read();
}
