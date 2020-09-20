/*
Solution for "Cracking the coding interview"
Exercise 16_3

Notes:
*/

#include <string>
#include <iostream>
#include <vector>
#include "stdint.h"

using namespace std;

typedef enum {
	slotUnchecked = 0,
	slotTic = 1,
	slotTac = 2
}Slot;

bool isWinBrute(Slot game[3][3], int dim) {
	/* brute force search */
	Slot cursor;

	bool winLine = false;
	int row = 0;
	int col = 0;

	/* search lines */
	for (row = 0; row < dim; row++) {
		cursor = game[row][0];
		for (col = 1; col < dim; col++) {
			if ((cursor == slotUnchecked) || (cursor != game[row][col]) || (game[row][col] == slotUnchecked)) {
				break;
			}
			cursor = game[row][col];
		}

		if (col == dim) {
			/* col==dim means we could iterate all slots without breaking -> line is win */
			return true;
		}
	}


	/* search columns */
	for (col = 0; col < dim; col++) {
		cursor = game[0][col];
		for (row = 1; row < dim; row++) {
			if ((cursor == slotUnchecked) || (cursor != game[row][col]) || (game[row][col] == slotUnchecked)) {
				break;
			}
			cursor = game[row][col];
		}

		if (row == dim) {
			/* col==dim means we could iterate all slots without breaking -> line is win */
			return true;
		}
	}

	/* search diagonals */
	cursor = game[0][0];
	row = 0;
	col = 0;
	while (row < dim) {
		row++;
		col++;
		if ((cursor == slotUnchecked) || (cursor != game[row][col]) || (game[row][col] == slotUnchecked)) {
			break;
		}
		cursor = game[row][col];
	}
	if (row == dim) {
		return true;
	}

	row = dim - 1;
	col = 0;
	while (row < dim) {
		row--;
		col++;
		if ((cursor == slotUnchecked) || (cursor != game[row][col]) || (game[row][col] == slotUnchecked)) {
			break;
		}
		cursor = game[row][col];
	}
	if (row == dim) {
		return true;
	}
	return false;
}


vector<int> rows, cols;

bool checkRow(Slot game[3][3], int dim, int row) {
	// return TRUE if row is a win
	// remove candidate cols if unchecked
	// remove row from rows if not win
}

bool checkCol(Slot game[3][3], int dim, int col) {
	// return TRUE if col is a win
	// remove candidate rows if unchecked
	// remove col from cols if not win
}

bool isWinOpt(Slot game[3][3], int dim) {

	for (int i = 0; i < dim; i++) {
		rows.push_back(i);
		cols.push_back(i);
	}

	int cursor[2] = {0,0};

	while (cursor[0] < dim) {
		if (find(rows.begin(), rows.end(), cursor[0]) != rows.end()) {
			if (checkRow(game, dim, cursor[0])) {
				return true;
			}
			if (find(cols.begin(), cols.end(), cursor[0]) != cols.end()) {
				if (checkCol(game, dim, cursor[1])) {
					return true;
				}
			}
		}
		cursor[0]++;
		cursor[1]++;
	}

	/* finally check diagonals */
}

int main() {
	Slot game1[3][3] = { {slotTic,slotTic,slotTic},{slotUnchecked,slotUnchecked,slotUnchecked},{slotUnchecked,slotUnchecked,slotUnchecked} };
	Slot game2[3][3] = { {slotUnchecked,slotUnchecked,slotTic},{slotUnchecked,slotUnchecked,slotTic},{slotUnchecked,slotUnchecked,slotTic} };
	Slot game3[3][3] = { {slotTic,slotUnchecked,slotUnchecked},{slotUnchecked,slotTic,slotUnchecked},{slotUnchecked,slotUnchecked,slotTic} };
	Slot game4[3][3] = { {slotTic,slotUnchecked,slotTic},{slotUnchecked,slotUnchecked,slotUnchecked},{slotUnchecked,slotUnchecked,slotUnchecked} };
	Slot game5[3][3] = { {slotUnchecked,slotUnchecked,slotTic},{slotUnchecked,slotUnchecked,slotTic},{slotUnchecked,slotUnchecked,slotUnchecked} };
	Slot game6[3][3] = { {slotTic,slotUnchecked,slotUnchecked},{slotUnchecked,slotUnchecked,slotUnchecked},{slotUnchecked,slotUnchecked,slotTic} };


	cout << "TicTacToe" << endl;

	cout << "game1 " << isWinBrute(game1, 3)<<endl;
	cout << "game2 " << isWinBrute(game2, 3)<<endl;
	cout << "game3 " << isWinBrute(game3, 3)<<endl;
	cout << "game4 " << isWinBrute(game4, 3)<<endl;
	cout << "game5 " << isWinBrute(game5, 3)<<endl;
	cout << "game6 " << isWinBrute(game6, 3)<<endl;



}

