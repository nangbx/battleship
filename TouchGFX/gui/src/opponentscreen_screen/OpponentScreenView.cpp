#include <gui/opponentscreen_screen/OpponentScreenView.hpp>
#include <random>
#include <tuple>
#include <cmsis_os.h>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

#define WIDTH_SQUARE 23
#define MIN_BOARD 0
#define MAX_BOARD 9
#define OUT_OF_BOARD_X -32
#define OUT_OF_BOARD_Y -68

extern osMessageQueueId_t Queue1Handle;
extern osMessageQueueId_t Queue2Handle;
extern osMessageQueueId_t Queue3Handle;
extern osMessageQueueId_t Queue4Handle;
extern osMessageQueueId_t Queue5Handle;
extern osMessageQueueId_t Queue6Handle;

enum DIRECTION {
	VERTICAL = 0,
	HORIZONTAL = 1,
};


std::tuple<int, int, int> randomIndexShip(int[][10], int);


OpponentScreenView::OpponentScreenView()
{
	tickCount = 0;
	currentCount = 0;
	for(int i = 0; i < 4; i++)
	{
		ship[i] = 0;
	}
}

void OpponentScreenView::setupScreen()
{
    OpponentScreenViewBase::setupScreen();
	x = 0;
	y = 0;
	gameMode = presenter->getGameMode();

	Unicode::snprintf(txtRemainShip1Buffer, TXTREMAINSHIP1_SIZE, "%s", touchgfx::TypedText(T_DESTROYER).getText());
	Unicode::snprintf(txtRemainShip2Buffer, TXTREMAINSHIP2_SIZE, "%s", touchgfx::TypedText(T_CRUISER).getText());
	Unicode::snprintf(txtRemainShip3Buffer, TXTREMAINSHIP3_SIZE, "%s", touchgfx::TypedText(T_BATTLESHIP).getText());
	Unicode::snprintf(txtRemainShip4Buffer, TXTREMAINSHIP4_SIZE, "%s", touchgfx::TypedText(T_AIRCRAFT_CARRIER).getText());

	if (gameMode == 0) {
		for (int i = 2; i <= 5; i++) {
			int x, y, direction;
			std::tie(x, y, direction) = randomIndexShip(board, i);
			if (i == 2) {
				switch (direction) {
				case DIRECTION::HORIZONTAL: {
					for (int j = 0; j < i; j++) {
						presenter->setDesk(x + j, y, i);
						board[x + j][y] = i;
					}
					boat2_r.setXY(getXFromIndex(y), getYFromIndex(x));
					break;
				}
				case DIRECTION::VERTICAL: {
					for (int j = 0; j < i; j++) {
						presenter->setDesk(x, y + j, i);
						board[x][y + j] = i;
					}
					boat2.setXY(getXFromIndex(y), getYFromIndex(x));
					break;
				}
				default:
					break;
				}
			} else if (i == 3) {
				switch (direction) {
				case DIRECTION::HORIZONTAL: {
					for (int j = 0; j < i; j++) {
						presenter->setDesk(x + j, y, i);
						board[x + j][y] = i;
					}
					boat3_r.setXY(getXFromIndex(y), getYFromIndex(x));
					break;
				}
				case DIRECTION::VERTICAL: {
					for (int j = 0; j < i; j++) {
						presenter->setDesk(x, y + j, i);
						board[x][y + j] = i;
					}
					 boat3.setXY(getXFromIndex(y), getYFromIndex(x));
					break;
				}
				default:
					break;
				}
			} else if (i == 4) {
				switch (direction) {
				case DIRECTION::HORIZONTAL: {
					for (int j = 0; j < i; j++) {
						presenter->setDesk(x + j, y, i);
						board[x + j][y] = i;
					}
					boat4_r.setXY(getXFromIndex(y), getYFromIndex(x));
					break;
				}
				case DIRECTION::VERTICAL: {
					for (int j = 0; j < i; j++) {
						presenter->setDesk(x, y + j, i);
						board[x][y + j] = i;
					}
					boat4.setXY(getXFromIndex(y), getYFromIndex(x));
					break;
				}
				default:
					break;
				}
			} else if (i == 5) {
				switch (direction) {
				case DIRECTION::HORIZONTAL: {
					for (int j = 0; j < i; j++) {
						presenter->setDesk(x + j, y, i);
						board[x + j][y] = i;
					}
					 boat5_r.setXY(getXFromIndex(y), getYFromIndex(x));
					break;
				}
				case DIRECTION::VERTICAL: {
					for (int j = 0; j < i; j++) {
						presenter->setDesk(x, y + j, i);
						board[x][y + j] = i;
					}
					boat5.setXY(getXFromIndex(y), getYFromIndex(x));
					break;
				}
				default:
					break;
				}
			}
		}
		presenter->setGameMode(1);
	}
	presenter->getDesk(desk);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if(desk[i][j] == 2)
			{
				ship[0]++;
			}
			else if(desk[i][j] == 3)
			{
				ship[1]++;
			}
			else if(desk[i][j] == 4)
			{
				ship[2]++;
			}
			else if(desk[i][j] == 5)
			{
				ship[3]++;
			}
			if (desk[i][j] == -2)
			{
				boxes[i][j].setBitmap(touchgfx::Bitmap(BITMAP_MISS_GRAY_ID));
			} else if(desk[i][j] == -1) {
				boxes[i][j].setBitmap(touchgfx::Bitmap(BITMAP_HIT_ID));
			}
			boxes[i][j].setPosition(getXFromIndex(j), getYFromIndex(i), 23, 23);
			boxes[i][j].setScalingAlgorithm(
					touchgfx::ScalableImage::NEAREST_NEIGHBOR);
			// boxes[i][j].setVisible(false);
			add (boxes[i][j]);
		}
	}
	for(int i = 0; i < 4; i++)
	{
		if (ship[0] == 0) {
			txtRemainShip1.setColor(
					touchgfx::Color::getColorFromRGB(255, 0, 0));
		}
		if (ship[1] == 0) {
			txtRemainShip2.setColor(
					touchgfx::Color::getColorFromRGB(255, 0, 0));
		}
		if (ship[2] == 0) {
			txtRemainShip3.setColor(
					touchgfx::Color::getColorFromRGB(255, 0, 0));
		}
		if (ship[3] == 0) {
			txtRemainShip4.setColor(
					touchgfx::Color::getColorFromRGB(255, 0, 0));
		}
	}
}

void OpponentScreenView::tearDownScreen()
{
    OpponentScreenViewBase::tearDownScreen();
}
void OpponentScreenView::handleTickEvent() {
    OpponentScreenViewBase::handleTickEvent();
    tickCount++;
	uint8_t res = 0;
	uint32_t count1 = osMessageQueueGetCount(Queue1Handle);
	uint32_t count2 = osMessageQueueGetCount(Queue2Handle);
	uint32_t count3 = osMessageQueueGetCount(Queue3Handle);
	uint32_t count4 = osMessageQueueGetCount(Queue4Handle);
	uint32_t count5 = osMessageQueueGetCount(Queue5Handle);
	uint32_t count6 = osMessageQueueGetCount(Queue6Handle);

	if (count1 > 0) {
		osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
		if (res == 'L') {
			x -= 1;
			if (x < MIN_BOARD) {
				x = MAX_BOARD;
			}
			select.setX(getXFromIndex(x));
		}
		if (res == 'S' && desk[y][x] >= 0) {
			boxes[y][x].setVisible(true);
			if(desk[y][x] > 0){
				if(desk[y][x] == 2)
				{
					ship[0]--;
					if(ship[0] == 0)
					{
						txtRemainShip1.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
					}
				}
				else if(desk[y][x] == 3)
				{
					ship[1]--;
					if(ship[1] == 0)
					{
						txtRemainShip2.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
					}
				}
				else if(desk[y][x] == 4)
				{
					ship[2]--;
					if(ship[2] == 0)
					{
						txtRemainShip3.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
					}
				}
				else if(desk[y][x] == 5)
				{
					ship[3]--;
					if(ship[3] == 0)
					{
						txtRemainShip4.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));						}
					}
				presenter->setDesk(y, x, -1);
				boxes[y][x].setBitmap(touchgfx::Bitmap(BITMAP_HIT_ID));
				presenter->getDesk(desk);
				if (OpponentScreenView::checkWinner(desk)) {
					presenter->setWinner(1);
					application().gotoEndGameScreenScreenSlideTransitionEast();
				}

			} else{
				presenter->setDesk(y, x, -2);
				boxes[y][x].setBitmap(touchgfx::Bitmap(BITMAP_MISS_GRAY_ID));
			}
			boxes[y][x].setPosition(getXFromIndex(x), getYFromIndex(y), 23, 23);
			boxes[y][x].setScalingAlgorithm(
					touchgfx::ScalableImage::NEAREST_NEIGHBOR);
			select.setVisible(false);
			if(currentCount == 0){
				currentCount = tickCount;
			}
		}
	}
	if(count2 > 0){
		osMessageQueueGet(Queue2Handle, &res, NULL, osWaitForever);
		if (res == 'R') {
			x += 1;
			if (x > MAX_BOARD) {
				x = MIN_BOARD;
			}
			select.setX(getXFromIndex(x));
		}
	}
	if (count3 > 0) {
		osMessageQueueGet(Queue3Handle, &res, NULL, osWaitForever);
		if (res == 'U') {
			y -= 1;
			if (y < MIN_BOARD) {
				y = MAX_BOARD;
			}
			select.setY(getYFromIndex(y));
		}
	}
	if (count4 > 0) {
		osMessageQueueGet(Queue4Handle, &res, NULL, osWaitForever);
		if (res == 'D') {
			y += 1;
			if (y > MAX_BOARD) {
				y = MIN_BOARD;
			}
			select.setY(getYFromIndex(y));
		}
	}
	if(currentCount != 0 && tickCount > currentCount + 15){
		application().gotoGameScreenScreenSlideTransitionEast();
	}
    invalidate();
}


std::tuple<int, int, int> randomIndexShip(int board[][10], int size_ship) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> disIndex(0, 9);
	std::uniform_int_distribution<int> disDirec(0, 1);

	int x, y;
	int direction;
	int status = -1;
	do {
		x = disIndex(gen);
		y = disIndex(gen);
		direction = disDirec(gen);
		for (int j = direction; j < direction + 1; j++) {
			int value = direction % 2;
			if (status != -1) {
				break;
			}
			switch (value) {
			case DIRECTION::VERTICAL: {
				bool check = true;
				if (y + size_ship < 10) {
					for (int i = 0; i < size_ship; i++) {
						if (board[x][y + i] != 0) {
							check = false;
							break;
						}
					}
				}
				else {
					check = false;
				}
				if (check) {
					status = value;
				}
				break;
			}
			case DIRECTION::HORIZONTAL: {
				bool check = true;
				if (x + size_ship < 10) {
					for (int i = 0; i < size_ship; i++) {
						if (board[x + i][y] != 0) {
							check = false;
							break;
						}
					}
				}
				else {
					check = false;
				}
				if (check) {
					status = value;
				}
				break;
			}
			default: break;
			}
		}
	} while (status == -1);
	return std::make_tuple(x, y, status);
}
int32_t OpponentScreenView::getXFromIndex(int32_t x) {
	return (5 + x * WIDTH_SQUARE);
}
int32_t OpponentScreenView::getYFromIndex(int32_t y) {
	return (83 + y * WIDTH_SQUARE);
}
