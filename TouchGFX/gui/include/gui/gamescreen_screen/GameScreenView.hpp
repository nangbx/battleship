#ifndef GAMESCREENVIEW_HPP
#define GAMESCREENVIEW_HPP

#include <gui_generated/gamescreen_screen/GameScreenViewBase.hpp>
#include <gui/gamescreen_screen/GameScreenPresenter.hpp>

class GameScreenView : public GameScreenViewBase
{
public:
    GameScreenView();
    virtual ~GameScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent();
protected:
    int32_t x;
    int32_t y;
    int16_t countBoat;
    bool is_vertical;
    touchgfx::Container* currentBoat;
    touchgfx::Container* currentBoatR;
};

#endif // GAMESCREENVIEW_HPP