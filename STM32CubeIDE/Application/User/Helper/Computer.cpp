#include <tuple>
#include <random>
#include "Computer.h"
#include "Utils.h"


std::tuple<int, int, int> Computer::randomIndexShip(int size_ship) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disIndex(0, 9);
	std::uniform_int_distribution<> disDirec(0, 1);
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
			case Orientation::VERTICAL: {
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
			case Orientation::HORIZONTAL: {
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

