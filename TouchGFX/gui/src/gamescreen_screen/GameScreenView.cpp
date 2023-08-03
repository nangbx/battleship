#include <gui/gamescreen_screen/GameScreenView.hpp>
#include <cmsis_os.h>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

extern osMessageQueueId_t Queue1Handle;
extern osMessageQueueId_t Queue2Handle;
extern osMessageQueueId_t Queue3Handle;
extern osMessageQueueId_t Queue4Handle;
extern osMessageQueueId_t Queue5Handle;
extern osMessageQueueId_t Queue6Handle;


#define WIDTH_SQUARE 23
#define MIN_BOARD 0
#define MAX_BOARD 9
#define OUT_OF_BOARD_X -32
#define OUT_OF_BOARD_Y -68
int32_t getXFromIndex(int32_t);
int32_t getYFromIndex(int32_t);
void displayNameShip(int16_t);
GameScreenView::GameScreenView() {

}

void GameScreenView::setupScreen() {
	GameScreenViewBase::setupScreen();
	is_vertical = false;
	currentBoat = (touchgfx::Container*) &boat2;
	currentBoatR = (touchgfx::Container*) &boat2_r;
	countBoat = 1;
	x = 0;
	y = 0;
	gameMode = 0; // Dat thuyen
}

void GameScreenView::tearDownScreen() {
	GameScreenViewBase::tearDownScreen();
}
int32_t getXFromIndex(int32_t x) {
	return (5 + x * WIDTH_SQUARE);
}
int32_t getYFromIndex(int32_t y) {
	return (83 + y * WIDTH_SQUARE);
}
void GameScreenView::handleTickEvent() {
	GameScreenViewBase::handleTickEvent();
	uint8_t res = 0;
	uint32_t count1 = osMessageQueueGetCount(Queue1Handle);
	uint32_t count2 = osMessageQueueGetCount(Queue2Handle);
	uint32_t count3 = osMessageQueueGetCount(Queue3Handle);
	uint32_t count4 = osMessageQueueGetCount(Queue4Handle);
	uint32_t count5 = osMessageQueueGetCount(Queue5Handle);
	uint32_t count6 = osMessageQueueGetCount(Queue6Handle);

	// displayNameShip(countBoat);
	if (gameMode == 0) {
		switch (countBoat)
		{
		case 1: {
			Unicode::snprintf(textShipBuffer, TEXTSHIP_SIZE, "%s", touchgfx::TypedText(T_DESTROYER).getText());
			break;
		}
		case 2: {
			Unicode::snprintf(textShipBuffer, TEXTSHIP_SIZE, "%s", touchgfx::TypedText(T_CRUISER).getText());
			break;
		}
		case 3: {
			Unicode::snprintf(textShipBuffer, TEXTSHIP_SIZE, "%s", touchgfx::TypedText(T_BATTLESHIP).getText());
			break;
		}
		case 4: {
			Unicode::snprintf(textShipBuffer, TEXTSHIP_SIZE, "%s", touchgfx::TypedText(T_AIRCRAFT_CARRIER).getText());
			break;
		}
		default:
			break;
		}
		if (count1 > 0) {
			osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
			if (res == 'S') {
				if (checkAvailable(x, y, countBoat)) {
					if (is_vertical) {
						for (int i = 0; i <= countBoat; i++) {
							desk[x][y + i] = countBoat + 1;
						}
					}
					else {
						for (int i = 0; i <= countBoat; i++) {
							desk[x + i][y] = countBoat + 1;
						}
					}
					if (countBoat == 1) {
						x = 0;
						y = 0;
						boat3.setXY(getXFromIndex(x), getYFromIndex(y));
						currentBoat = (touchgfx::Container*)&boat3;
						currentBoatR = (touchgfx::Container*)&boat3_r;
					}
					if (countBoat == 2) {
						x = 0;
						y = 0;
						boat4.setXY(getXFromIndex(x), getYFromIndex(y));
						currentBoat = (touchgfx::Container*)&boat4;
						currentBoatR = (touchgfx::Container*)&boat4_r;
					}
					if (countBoat == 3) {
						x = 0;
						y = 0;
						boat5.setXY(getXFromIndex(x), getYFromIndex(y));
						currentBoat = (touchgfx::Container*)&boat5;
						currentBoatR = (touchgfx::Container*)&boat5_r;
					}
					if (countBoat == 4) {
						gameMode = 1;
					}
					if (countBoat <= 3) {
						countBoat++;
					}
				}

			}
			if (!is_vertical) {
				if (res == 'L') {
					x -= 1;
					if (x < MIN_BOARD) {
						x = MAX_BOARD - countBoat;
					}
					currentBoat->setX(getXFromIndex(x));
				}
				
			}
			else {
				if (res == 'L') {
					x -= 1;
					if (x < MIN_BOARD) {
						x = MAX_BOARD;
					}
					currentBoatR->setX(getXFromIndex(x));
				}
				

			}
		}
		if (count2 > 0) {
			osMessageQueueGet(Queue2Handle, &res, NULL, osWaitForever);
			if (!is_vertical) {
				if (res == 'R') {
					x += 1;
					if (x > MAX_BOARD - countBoat) {
						x = MIN_BOARD;
					}
					currentBoat->setX(getXFromIndex(x));
				}
			}
			else {
				if (res == 'R') {
					x += 1;
					if (x > MAX_BOARD) {
						x = MIN_BOARD;
					}
					currentBoatR->setX(getXFromIndex(x));
				}
			}
		}
		if (count3 > 0) {
			osMessageQueueGet(Queue3Handle, &res, NULL, osWaitForever);
			if (!is_vertical) {
				if (res == 'U') {
					y -= 1;
					if (y < MIN_BOARD) {
						y = MAX_BOARD;
					}
					currentBoat->setY(getYFromIndex(y));
				}
			}
			else {
				if (res == 'U') {
					y -= 1;
					if (y < MIN_BOARD) {
						y = MAX_BOARD - countBoat;
					}
					currentBoatR->setY(getYFromIndex(y));
				}
			}
		}
		if (count4 > 0) {
			osMessageQueueGet(Queue4Handle, &res, NULL, osWaitForever);
			if (!is_vertical) {
				if (res == 'D') {
					y += 1;
					if (y > MAX_BOARD) {
						y = MIN_BOARD;
					}
					currentBoat->setY(getYFromIndex(y));
				}
			}
			else {
				if (res == 'D') {
					y += 1;
					if (y > MAX_BOARD - countBoat) {
						y = MIN_BOARD;
					}
					currentBoatR->setY(getYFromIndex(y));
				}
			}
		}
		if (count5 > 0) {
			osMessageQueueGet(Queue5Handle, &res, NULL, osWaitForever);
			if (!is_vertical) {
				if (res == 'A') {
					if (checkOutOfDesk(x, y, countBoat)) {
						int16_t x = currentBoat->getX();
						int16_t y = currentBoat->getY();
						currentBoatR->setXY(x, y);
						currentBoat->setXY(OUT_OF_BOARD_X, OUT_OF_BOARD_Y);
						is_vertical = true;
					}
				}
			}
			else {
				if (res == 'A') {
					if (checkOutOfDesk(x, y, countBoat)) {
						int16_t x = currentBoatR->getX();
						int16_t y = currentBoatR->getY();
						currentBoat->setXY(x, y);
						currentBoatR->setXY(OUT_OF_BOARD_X, OUT_OF_BOARD_Y);
						is_vertical = false;
					}
				}
			}
		}
	}
	else if (gameMode == 1) {
		application().gotoOpponentScreenScreenSlideTransitionEast();
	}
	invalidate();
}
bool GameScreenView::checkOutOfDesk(int32_t x, int32_t y, int16_t countBoat) {
	if (is_vertical) {
		if (x + countBoat > MAX_BOARD) {
			return false;
		}
	} else {
		if (y + countBoat > MAX_BOARD) {
			return false;
		}
	}
	return true;
}

bool GameScreenView::checkAvailable(int32_t x, int32_t y, int16_t countBoat) {
	if (is_vertical) {
		for (int i = 0; i <= countBoat; i++) {
			if (desk[x][y + i] > 0) {
				return false;
			}
		}
	} else {
		for (int i = 0; i <= countBoat; i++) {
			if (desk[x + i][y] > 0) {
				return false;
			}
		}
	}
	return true;
}
