#include "Set.h"
#include <iostream>

// Use this file to test your Set class.
// This file won't be graded - do whatever you want.

int main() {
  Set set;
  
  //std::cout << "This program doesn't do anything interesting yet...\n";
set.insert("nu");
set.insert("mu");
set.insert("gamma");
set.insert("eta");

set.print();
set.remove("i");
set.print();

  return 0;
}
