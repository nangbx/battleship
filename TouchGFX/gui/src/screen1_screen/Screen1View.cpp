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
	// uint16_t res = 0;
	//uint32_t count = osMessageQueueGetCount(Queue1Handle);
	// if (count > 0){
		//osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
		/*if(res == 'R'){
			int16_t x = car.getX();
			x += 2;
			if (x > 240){
				x = 0;
			}
			car.setX(x);
		}
		if(res == 'L'){
			int16_t x = car.getX();
			x -= 2;
			if (x < 0){
				x = 240;
			}
			car.setX(x);
		}
		if(res == 'U'){
			int16_t y = car.getY();
			y -= 2;
			if (y < 0){
				y = 235;
			}
			car.setY(y);
		}
		if(res == 'D'){
			int16_t y = car.getY();
			y += 2;
			if (y > 235){
				y = 0;
			}
			car.setY(y);
		}*/
	//}
	invalidate();
}
