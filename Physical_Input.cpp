// 
// 
// 

#include "Physical_Input.h"


void Physical_Input::best_Button_on_pressed()
{
}

Physical_Input::Physical_Input()
	:enabled(true),
	best_Button(EasyButton(_Best_Button_Pin)),
	rotary_Button(EasyButton(_Rotary_Button_Pin))//,
	//encoder(Encoder(_Rotary_Pin_A, _Rotary_Pin_B))
{
	

}



void Physical_Input::setup()
{
	best_Button.onPressed(Physical_Input::best_Button_on_pressed);
}

void Physical_Input::check()
{
	best_Button.read();
	rotary_Button.read();
}
