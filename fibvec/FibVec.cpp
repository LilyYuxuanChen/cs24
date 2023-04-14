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
	
}
int FibVec::lookup(size_t i) const {
	return data[i];
}
int FibVec::pop() {
	int v = 0;
	return v;
}
void FibVec::push(int val) {

}
int FibVec::remove(size_t i) {
	return data[i];
}
