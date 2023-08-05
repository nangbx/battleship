#include <gui/homescreen_screen/HomeScreenView.hpp>
#include <cmsis_os.h>

extern osMessageQueueId_t Queue1Handle;

HomeScreenView::HomeScreenView()
{

}

void HomeScreenView::setupScreen()
{
    HomeScreenViewBase::setupScreen();

}

void HomeScreenView::tearDownScreen()
{
    HomeScreenViewBase::tearDownScreen();
}

void HomeScreenView::handleTickEvent()
{
	HomeScreenViewBase::handleTickEvent();
	uint8_t res = 0;
	uint32_t count1 = osMessageQueueGetCount(Queue1Handle);
	if (count1 > 0) {
		osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
		if (res == 'S') {
			application().gotoGameScreenScreenSlideTransitionEast();
		}

	}

	invalidate();
}
