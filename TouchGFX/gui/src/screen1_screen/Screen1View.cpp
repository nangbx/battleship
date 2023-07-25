#include <gui/screen1_screen/Screen1View.hpp>
//#include "cmsis_os.h"

//extern osMessageQueueId_t Queue1Handle;
Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
void Screen1View::handleTickEvent(){
	Screen1ViewBase::handleTickEvent();

	invalidate();
}
