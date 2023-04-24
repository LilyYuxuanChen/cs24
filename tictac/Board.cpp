#include "Errors.h"
#include "Board.h"
#include <array>
using namespace std;
// Space for implementing Board functions.
Board::Board() :
	m_board{{
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
		
	}},
	m_currentPlayer('X'),
	m_numMoves(0)
{}

bool Board::isValidCoord(int row, int col) const{
	return (row >=0) && (row < 3) && (col >= 0) && (col < 3);
}

bool Board::hasPlayerWon(char player) const {
	for(int i = 0; i < 3; i++){
		if(m_board[i][0] == player && m_board[i][1] == player && m_board[i][2] == player){
			cout << "Game over: " << player << " wins." << endl;
			return true;
		}
		if(m_board[0][i] == player && m_board[1][i] == player && m_board[2][i] == player){
			cout << "Game over: " << player << " wins." << endl;
			return true;
		}
	}


	if(m_board[0][0] == player && m_board[1][1] == player && m_board[2][2] == player) {
		cout << "Game over: " << player << " wins." << endl;
		return true;
	}
	if(m_board[2][0] == player && m_board[1][1] == player && m_board[0][2] == player) {
		cout << "Game over: " << player << " wins." << endl;
		return true;
	
	}
	return false;
}

void Board::makeMove(const Move& move) {
	if(!isValidCoord(move.row, move.column)) {
		throw InvalidMove("Invalid coordinate");
	}
	if (m_board[move.row][move.column] != ' '){
		throw InvalidMove("Position is already occupied");
	}
	m_board[move.row][move.column] = m_currentPlayer;

	if(m_currentPlayer == 'X') {
		m_currentPlayer = 'O';
		cout << "Game in progress: O's turn." << endl;
	}
	else {
		m_currentPlayer = 'X';
		cout << "Game in progress: X's turn." << endl;

	}
	++m_numMoves;
}
char Board::getWinner() const {
	if (hasPlayerWon('X')) {
		return 'X';
	}
	else if (hasPlayerWon('O')) {
		return 'O';
	}
	else {
		return ' ';
	}

}

bool Board::isValidMove(const Move& move) const {
	if (!isValidCoord(move.row, move.column)) {
		return false;
	}
	if (m_board[move.row][move.column] != ' '){
		return false;
	}
	if (move.player != m_currentPlayer) {
		return false;
	}
	return true;
}
bool Board::isGameOver() const {
	if (hasPlayerWon('X') || hasPlayerWon('O')){
		return true;
	}

	if (m_numMoves == 9) {
		cout << "Game over: Draw." << endl;
		return true;
	}

	return false;
}

