#ifndef ENDGAMESCREENVIEW_HPP
#define ENDGAMESCREENVIEW_HPP

#include <gui_generated/endgamescreen_screen/EndGameScreenViewBase.hpp>
#include <gui/endgamescreen_screen/EndGameScreenPresenter.hpp>

class EndGameScreenView : public EndGameScreenViewBase
{
public:
    EndGameScreenView();
    virtual ~EndGameScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:

};

#endif // ENDGAMESCREENVIEW_HPP
