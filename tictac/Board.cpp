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
	//return true;
	return (row >= 0) && (row < 3) && (col >= 0) && (col < 3);
}

bool Board::hasPlayerWon(char player) const {
	for(int i = 0; i < 3; i++){
		if(m_board[i][0] == player && m_board[i][1] == player && m_board[i][2] == player){
			//cout << "Game over: " << player << " wins." << endl;
			return true;
		}
		if(m_board[0][i] == player && m_board[1][i] == player && m_board[2][i] == player){
			//cout << "Game over: " << player << " wins." << endl;
			return true;
		}
	}


	if(m_board[0][0] == player && m_board[1][1] == player && m_board[2][2] == player) {
		//cout << "Game over: " << player << " wins." << endl;
		return true;
	}
	if(m_board[2][0] == player && m_board[1][1] == player && m_board[0][2] == player) {
		//cout << "Game over: " << player << " wins." << endl;
		return true;
	
	}
	return false;
}

void Board::makeMove(const Move& move) {	
	if(!isValidCoord(move.row-1, move.column-1)) {
		throw InvalidMove("Invalid coordinate");
	}
	if (m_board[move.row-1][move.column-1] != ' '){
		throw InvalidMove("Position is already occupied");
	}
	if (move.number != m_numMoves+1) {
		throw InvalidMove("invalid move number");
	}
	m_board[move.row-1][move.column-1] = move.player;
	if (move.number != 1 && move.player == m_currentPlayer) {
		throw InvalidMove("invalid player");
	}
	m_currentPlayer = move.player; 
	
	//if(m_currentPlayer == 'X') {
	//	m_currentPlayer = 'O';
		//cout << "Game in progress: O's turn." << endl;
	//}
	//else {
	//	m_currentPlayer = 'X';
		//cout << "Game in progress: X's turn." << endl;

	//}
	++m_numMoves;
	//cout << m_numMoves << endl;
	
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
/*
bool Board::isValidMove(const Move& move) const {
	if (!isValidCoord(move.row, move.column)) {
		cout << "invalid coordinate" << endl;
		return false;
	}
	if (m_board[move.row][move.column] != ' '){
		cout << "space taken" << endl;
		return false;
	}
	if (move.player != m_currentPlayer) {
		cout << "invalid player" << endl;
		return false;
	}
	if (move.number != m_numMoves) {
		cout << "invalid move number" << endl;
		return false;
	}

	return true;
}
*/
bool Board::isGameOver() const {
	if (hasPlayerWon('X') || hasPlayerWon('O')){
		return true;
	}

	if (m_numMoves == 9) {
		//cout << "Game over: Draw." << endl;
		return true;
	}

	return false;
}

void Board::PrintGameResult() const {
	if (hasPlayerWon('X')){
		        cout << "Game over: X wins." << endl;
	}
	else if (hasPlayerWon('O')){
		        cout << "Game over: O wins." << endl;
	}
	else if (m_numMoves == 8) {
		        cout << "Game over: Draw." << endl;
	}
	else if (m_numMoves ==0) {
		cout << "Game in progress: New game." << endl;
	}
	else if (m_currentPlayer == 'X') {
		        cout << "Game in progress: O's turn." << endl;
	}
	else if (m_currentPlayer == 'O') {
		        cout << "Game in progress: X's turn." << endl;
	}
	else {
		        cout << "Game in progress: New game." << endl;
	}
}

