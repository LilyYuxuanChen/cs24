#include "Counter.h"

// Counter Member Functions
Counter::Iterator Counter::begin() const{
	return *ibegin;
}
Counter::Iterator Counter::end() const{
	return *iend;
}

int Counter::total() const{
	int sum = 0;
	for(auto i = this->begin(); i != this->end(); ++i) {
		sum = sum + i.value();
	}
	return sum;
}

int Counter::h(const std::string& key, int max) {
	const unsigned int prime = 16777619;
	unsigned int hash = 2166136261;

	for (char c: input) {
		hash ^= c;
		hash *= prime;
	}
	return hash % max;
}

Node* find(const std::string& key) {
	int j = h(key, cap);
	if (table[j] == nullptr) {
		return nullptr;
	}
	else {
		Node* t = table[j];
		while (t != nullptr) {
			if (t->k == key){
				return t;
			}
			else {
				t = nc;
			}
		}
		return nullptr;
	}
}
