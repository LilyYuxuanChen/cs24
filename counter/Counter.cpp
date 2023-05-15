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

int Counter::h(const std::string& key, int max) const {
	const unsigned int prime = 16777619;
	unsigned int hash = 2166136261;

	for (char c: key) {
		hash ^= c;
		hash *= prime;
	}
	return hash % max;
}

Node* Counter::find(const std::string& key) const{
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
				t = t->nc;
			}
		}
		return nullptr;
	}
}

Counter::Counter() {
	cnt = 0;
	cap = 5000;
	table = new Node*[5000]();
	ibegin = new Iterator();
	ibegin->i = nullptr;
	iend = new Iterator();
	iend->i = nullptr;
	ilast = new Iterator();
	ilast->i = nullptr;

}

Counter::~Counter() {
	delete ibegin;
	delete iend;
	delete ilast;
	for (int i = 0; i < cap; ++i) {
		if (table[i]  != NULL){
			Node* temp = table[i];
			Node* t2 = NULL;
			while (temp != NULL) {
				t2 = temp->ns;
				delete temp;
				temp = t2;
			}
		}
	}
	delete[] table;

}
int Counter::get(const std::string& input) const {
	Node* t = find(input);
	if (t == nullptr) {
		return 0;
	}
	else {
		return t->v;
	}
}
size_t Counter::count() const {
	size_t count = cnt;
	return count;
}
void Counter::resize() {
	int ncap = cap + cap;
	Node** ntable = new Node*[ncap]();
	Node* prev  = NULL;
	for (auto j = *ibegin; j != *iend; ++j) {
		int ind = h(j.i->k, ncap);
		Node* nn = new Node(j.i->k, j.i->v);
		if (ntable[ind] == NULL) {
			//Node* nn = new Node(j.i->k, j.i->v);
			if (prev == NULL) {
				ibegin->i = nn;
			}
			else {
				nn->ps = prev;
				prev->ns = nn;
			}
			prev = nn;
		}
		else {
			Node* k = ntable[ind];
			while (k != nullptr) {
				k = k->nc;
				if (k == NULL) {
					//Node* nn = new Node(j.i->k, j.i->v);
					k = nn;
					nn->ps = prev;
					prev->ns = nn;
					prev = nn;
					break;
				}
			

			}
			
		}
		if (j.i->ns == NULL) {
			ilast->i = nn;
		}
		//Node* 
		//delete j.i;
		//j.i = j.i->ns; //changed


	}
	for (int i = 0; i < cap; ++i) {
		if (table[i] != NULL) {
			Node* temp = table[i];
			Node* t2 = NULL;
			while (temp != NULL) {
				t2 = temp->ns;
				delete temp;
				temp = t2;
			}
		}
	}
	delete[] table;
	table = ntable;
	cap = ncap;


}

void Counter::set(const std::string& key, int count) {
	if ((static_cast<double>(cnt)/cap)>0.7) {
		resize();
	}
	if (cnt == 0) {
		int ind = h(key, cap);
		Node* nn = new Node(key,count);
		table[ind] = nn;
		ibegin->i = nn;
		ilast->i = nn;
		++cnt;
	}
	else {
		int ind = h(key,cap);
		Node* temp = find(key);
		if (temp == NULL) {
			Node*nn = new Node(key, count);
			if (table[ind] == NULL) {
				//Node* nn = new Node(key, count);
				table[ind] = nn;
				ilast->i->ns = nn;
				nn->ps = ilast->i;
				ilast->i = nn;
				cnt++;
			}
			else {
				Node* k = table[ind];
				while (k!= NULL) {
					if (k->nc == NULL) {
						k->nc = nn;
						nn->ps = k;
						k->ns = nn;
						ilast->i = nn;
						cnt++;
						break;
					}
					k = k->nc;
				}
			}

		}
		else {
			temp->v = count;
		}

	}
}

void Counter::inc(const std::string& key, int by) {
	//
}
void Counter::dec(const std::string& key, int by) {
	// 
}
void Counter::del(const std::string& key) {
	//
}


