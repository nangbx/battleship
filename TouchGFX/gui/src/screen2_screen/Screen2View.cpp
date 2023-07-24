#include <gui/screen2_screen/Screen2View.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::handleTickEvent()
{
	int currentValue = boxProgress1.getValue();
	int max;
	int min;
	boxProgress1.getRange(min, max);

	if (currentValue == min)
	{
		increase = true;
	}
	else if (currentValue == max)
	{
	    increase = false;
	}
	if(increase == true)
		currentValue += 1;
	boxProgress1.setValue(currentValue);

}
