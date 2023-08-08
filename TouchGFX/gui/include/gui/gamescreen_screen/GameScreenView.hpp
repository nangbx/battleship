#ifndef GAMESCREENVIEW_HPP
#define GAMESCREENVIEW_HPP

#include <gui_generated/gamescreen_screen/GameScreenViewBase.hpp>
#include <gui/gamescreen_screen/GameScreenPresenter.hpp>
#include <stm32f4xx.h>
#include <Board.hpp>
#include <Queue.hpp>


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
    void botHit(int32_t [][10]);
    bool checkWinner(int32_t board[][10]) {
    	for (int32_t i = 0; i < 10; i++) {
    		for (int32_t j = 0; j < 10; j++) {
    			if (board[i][j] > 0) {
    				return false;
    			}
    		}
    	}
    	return true;
    }

protected:
    uint8_t gameMode;
    int32_t x;
    int32_t y;
    Board gameBoard;
    Queue myq;
    int16_t countBoat;
    bool is_vertical;
    touchgfx::Container* currentBoat;
    touchgfx::Container* currentBoatR;
    int32_t desk[10][10];
	touchgfx::ScalableImage boxes[10][10];
	uint32_t tickCount;
	uint32_t currentCount;
    std::pair<int32_t, int32_t> hits[100];
    int32_t indexHit;
    bool isMultiPlayer;
    bool isGoFirst;
};

#endif // GAMESCREENVIEW_HPP
