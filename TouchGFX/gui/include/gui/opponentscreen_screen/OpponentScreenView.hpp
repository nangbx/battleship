#ifndef OPPONENTSCREENVIEW_HPP
#define OPPONENTSCREENVIEW_HPP

#include <gui_generated/opponentscreen_screen/OpponentScreenViewBase.hpp>
#include <gui/opponentscreen_screen/OpponentScreenPresenter.hpp>
#include <vector>

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

	std::vector<std::vector<int8_t>> OpponentDesk;
};

#endif // OPPONENTSCREENVIEW_HPP
