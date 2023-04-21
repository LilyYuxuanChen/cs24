#include "Errors.h"
#include "Move.h"
#include <sstream>
#include <string>

using namespace std
// Space for implementing Move functions.

Move::Move(const std::string& input) {
	std::istringstream iss (input);
	iss >> number;
	iss >> player;
	player = toupper(player);
	string temp;
	iss >> temp;
	row = temp[0] - 'A';
	column = temp[1]- '0' +1;

}

std::ostream& operator << (std::ostream& stream, const Move& move) {
	stream << number << " " << player << " ";
	if (row ==0) {
		stream << "A";
	}
	else if (row ==1) {
		stream << "B";
	}
	else {
		stream << "C";
	}
	stream << column;
}
