#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <vector>

#include "matrix.h"

using namespace std;

class chessBoard {
public:
	chessBoard();
	void setQueens(const vector<int> &queenList);
	void clearBoard();
	void drawBoard() const;

private:
	matrix<bool> board;
};

// Constructor. initialize board to blanks
chessBoard::chessBoard() :
		board(8, 8) {
	clearBoard();
}

// Assign queens at locations (queenList[col],col), 0 <= col < 8
void chessBoard::setQueens(const vector<int> &queenList) {
	clearBoard();

	for (int col = 0; col < 8; col++)
		board[queenList[col]][col] = true;
}

void chessBoard::clearBoard() {
	int i, j;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			board[i][j] = false;
}

// draw the chess board
void chessBoard::drawBoard() const {
	int i, j;

	cout << "   0 1 2 3 4 5 6 7" << endl;
	for (i = 0; i < 8; i++) {
		cout << i << " ";

		for (j = 0; j < 8; j++) {
			if (board[i][j] == true)
				cout << " Q";
			else
				cout << " -";
		}
		cout << endl;
	}
}

#endif	// CHESSBOARD_H
