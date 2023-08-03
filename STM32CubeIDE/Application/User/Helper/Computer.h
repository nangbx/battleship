#include "Game.h"
#include <tuple>
#pragma once

class Computer : public Game
{
public:
	Computer() : Game() {};
	int computerFire();
	void chooseRandomShips(int);
	std::tuple<int, int, int> randomIndexShip(int);
};