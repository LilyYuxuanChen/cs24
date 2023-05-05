#include "GenePool.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;
// GenePool Member Functions


GenePool::GenePool(std::istream& stream) {

	string ln;
	
	while (getline(stream, ln)){
		if (ln.empty()) {
			continue;
		}
		else if (ln[0] == "#") {
			continue;
		}
		std::istringstream iss (ln);
		string temp;
		vector <string> input;
		while(getline(iss, temp, '\t')) {
			input.pushback(temp);
		}
		
		Person* person = new Person(input[0],input[1]);
		genep.insert({input[0], person});
		if (input[2] != "???"){
			person->mom = genep.find(input[2])->second;
			person->mom->pchild.pushback(person);
		}
		if (input[3] != "???") {
			person->dad = genep.find(input[3])->second;
			person->dad->pchild.pushback(person);
		}

	}
}

