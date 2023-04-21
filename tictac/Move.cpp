#include "Errors.h"
#include "Move.h"
#include <sstream>
#include <string>
#include <cctype>

using namespace std;
// Space for implementing Move functions.

Move::Move(const std::string& input) {
	std::istringstream iss (input);
	string temp;
	if (input.size()==0){
		throw ParseError("Empty String");
	}
	if (isspace(input[0])) {
		throw ParseError("starts with space");
	}

	if (!(iss >> temp)){
		throw ParseError("no number");
	}
	else if (temp.size() != 1){
		throw ParseError("wrong size for number");
	}
	else if ((temp < "1") || (temp > "9")) {
		throw ParseError("number out of range");
	}
	else {
		number = temp[0]-'0';
	}

	if (!(iss >> temp)){
		throw ParseError("no player");
	}
	else if (temp.size() != 1) {
		throw ParseError("wrong size for player");
	}
	else if ((toupper(temp[0]) != 'X') && (toupper(temp[0]) != 'O')){
		throw ParseError("player not X or O");
	}
	else {
		player = toupper(temp[0]);
	}

	if (!(iss >> temp)){
		throw ParseError("no row/column");
	}
	else if (temp.size() != 2) {
		throw ParseError("wrong size for row/column");
	}
	else if (((toupper(temp[0])-'A')!= 0) && ((toupper(temp[0])-'A')!=1) && ((toupper(temp[0])-'A')!=2)){
		throw ParseError("invalid row");
	}
	else if (((temp[1]-'0')!= 1) && ((temp[1]-'0')!= 2) && ((temp[1]-'0')!= 3)){
		throw ParseError("invalid column");
	}
	else {
		row = toupper(temp[0]) -'A' +1;
		column = temp[1] -'0';
	}

	if (iss >> temp) {
		if (temp[0] != '#'){
			throw ParseError("invalid comment");
		}
	}



/*
	iss >> number;
	if ((number < 1) || (number > 9)){
		throw ParseError("invalid number");
	}
	iss >> player;
	player = toupper(player);
	if ((player != "X") || (player != "O"))
	string temp;
	iss >> temp;
	row = temp[0] - 'A';
	column = temp[1]- '0' +1;
*/
}

std::ostream& operator << (std::ostream& stream, const Move& move) {
	stream << move.number << " " << move.player << " ";
	if (move.row ==1) {
		stream << "A";
	}
	else if (move.row ==2) {
		stream << "B";
	}
	else {
		stream << "C";
	}
	stream << move.column;
	return stream;
}
