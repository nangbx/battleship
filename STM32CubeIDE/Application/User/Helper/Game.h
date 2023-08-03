#include <vector>
#pragma once
class Game {
public: 
	Game() {
		board.resize(BOARD_SIZE, std::vector<int>(BOARD_SIZE));
	};

	static const int DESTROYER_SIZE = 2;
	static const int SUBMARINE_SIZE = 3;
	static const int BATTLESHIP_SIZE = 4;
	static const int CARRIER_SIZE = 5;
	const int SHIP_SIZES[4] = { DESTROYER_SIZE, SUBMARINE_SIZE, BATTLESHIP_SIZE, CARRIER_SIZE };

	static const int BOARD_SIZE = 10;
	std::vector<std::vector<int>> board;
private:
};
