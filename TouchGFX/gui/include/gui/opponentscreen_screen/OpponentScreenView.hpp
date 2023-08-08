#ifndef OPPONENTSCREENVIEW_HPP
#define OPPONENTSCREENVIEW_HPP

#include <gui_generated/opponentscreen_screen/OpponentScreenViewBase.hpp>
#include <gui/opponentscreen_screen/OpponentScreenPresenter.hpp>
#include <stm32f4xx.h>


class OpponentScreenView : public OpponentScreenViewBase
{
public:
    OpponentScreenView();
    virtual ~OpponentScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
	void handleTickEvent();
	int32_t getXFromIndex(int32_t);
	int32_t getYFromIndex(int32_t);
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
	int board[10][10] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
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
	int8_t x;
	int8_t y;
	touchgfx::ScalableImage boxes[10][10];
	int32_t desk[10][10];
	int32_t tickCount;
	int32_t currentCount;
	int32_t ship[4];
	int32_t gameMode;

};

#endif // OPPONENTSCREENVIEW_HPP
