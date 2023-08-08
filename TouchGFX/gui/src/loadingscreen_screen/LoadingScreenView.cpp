#include <gui/loadingscreen_screen/LoadingScreenView.hpp>

LoadingScreenView::LoadingScreenView()
{

}

void LoadingScreenView::setupScreen()
{
    LoadingScreenViewBase::setupScreen();
}

void LoadingScreenView::tearDownScreen()
{
    LoadingScreenViewBase::tearDownScreen();
}

void LoadingScreenView::handleTickEvent()
{
	LoadingScreenViewBase::handleTickEvent();
	int currentValue = boxProgress1.getValue();
	int max;
	int min;
	boxProgress1.getRange(min, max);

	if (currentValue == min) {
		increase = true;
	}
	else if (currentValue == max)
	{
		increase = false;
	}

	if(increase)
	{
		currentValue++;
		boxProgress1.setValue(currentValue);
	}
	else
	{
		application().gotoGameScreenScreenSlideTransitionEast();
	}
}
