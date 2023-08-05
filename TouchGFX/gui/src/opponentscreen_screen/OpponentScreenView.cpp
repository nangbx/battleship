#include <gui/opponentscreen_screen/OpponentScreenView.hpp>
#include <random>
#include <tuple>
#include <cmsis_os.h>
#include <images/BitmapDatabase.hpp>

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

}

void OpponentScreenView::setupScreen()
{
    OpponentScreenViewBase::setupScreen();
	x = 0;
	y = 0;
	OpponentDesk = presenter->getDesk();

	for (int i = 2; i <= 5; i++) {
		int x, y, direction;
		std::tie(x, y, direction) = randomIndexShip(board, i);
		if (i == 2) {
			switch (direction) {
			case DIRECTION::HORIZONTAL: {
				for (int j = 0; j < i; j++) {
					board[x + j][y] = i;
				}
				boat2_r.setXY(getXFromIndex(y), getYFromIndex(x));
				break;
			}
			case DIRECTION::VERTICAL: {
				for (int j = 0; j < i; j++) {
					board[x][y + j] = i;
				}
				boat2.setXY(getXFromIndex(y), getYFromIndex(x));
				break;
			}
			default: break;
			}
		}
		else if (i == 3) {
			switch (direction) {
			case DIRECTION::HORIZONTAL: {
				for (int j = 0; j < i; j++) {
					board[x + j][y] = i;
				}
				boat3_r.setXY(getXFromIndex(y), getYFromIndex(x));
				break;
			}
			case DIRECTION::VERTICAL: {
				for (int j = 0; j < i; j++) {
					board[x][y + j] = i;
				}
				boat3.setXY(getXFromIndex(y), getYFromIndex(x));
				break;
			}
			default: break;
			}
		}
		else if (i == 4) {
			switch (direction) {
			case DIRECTION::HORIZONTAL: {
				for (int j = 0; j < i; j++) {
					board[x + j][y] = i;
				}
				boat4_r.setXY(getXFromIndex(y), getYFromIndex(x));
				break;
			}
			case DIRECTION::VERTICAL: {
				for (int j = 0; j < i; j++) {
					board[x][y + j] = i;
				}
				boat4.setXY(getXFromIndex(y), getYFromIndex(x));
				break;
			}
			default: break;
			}
		}
		else if (i == 5) {
			switch (direction) {
			case DIRECTION::HORIZONTAL: {
				for (int j = 0; j < i; j++) {
					board[x + j][y] = i;
				}
				boat5_r.setXY(getXFromIndex(y), getYFromIndex(x));
				break;
			}
			case DIRECTION::VERTICAL: {
				for (int j = 0; j < i; j++) {
					board[x][y + j] = i;
				}
				boat5.setXY(getXFromIndex(y), getYFromIndex(x));
				break;
			}
			default: break;
			}
		}
	}

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(OpponentDesk[i][j] == 0)
			//if(board[i][j] == 0)
			{
				boxes[i][j].setBitmap(touchgfx::Bitmap(BITMAP_MISS_GRAY_ID));
			}
			else
			{
				boxes[i][j].setBitmap(touchgfx::Bitmap(BITMAP_HIT_ID));
			}
			boxes[i][j].setPosition(getXFromIndex(j), getYFromIndex(i), 23, 23);
			boxes[i][j].setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
			boxes[i][j].setVisible(false);
			add(boxes[i][j]);
		}
	}
}

void OpponentScreenView::tearDownScreen()
{
    OpponentScreenViewBase::tearDownScreen();
}
void OpponentScreenView::handleTickEvent() {
    OpponentScreenViewBase::handleTickEvent();
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
		if(res == 'S')
		{
			boxes[y][x].setVisible(true);
			//select.setVisible(false);

			//application().gotoGameScreenScreenSlideTransitionEast();
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
