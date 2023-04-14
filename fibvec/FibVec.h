#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

class FibVec {
  // Member Variables

  // Helper Functions
int* data;
size_t cap;
size_t cnt;

public:
  // Constructor and Destructor
FibVec();
~Fibvec();

// Member Functions
size_t capacity() const;
size_t count() const;
void insert(int val, size_t i);
int lookup(size_t i) const;
int pop();
void push(int val);
int remove(size_t i);

};

// Used by the autograder:
FibVec* create_fibvec();

#endif
