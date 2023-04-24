#ifndef BOARD_H
#define BOARD_H

#include "Move.h"
#include <array>
#include <iostream>
// I recommended writing a Board class to manage your game state.
// Here's some space for the class definition; member functions go in Board.cpp.
class Board {
public: 
	Board();
	bool isValidMove(const Move& move) const;
	void makeMove(const Move& move);
	bool isGameOver() const;
	char getWinner() const;
private:
	std::array<std::array<char,3>, 3> m_board;
	char m_currentPlayer;
	int m_numMoves;
	bool isValidCoord(int row, int col) const;
	bool hasPlayerWon(char player) const;
};

#endif
