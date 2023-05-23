#include "Heap.h"
#include <iostream>
#include <stdexcept>

Heap::Heap(size_t capacity) {
	mCapacity = capacity;
	mCount = 0;
	mData = new Entry[capacity];

}
Heap::Heap(const Heap& other) {
	mCapacity = other.mCapacity;
	mCount = other.mCount;
	mData = new Entry[mCapacity];
	for (size_t i = 0; i < mCapacity; i++) {
		mData[i] = other.mData[i];
	}

}
Heap::Heap(Heap&& other) {
	mCapacity = other.mCapacity;
	mCount = other.mCount;
	mData = other.mData;
	other.mCapacity = 0;
	other.mCount = 0;
	other.mData = NULL;	

}

Heap::~Heap() {
	delete[] mData;
	mData = NULL;
}

size_t Heap::capacity() const {
	return mCapacity;
}

size_t Heap::count() const {
	return mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const {
	if (index >= mCount) {
		throw std::underflow_error("out of range");
	}
	else {
		return mData[index];
	}
}

Heap::Entry Heap::pop() {
/*	if (mCount == 0) {
		throw std::underflow_error("empty");
	}
	else {
		Entry r = mData[0];
		mData[0] = mData[mCount-1];
		mCount -= 1;
		size_t loc = 0;
		size_t left = 1;
		size_t right = 2;
		if (left < mCount && right < mCount) {
		while (mData[loc].score > mData[left].score || mData[loc].score > mData[right].score) {
			if (mData[loc].score > mData[left].score && mData[loc].score <= mData[right].score) {
				Entry temp;
				temp = mData[loc];
				mData[loc] = mData[left];
				mData[left] = temp;
				loc = left;
			}
			else if (mData[loc].score < mData[left].score && mData[loc].score >= mData[right].score){
				Entry temp;
				temp = mData[loc];
				mData[loc] = mData[right];
				mData[right] = temp;
				loc = right;
			}
			else {
				if (mData[left].score < mData[right].score) {
					Entry temp;
					temp = mData[loc];
					mData[loc] = mData[left];
					mData[left] = temp;
					loc = left;
				}
				else if (mData[left].score == mData[right].score) {
					Entry temp;
					temp = mData[loc];
					mData[loc] = mData[left];
					mData[left] = temp;
					loc = left;
				}
				else {
					Entry temp;
					temp = mData[loc];
					mData[loc] = mData[right];
					mData[right] = temp;
					loc = right;
				}
			}
			left = loc*2+1;
			right = loc*2+2;
			if (left >= mCount) {
				break;
			}
			else if (right >= mCount && left < mCount) {
				if (mData[loc].score < mData[left].score) {
					Entry temp;
					temp = mData[loc];
					mData[loc] = mData[left];
					mData[left] = temp;
					loc = left;
				}
				break;
			}
	}
	}
	else if (right >= mCount && left < mCount) {
	if (mData[loc].score < mData[left].score) {
	                                        Entry temp;
					                                        temp = mData[loc];
									                                        mData[loc] = mData[left];
													                                        mData[left] = temp;
																	                                        loc = left;
																					                                }	
	}
return r;
}*/
}
}

Heap::Entry Heap::pushpop(const std::string& value, float score) {
	Entry temp;
	return temp;
}

void Heap::push(const std::string& value, float score) {
	if (mCapacity < mCount +1) {
		throw std::overflow_error("no space");
	}
	else {
		Entry inp;
		inp.value = value;
		inp.score = score;
		mCount++;
		mData[mCount-1] = inp;
		size_t index = mCount-1;
		while(index != 0) {
			if (mData[(index-1)/2].score > score) {
				Entry temp;
				temp = mData[(index-1)/2];
				mData[(index-1)/2] = mData[index];
				mData[index] = mData[(index-1)/2];
				index = (index-1)/2;
			}
		}
	}
}

const Heap::Entry& Heap::top() const {
	if (mCount == 0) {
		throw std::underflow_error("no items in the heap");
	}
	else {
		return mData[0];
	}
}
