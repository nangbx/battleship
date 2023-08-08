/*
 * Board.cpp
 *
 *  Created on: Aug 6, 2023
 *      Author: nangb
 */



#include "Board.hpp"

Board::Board():desk({{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}),
	top(-1)
{
}

void Board::Init()
{
	this->selected = 2;
}
void Board::setSelected(int32_t boat){
	this->selected = boat;
}
void Board::setDesk(int32_t board[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->desk[i][j] = board[i][j];
		}
	}
}
int Board::getSelected(){
	return this->selected;
}

std::pair<int32_t, int32_t> Board::getHitBot() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disIndex(0, 9);

	int32_t x, y;
	if (this->top <= -1) {
		do {
			x = disIndex(gen);
			y = disIndex(gen);
		} while (this->desk[x][y] == -1);
	}
	else {
		std::pair<int, int> top = this->queue[this->top];
		x = top.first;
		y = top.second;
		this->top = this->top - 1;
	}
	if (this->desk[x][y] > 0) {
		if (x + 1 < 10) {
			if (this->desk[x + 1][y] > 0) {
				this->top += 1;
				this->queue[this->top] = std::make_pair(x, y + 1);
			}
		}
		if (y + 1 < 10) {
			if (this->desk[x][y + 1] > 0) {
				this->top += 1;
				this->queue[this->top] = std::make_pair(x, y + 1);
			}
		}
		if (x - 1 >= 0) {
			if (this->desk[x - 1][y] > 0) {
				this->top += 1;
				this->queue[this->top] = std::make_pair(x - 1, y);
			}
		}
		if (y - 1 >= 0) {
			if (this->desk[x][y - 1] > 0) {
				this->top += 1;
				this->queue[this->top] = std::make_pair(x, y - 1);
			}
		}
	}
	this->desk[x][y] = -1;
	return std::make_pair(x, y);
}

