#include <gui/gamescreen_screen/GameScreenView.hpp>
#include <cmsis_os.h>
#include <images/BitmapDatabase.hpp>

extern osMessageQueueId_t Queue1Handle;

#define WIDTH_SQUARE 23
#define MIN_BOARD 0
#define MAX_BOARD 9
#define OUT_OF_BOARD_X -32
#define OUT_OF_BOARD_Y -68
int32_t getXFromIndex(int32_t);
int32_t getYFromIndex(int32_t);
GameScreenView::GameScreenView()
{

}

void GameScreenView::setupScreen()
{
    GameScreenViewBase::setupScreen();
    is_vertical = false;
    currentBoat = (touchgfx::Container*)& boat2;
    currentBoatR = (touchgfx::Container*)& boat2_r;
    countBoat = 1;
    x = 0;
    y = 0;
}

void GameScreenView::tearDownScreen()
{
    GameScreenViewBase::tearDownScreen();
}
int32_t getXFromIndex(int32_t x){
	return (5 + x * WIDTH_SQUARE);
}
int32_t getYFromIndex(int32_t y){
	return (83 + y * WIDTH_SQUARE);
}
void GameScreenView::handleTickEvent(){
	GameScreenViewBase::handleTickEvent();
	uint8_t res = 0;
	uint32_t count = osMessageQueueGetCount(Queue1Handle);

	if(count > 0){
		osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
		if(res == 'S'){
			if(countBoat == 1){
				x = 0;
				y = 0;
				boat3.setXY(getXFromIndex(x), getYFromIndex(y));
				currentBoat = (touchgfx::Container*)& boat3;
				currentBoatR = (touchgfx::Container*)& boat3_r;
			}
			if(countBoat == 2){
				x = 0;
				y = 0;
				boat4.setXY(getXFromIndex(x), getYFromIndex(y));
				currentBoat = (touchgfx::Container*)& boat4;
				currentBoatR = (touchgfx::Container*)& boat4_r;
			}
			if(countBoat == 3){
				x = 0;
				y = 0;
				boat5.setXY(getXFromIndex(x), getYFromIndex(y));
				currentBoat = (touchgfx::Container*)& boat5;
				currentBoatR = (touchgfx::Container*)& boat5_r;
			}
			if(countBoat <= 3){
				countBoat++;
			}
		}
		if(!is_vertical){
			if(res == 'L'){
				x -= 1;
				if(x < MIN_BOARD){
					x = MAX_BOARD - countBoat;
				}
				currentBoat->setX(getXFromIndex(x));
			}
			if(res == 'R'){
				x += 1;
				if(x > MAX_BOARD - countBoat){
					x = MIN_BOARD;
				}
				currentBoat->setX(getXFromIndex(x));
			}
			if(res == 'U'){
				y -= 1;
				if(y < MIN_BOARD){
					y = MAX_BOARD;
				}
				currentBoat->setY(getYFromIndex(y));
			}
			if(res == 'D'){
				y += 1;
				if(y > MAX_BOARD){
					y = MIN_BOARD;
				}
				currentBoat->setY(getYFromIndex(y));
			}
			if(res == 'A'){
				int16_t x = currentBoat->getX();
				int16_t y = currentBoat->getY();
				currentBoatR->setXY(x, y);
				currentBoat->setXY(OUT_OF_BOARD_X, OUT_OF_BOARD_Y);
				is_vertical = true;
			}
		} else{
			if(res == 'L'){
				x -= 1;
				if(x < MIN_BOARD){
					x = MAX_BOARD;
				}
				currentBoatR->setX(getXFromIndex(x));
			}
			if(res == 'R'){
				x += 1;
				if(x > MAX_BOARD){
					x = MIN_BOARD;
				}
				currentBoatR->setX(getXFromIndex(x));
			}
			if(res == 'U'){
				y -= 1;
				if(y < MIN_BOARD){
					y = MAX_BOARD - countBoat;
				}
				currentBoatR->setY(getYFromIndex(y));
			}
			if(res == 'D'){
				y += 1;
				if(y > MAX_BOARD - countBoat){
					y = MIN_BOARD;
				}
				currentBoatR->setY(getYFromIndex(y));
			}
			if(res == 'A'){
				int16_t x = currentBoatR->getX();
				int16_t y = currentBoatR->getY();
				currentBoat->setXY(x, y);
				currentBoatR->setXY(OUT_OF_BOARD_X, OUT_OF_BOARD_Y);
				is_vertical = false;
			}
		}
	}
	invalidate();
}
