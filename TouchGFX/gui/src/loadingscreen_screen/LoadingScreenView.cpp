#include <gui/loadingscreen_screen/LoadingScreenView.hpp>
#include <cmsis_os.h>

extern osMessageQueueId_t Queue6Handle;


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
		uint8_t res = 0;
		uint32_t count = osMessageQueueGetCount(Queue6Handle);
		if (count > 0) {
			osMessageQueueGet(Queue6Handle, &res, NULL, osWaitForever);
			if (res == '1') {
				application().gotoChooseTurnScreenScreenSlideTransitionEast();
			}
		}
	}

	if(increase)
	{
		currentValue++;
		boxProgress1.setValue(currentValue);
	}

}
