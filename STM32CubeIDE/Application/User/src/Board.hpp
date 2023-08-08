/*
 * Board.hpp
 *
 *  Created on: Aug 6, 2023
 *      Author: nangb
 */

#ifndef APPLICATION_USER_SRC_BOARD_HPP_
#define APPLICATION_USER_SRC_BOARD_HPP_


#include <vector>
#include <random>

class Board
{
protected:
	 int32_t desk[10][10];
	 int32_t selected;
	 std::pair<int32_t, int32_t> queue[100];
	 int32_t top;
public:
	 const static int SIZE_BOARD = 10;
	 const static int HIT_VALUE = -1;
	 const static int MISS_VALUE = -2;
	 Board();
	 void Init();
	 void setSelected(int32_t);
	 void addShip();
	 void setDesk(int32_t (*)[10]);
	 
	 int getSelected();
	 std::pair<int32_t, int32_t> getHitBot();
};



#endif /* APPLICATION_USER_SRC_BOARD_HPP_ */
