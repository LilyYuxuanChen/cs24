#ifndef COUNTER_H
#define COUNTER_H
#include "DataStore.h"
#include <random>
#include <functional>
#include <cstddef>
#include <string>

// This is the Counter class you need to implement.
// It includes the Counter::Iterator as a nested class.
// If you want more space to implement helper classes,
// you can use the DataStore.* and Index.* files.

class Counter {
public:
  class Iterator {
    // Member Variables
  public:
	  Node* i;

  public:
    const std::string& key() const;
    int value() const;

    Iterator& operator ++ ();
    bool      operator == (const Iterator& other) const;
    bool      operator != (const Iterator& other) const;
  };

private:
  // Member Variable
  Node** table;
  int cap;
  int cnt;
  Iterator* ibegin;
  Iterator* ilast;
  Iterator* iend;
 

private:
  // Helper Functions
  void resize();
  int h(const std::string& key, int max) const;
  Node* find(const std::string& key) const;

public:
  Counter();
  ~Counter();

  size_t count() const;
  int    total() const;

  void inc(const std::string& key, int by = 1);
  void dec(const std::string& key, int by = 1);
  void del(const std::string& key);
  int  get(const std::string& key) const;
  void set(const std::string& key, int count);

  Iterator begin() const;
  Iterator end() const;
};

#endif
