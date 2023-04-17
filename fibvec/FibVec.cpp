#include "FibVec.h"
#include <cmath>
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

size_t FibVec::fib(size_t n) {
	if (n == 1) {
		return 1;
	}
	else {
		size_t a = 0;
		size_t b = 1;
		size_t c = 0;
		for (size_t j = 2; j <= n ; j++) {
			c = a+b;
			a =b;
			b=c;
		}
		return a;
		
	}
	
}
size_t FibVec::get_fibindex(size_t num) {
	const double phi = (1+sqrt(5))/2;
	return round(log(phi*num)/log(1.618));
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
		size_t new_cap = cap + fib(get_fibindex(cap)+1);
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
	if (get_fibindex(cap) > 1 && cnt <= fib(get_fibindex(cap)-2)) {
		size_t new_cap = fib(get_fibindex(cap)-1);
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
	
	if (cnt>cap) {
		cap = cap + fib(get_fibindex(cap)+1);
	}

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
	if (get_fibindex(cap)> 1 && cnt < fib(get_fibindex(cap)-2)){
		size_t new_cap = fib(get_fibindex(cap)-1);
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
