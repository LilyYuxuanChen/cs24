#include "Counter.h"

// Counter Member Functions
Counter::Iterator Counter::begin() const{
	return *ibegin;
}
Counter::Iterator Counter::end() const{
	return *iend;
}

int Counter::total() const{
	//int sum = 0;
	//for(auto i = this->begin(); i != this->end(); ++i) {
	//	sum = sum + i.value();
	//}
	return tot;
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
	tot = 0;
	cnt = 0;
	cap = 5;
	table = new Node*[5]();
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
				t2 = temp->nc;
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
	Node* begin = NULL;

	for (auto j = *ibegin; j != *iend; ++j) {
		int ind = h(j.i->k, ncap);
		Node* nn = new Node(j.i->k, j.i->v);
		if (ntable[ind] == NULL) {
			//Node* nn = new Node(j.i->k, j.i->v);
			if (prev == NULL) {
				begin = nn;
			}
			else {
				nn->ps = prev;
				prev->ns = nn;
			}
			ntable[ind] = nn;
			prev = nn;
		}
		else {
			Node* k = ntable[ind];
			while (k != nullptr) {
				Node* prevchain = k;
				k = k->nc;
				if (k == NULL) {
					//Node* nn = new Node(j.i->k, j.i->v);
					k = nn;
					k->pc = prevchain;
					prevchain->nc = k;
					k->ps = prev;
					prev->ns = k;
					prev = k;
					break;
				}
				//k = k->nc;
			

			}
			
		}
		if (j.i->ns == NULL) {
			ilast->i = nn;
		}
		//Node* 
		//delete j.i;
		//j.i = j.i->ns; //changed
	}
	ibegin->i = begin;
	
	for (int i = 0; i < cap; ++i) {
		if (table[i] != NULL) {
			Node* temp = table[i];
			Node* t2 = NULL;
			while (temp != NULL) {
				t2 = temp->nc;
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
	if ((static_cast<double>(cnt)/cap)>0.5) {
		resize();
	}
	if (cnt == 0) {
		int ind = h(key, cap);
		Node* nn = new Node(key,count);
		table[ind] = nn;
		ibegin->i = nn;
		ilast->i = nn;
		++cnt;
		tot += count;
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
				tot += count;
			}
			else {
				Node* k = table[ind];
				while (k!= NULL) {
					if (k->nc == NULL) {
						k->nc = nn;
						nn->pc = k;
						ilast->i->ns = nn;
						nn->ps = ilast->i;
						ilast->i = nn;
						cnt++;
						tot += count;
						break;
					}
					k = k->nc;
				}
			}

		}
		else {
			tot -= temp->v;
			temp->v = count;
			tot += count;
		}

	}
}

void Counter::inc(const std::string& key, int by) {
	Node* t = find(key);
	if (t == NULL) {
		set(key, by);
	}
	else {
		t->v += by;
		tot += by;
	}
}
void Counter::dec(const std::string& key, int by) {
	Node* t = find(key) ;
	if (t == NULL) {
		int temp = 0 - by;
		set(key, temp);
	}
	else {
		t->v -= by;
		tot -= by;
	}

}
void Counter::del(const std::string& key) {
	Node* t = find(key);
	if (t != NULL) {
		//t->v = 0;
		Node* prevchain = t->pc;
		Node* nextchain = t->nc;
		Node* prevseq = t->ps;
		Node* nextseq = t->ns;
		
		if (prevchain != NULL && nextchain != NULL) {
			 prevchain->nc = t->nc;
			 nextchain->pc = t->pc;
		}
		else if (prevchain == NULL && nextchain != NULL){
			string temp = t->k;
			int currind = h(temp, cap);
			table[currind] = t->nc;
			nextchain->pc = NULL;

		}
		else if (nextchain == NULL && prevchain != NULL) {
			prevchain->nc = NULL;
		}
		else {
			string temp = t->k;
			int currind = h(temp,cap);
			table[currind] = NULL;
		}
		

		if (prevseq != NULL && nextseq != NULL) {
			prevseq->ns = t->ns;
			nextseq->ps = t->ps;
		}
		else if (prevseq == NULL && nextseq !=NULL) {
			ibegin->i = t->ns;
			nextseq->ps = NULL;
		}
		else if (nextseq == NULL && prevseq != NULL) {
			ilast->i = t->ps;
			prevseq->ns = NULL;
		
		}
		else {
			ilast->i = NULL;
			ibegin->i = NULL;
		}
		cnt--;
		tot -= t->v;
		delete t;
	}

/*
		prevchain->nc = t->nc;
		nextchain->pc = t->pc;
		prevseq->ns = t->ns;
		nextseq->ps = t->ps;
*/
}


