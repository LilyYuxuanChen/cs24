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
	for (size_t i = 0; i < other.mCapacity; i++) {
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
		throw std::out_of_range("out of range");
	}
	else {
		return mData[index];
	}
}

Heap::Entry Heap::pop() {
	if (mCount == 0) {
		throw std::underflow_error("empty");
	}
	else {
		Entry ret = mData[0];
		if (mCount == 1) {
			//mData[0].value = "";
			//mData[0].score = 0;
			mCount = 0;
		}
		else {
			mData[0] = mData[mCount-1];
			//mData[mCount-1].value = "";
			//mData[mCount-1].score = "0";
			mCount--;
			size_t index = 0;
			while ((index * 2 +1) < mCount) {
				if ((index * 2 +2)>= mCount) {
					//one left child
					if (mData[index *2 +1].score >= mData[index].score) {
						break;
					}
					else {
						Entry temp = mData[index];
						mData[index] = mData[index*2+1];
						mData[index *2 +1] = temp;
						index = index*2+1;
					}
				}
				else {
					//two children
					if (mData[index*2+1].score >= mData[index].score && mData[index*2+2].score >= mData[index].score) {
						break;
					}
					else if (mData[index*2+1].score < mData[index].score && mData[index*2+2].score < mData[index].score) {
						if (mData[index*2+1].score > mData[index*2+2].score) {
							Entry temp = mData[index];
							mData[index] = mData[index*2+2];
							mData[index*2+2] = temp;
							index = index*2+2;
						}
						else {
							Entry temp = mData[index];
							mData[index] = mData[index*2+1];
							mData[index*2+1] = temp;
							index = index*2+1;
						}

					}
					else if (mData[index*2+1].score < mData[index].score){
						Entry temp = mData[index];
						mData[index] = mData[index*2+1];
						mData[index*2+1] = temp;
						index = index*2+1;
					}
					else {
						Entry temp = mData[index];
						mData[index] = mData[index*2+2];
						mData[index*2+2] = temp;
						index = index*2+2;
					}
				}
			}
		
		}
		return ret;
	}
	

/*
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

Heap::Entry Heap::pushpop(const std::string& value, float score) {

/*
if(mCount == 0) {
	throw std::underflow_error("empty");
}
else {
	Entry ret = mData[0];
	if (mCount == 1) {
		mData[0].value = value;
		mData[0].score = score;
	}
	else {
		mData[0].value = value;
		mData[0].score = score;
		size_t index = 0;
					while ((index * 2 +1) < mCount) {
										if ((index * 2 +2)>= mCount) {
																if (mData[index *2 +1].score >= mData[index].score) {
																							break;
																												}
																					else {
																												Entry temp = mData[index];
																																		mData[index] = mData[index*2+1];
																																								mData[index *2 +1] = temp;
																																														index = index*2+1;
																																																			}
																									}
														else {
																				if (mData[index*2+1].score >= mData[index].score && mData[index*2+2].score >= mData[index].score) {
																											break;
																																}
																									else if (mData[index*2+1].score < mData[index].score && mData[index*2+2].score < mData[index].score) {
																																if (mData[index*2+1].score > mData[index*2+2].score) {
																																								Entry temp = mData[index];
																																															mData[index] = mData[index*2+2];
																																																						mData[index*2+2] = temp;
																																																													index = index*2+2;
																																																																			}
																																						else {
																																														Entry temp = mData[index];
																																																					mData[index] = mData[index*2+1];
																																																												mData[index*2+1] = temp;
																																																																			index = index*2+1;
																																																																									}

																																											}
																														else if (mData[index*2+1].score < mData[index].score){
																																					Entry temp = mData[index];
																																											mData[index] = mData[index*2+1];
																																																	mData[index*2+1] = temp;
																																																							index = index*2+1;
																																																												}
																																			else {
																																										Entry temp = mData[index];
																																																mData[index] = mData[index*2+2];
																																																						mData[index*2+2] = temp;
																																																												index = index*2+2;
																																																																	}
																																							}
																	}
							
							}
			return ret;
	}







*/

	if (mCount != 0 && mCount < mCapacity) {
		mCount++;
		mData[mCount-1].value = value;
		mData[mCount-1].score = score;
		Entry ret = mData[0];
		pop();
		return ret;
	}
	else if (mCount == mCapacity) {
		Entry ret = mData[0];
		mData[0].value = value;
		mData[0].score = score;
					size_t index = 0;
								while ((index * 2 +1) < mCount) {
													if ((index * 2 +2)>= mCount) {
																			if (mData[index *2 +1].score >= mData[index].score) {
																										break;
																															}
																								else {
																															Entry temp = mData[index];
																																					mData[index] = mData[index*2+1];
																																											mData[index *2 +1] = temp;
																																																	index = index*2+1;
																																																						}
																												}
																	else {
																			
																							if (mData[index*2+1].score >= mData[index].score && mData[index*2+2].score >= mData[index].score) {
																														break;
																																			}
																												else if (mData[index*2+1].score < mData[index].score && mData[index*2+2].score < mData[index].score) {
																																			if (mData[index*2+1].score > mData[index*2+2].score) {
																																											Entry temp = mData[index];
																																																		mData[index] = mData[index*2+2];
																																																									mData[index*2+2] = temp;
																																																																index = index*2+2;
																																																																						}
																																									else {
																																																	Entry temp = mData[index];
																																																								mData[index] = mData[index*2+1];
																																																															mData[index*2+1] = temp;
																																																																						index = index*2+1;
																																																																												}

																																														}
																																	else if (mData[index*2+1].score < mData[index].score){
																																								Entry temp = mData[index];
																																														mData[index] = mData[index*2+1];
																																																				mData[index*2+1] = temp;
																																																										index = index*2+1;
																																																															}
																																						else {
																																													Entry temp = mData[index];
																																																			mData[index] = mData[index*2+2];
																																																									mData[index*2+2] = temp;
																																																															index = index*2+2;
																																																																				}
																																										}
																				}
										
									
		return ret;
	}
	else {
		throw std::underflow_error("k");


	}

}

void Heap::push(const std::string& value, float score) {
	if (mCapacity == mCount) {
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
				mData[index] = temp; 
				index = (index-1)/2;
			}
			else {
				break;
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
