#include "GenePool.h"
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "Person.h"

using namespace std;
// GenePool Member Functions


GenePool::GenePool(std::istream& stream) {

	string ln;
	
	while (getline(stream, ln)){
		if (ln.empty()) {
			continue;
		}
		else if (ln[0] == '#') {
			continue;
		}
		std::istringstream iss (ln);
		string temp;
		vector <string> input;
		while(getline(iss, temp, '\t')) {
			input.push_back(temp);
		}
		
		Person* person = new Person(input[0],input[1]);
		genep.insert({input[0], person});
		if (input[2] != "???"){
			person->mom = genep.find(input[2])->second;
			person->mom->pchild.push_back(person);
		}
		if (input[3] != "???") {
			person->dad = genep.find(input[3])->second;
			person->dad->pchild.push_back(person);
		}

	}
}

GenePool::~GenePool() {
	for (auto& [n, p] : genep) {
		delete p;
	}
	genep.clear();
}

set<Person*> GenePool::everyone() const {
	set<Person*> population;
	for (auto& [n, p] : genep) {
		population.insert(p);
	}
	return population;
}
Person* GenePool::find(const string& name) const {
	if (genep.find(name) != genep.end()) {
		return genep.find(name)->second;
	}
	else {
		return nullptr;
	}
}
