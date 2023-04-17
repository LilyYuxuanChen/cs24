#include "FibVec.h"

// This provides exception types:
#include <stdexcept>


FibVec* create_fibvec() {
  // Used by the autograder to make a new FibVec.
  // You shouldn't need to change this.
  return new FibVec();
}


// FibVec Function Implementation
FibVec::FibVec(){
	data = new int[1];
	cap = 1;
	cnt = 0;
}

FibVec::~FibVec() {
	delete [] data;
}

size_t FibVec::capacity() const {
	return cap;
}

size_t FibVec::count() const {
	return cnt;
}
void FibVec::insert(int val, size_t i) {
	if (i > cnt) {
	throw std::out_of_range("Index out of range");
	}
	if (cnt >= cap)	{
		size_t new_cap = cap +(cap >> 1) +1;
		int* new_data = new int[new_cap];
		for (size_t j=0; j < i; j++) {
			new_data[j] = data[j];
		}
		new_data[i] = val;
		for (size_t j = i; j < cnt; j++) {
			new_data[j+1] = data[j];
		}
		delete[] data;
		data = new_data;
		cap = new_cap;
	}
	else {
		for (size_t j = cnt; j>i; j--) {
			data[j] = data[j-1];
		}
		data[i] = val;
	}
	cnt++;
}
int FibVec::lookup(size_t i) const {
	if (i >= cnt) {
		throw std::out_of_range("Index out of range");
	}
	return data[i];
}
int FibVec::pop() {
	int val = data[cnt-1];
	cnt--;
	if (cnt < cap - 2 && cap > 1) {
		size_t new_cap = cap >>1;
		int* new_data = new int[new_cap];
		for (size_t i = 0; i < cnt; i++) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		cap = new_cap;
	}
	return val;
	
}
void FibVec::push(int val) {
	insert(val, cnt);
}
int FibVec::remove(size_t i) {
	if (i >= cnt) {
		throw std::out_of_range("Index out of range");
	}
	int val = data[i];
	for (size_t j= i ; j< cnt -1; j++){
		data[j] = data[j+1];
	}
	cnt--;
	if (cnt < cap-2 && cap > 1) {
		size_t new_cap = cap >> 1;
		int* new_data = new int[new_cap];
		for (size_t j = 0; j < cnt; j++) {
			new_data[j] = data[j];
		}
		delete[] data;
		data = new_data;
		cap = new_cap;
	}
	return val;
	
}
