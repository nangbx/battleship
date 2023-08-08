#include <gui/chooseturnscreen_screen/ChooseTurnScreenView.hpp>

ChooseTurnScreenView::ChooseTurnScreenView()
{

}

void ChooseTurnScreenView::setupScreen()
{
    ChooseTurnScreenViewBase::setupScreen();
}

void ChooseTurnScreenView::tearDownScreen()
{
    ChooseTurnScreenViewBase::tearDownScreen();
}

void ChooseTurnScreenView::btnFirstClicked()
{
	presenter->setIsGoFirst(true);
	application().gotoGameScreenScreenSlideTransitionEast();
}

void ChooseTurnScreenView::btnSecondClicked()
{
	presenter->setIsGoFirst(false);
	application().gotoGameScreenScreenSlideTransitionEast();
}
