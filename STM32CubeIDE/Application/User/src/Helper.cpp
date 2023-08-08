/*
 * Helper.cpp
 *
 *  Created on: Aug 8, 2023
 *      Author: DONG DUY TIEN
 */
#include <stdint.h>

bool checkWinner(int32_t board[][10]) {
	for (int32_t i = 0; i < 10; i++) {
		for (int32_t j = 0; j < 10; j++) {
			if (board[i][j] > 0) {
				return false;
			}
		}
	}
	return true;
}

