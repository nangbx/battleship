#include <gui/endgamescreen_screen/EndGameScreenView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

EndGameScreenView::EndGameScreenView()
{

}

void EndGameScreenView::setupScreen()
{
    EndGameScreenViewBase::setupScreen();
    int32_t winner = presenter->getWinner();
    if(winner == 1)
    {
    	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", touchgfx::TypedText(T_PLAYER1).getText());
    }
    else
    {
    	Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", touchgfx::TypedText(T_PLAYER2).getText());
    }
    presenter->Init();
}

void EndGameScreenView::tearDownScreen()
{
    EndGameScreenViewBase::tearDownScreen();
}
