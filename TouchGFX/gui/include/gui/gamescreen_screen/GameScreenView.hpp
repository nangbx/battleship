#ifndef GAMESCREENVIEW_HPP
#define GAMESCREENVIEW_HPP

#include <gui_generated/gamescreen_screen/GameScreenViewBase.hpp>
#include <gui/gamescreen_screen/GameScreenPresenter.hpp>
#include <vector>

class GameScreenView : public GameScreenViewBase
{
public:
    GameScreenView();
    virtual ~GameScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent();
    bool checkOutOfDesk(int32_t x, int32_t y, int16_t countBoat);
    bool checkAvailable(int32_t x, int32_t y, int16_t countBoat);
protected:
    uint8_t gameMode;
    int32_t x;
    int32_t y;
    int16_t countBoat;
    bool is_vertical;
    touchgfx::Container* currentBoat;
    touchgfx::Container* currentBoatR;
    std::vector<std::vector<int8_t>> desk =
    						{{0, 0, 0, 0, 0, 0, 0, 0, 0},
    					  {0, 0, 0, 0, 0, 0, 0, 0, 0},
						  {0, 0, 0, 0, 0, 0, 0, 0, 0},
						  {0, 0, 0, 0, 0, 0, 0, 0, 0},
						  {0, 0, 0, 0, 0, 0, 0, 0, 0},
						  {0, 0, 0, 0, 0, 0, 0, 0, 0},
						  {0, 0, 0, 0, 0, 0, 0, 0, 0},
						  {0, 0, 0, 0, 0, 0, 0, 0, 0},
						  {0, 0, 0, 0, 0, 0, 0, 0, 0},
						  {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
};

#endif // GAMESCREENVIEW_HPP
