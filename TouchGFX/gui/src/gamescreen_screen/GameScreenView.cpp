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
bool checkWinner(int32_t [][10]);
GameScreenView::GameScreenView() {
	tickCount = 0;
}

void GameScreenView::setupScreen() {
	GameScreenViewBase::setupScreen();
	is_vertical = false;
	currentBoat = (touchgfx::Container*) &boat2;
	currentBoatR = (touchgfx::Container*) &boat2_r;
	gameBoard.Init();
	// gameBoard.setSelected(2);
	x = 0;
	y = 0;
	presenter->getDesk(desk);
	std::pair<int, int> fire = presenter->getFire();
	if(fire.first >= 0 && fire.second >= 0){
		gameMode = 1;
		indexHit = presenter->getIndexHit();
		presenter->getHits(hits);
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				if (desk[i][j] == Board::HIT_VALUE)
				//if(board[i][j] == 0)
						{
					boxes[i][j].setBitmap(
							touchgfx::Bitmap(BITMAP_HIT_ID));
				} else if(desk[i][j] == Board::MISS_VALUE) {
					boxes[i][j].setBitmap(touchgfx::Bitmap(BITMAP_MISS_BLUE_ID));
				} else if (desk[i][j] > 0){
					if((i + 1 < 10 && desk[i + 1][j] == desk[i][j]) || (i - 1 >= 0 && desk[i - 1][j] == desk[i][j])){
						boxes[i][j].setBitmap(touchgfx::Bitmap(BITMAP_BOAT_ID));
					} else{
						boxes[i][j].setBitmap(touchgfx::Bitmap(BITMAP_BOAT2_ID));
					}
				}
				boxes[i][j].setPosition(getXFromIndex(j), getYFromIndex(i), 23,
						23);
				boxes[i][j].setScalingAlgorithm(
						touchgfx::ScalableImage::NEAREST_NEIGHBOR);
				add (boxes[i][j]);
			}
		}
	} else{
		gameMode = 0; // Dat thuyen
	}
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
	tickCount++;
	uint8_t res = 0;
	uint32_t count1 = osMessageQueueGetCount(Queue1Handle);
	uint32_t count2 = osMessageQueueGetCount(Queue2Handle);
	uint32_t count3 = osMessageQueueGetCount(Queue3Handle);
	uint32_t count4 = osMessageQueueGetCount(Queue4Handle);
	uint32_t count5 = osMessageQueueGetCount(Queue5Handle);
	uint32_t count6 = osMessageQueueGetCount(Queue6Handle);
	int selected = gameBoard.getSelected();
	// displayNameShip(countBoat);
	if (gameMode == 0) {
		switch (selected)
		{
		case 2: {
			Unicode::snprintf(textShipBuffer, TEXTSHIP_SIZE, "%s", touchgfx::TypedText(T_DESTROYER).getText());
			break;
		}
		case 3: {
			Unicode::snprintf(textShipBuffer, TEXTSHIP_SIZE, "%s", touchgfx::TypedText(T_CRUISER).getText());
			break;
		}
		case 4: {
			Unicode::snprintf(textShipBuffer, TEXTSHIP_SIZE, "%s", touchgfx::TypedText(T_BATTLESHIP).getText());
			break;
		}
		case 5: {
			Unicode::snprintf(textShipBuffer, TEXTSHIP_SIZE, "%s", touchgfx::TypedText(T_AIRCRAFT_CARRIER).getText());
			break;
		}
		default:
			break;
		}
		if (count1 > 0) {
			osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
			if (res == 'S') {
				if (checkAvailable(x, y, selected)) {
					if (is_vertical) {
						for (int i = 0; i <= selected - 1; i++) {
							presenter->setDesk(y + i, x, selected);
						}
					}
					else {
						for (int i = 0; i <= selected - 1; i++) {
							presenter->setDesk(y, x + i, selected);
						}
					}
					if (selected == 2) {
						x = 0;
						y = 0;
						boat3.setXY(getXFromIndex(x), getYFromIndex(y));
						currentBoat = (touchgfx::Container*)&boat3;
						currentBoatR = (touchgfx::Container*)&boat3_r;
						gameBoard.setSelected(selected + 1);
					} else if (selected == 3) {
						x = 0;
						y = 0;
						boat4.setXY(getXFromIndex(x), getYFromIndex(y));
						currentBoat = (touchgfx::Container*)&boat4;
						currentBoatR = (touchgfx::Container*)&boat4_r;
						gameBoard.setSelected(selected + 1);
					} else if (selected == 4) {
						x = 0;
						y = 0;
						boat5.setXY(getXFromIndex(x), getYFromIndex(y));
						currentBoat = (touchgfx::Container*)&boat5;
						currentBoatR = (touchgfx::Container*)&boat5_r;
						gameBoard.setSelected(selected + 1);
					} else if (selected == 5) {
						// HAL_Delay(5000);
						botHit(desk);
						presenter->setHits(hits);
						application().gotoOpponentScreenScreenSlideTransitionEast();
					}
				}

			}
			if (!is_vertical) {
				if (res == 'L') {
					x -= 1;
					if (x < MIN_BOARD) {
						x = MAX_BOARD - selected + 1;
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
					if (x > MAX_BOARD - selected + 1) {
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
						y = MAX_BOARD - selected + 1;
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
					if (y > MAX_BOARD - selected + 1) {
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
					if (checkOutOfDesk(x, y, selected - 1)) {
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
					if (checkOutOfDesk(x, y, selected - 1)) {
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

		// delay
		std::pair<int32_t, int32_t> hit = hits[indexHit];
		if(desk[hit.first][hit.second] > 0){
			presenter->setDesk(hit.first, hit.second, Board::HIT_VALUE);
		} else{
			presenter->setDesk(hit.first, hit.second, Board::MISS_VALUE);
		}
		presenter->setIndexHit(indexHit + 1);
		for(int i = 0; i < 3; i++){
			HAL_Delay(1000);
		}
		application().gotoOpponentScreenScreenSlideTransitionEast();
	}
	invalidate();
}
bool GameScreenView::checkOutOfDesk(int32_t x, int32_t y, int16_t countBoat) {
	presenter->getDesk(desk);
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
	presenter->getDesk(desk);
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

void GameScreenView::botHit(int32_t board[][10]) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disIndex(0, 9);
	int32_t x, y;
	int32_t index = 0;
	while (!checkWinner(board)) {
		if (myq.isEmpty()) {
			do {
				x = disIndex(gen);
				y = disIndex(gen);
			} while (board[x][y] == -1);
		}
		else {
			std::pair<int, int> top = myq.deQueue();
			x = top.first;
			y = top.second;
		}
		if (board[x][y] > 0) {
			if (x + 1 < 10) {
				if (board[x + 1][y] > 0) {
					myq.enQueue(std::make_pair(x + 1, y));
				}
			}
			if (y + 1 < 10) {
				if (board[x][y + 1] > 0) {
					myq.enQueue(std::make_pair(x, y + 1));
				}
			}
			if (x - 1 >= 0) {
				if (board[x - 1][y] > 0) {
					myq.enQueue(std::make_pair(x - 1, y));
				}
			}
			if (y - 1 >= 0) {
				if (board[x][y - 1] > 0) {
					myq.enQueue(std::make_pair(x, y - 1));
				}
			}
		}
		board[x][y] = -1;
		hits[index] = std::make_pair(x, y);
		index++;
	}

}
bool checkWinner(int32_t board[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] > 0) {
				return false;
			}
		}
	}
	return true;
}
