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

GenePool::~GenePool() {
	for (const auto& gene : genep) {
		delete gene->second;
	}
	genep.clear();
}

set<Person*> Genepool::everyone() const {
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
