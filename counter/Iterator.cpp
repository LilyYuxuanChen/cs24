#include "Counter.h"

// Counter::Iterator Member Functions
const std:: string& Counter::Iterator::key() const {
	return i->k;
}
int Counter::Iterator::value() const {
	return i->v;
}
Counter::Iterator& Counter::Iterator::operator++ () {
	if (this->i != NULL) {
		this->i = this->i->ns;
	}
	return *this;
}
bool Counter::Iterator::operator == (const Iterator& other) const {
	return (this->i == other.i);
}
bool Counter::Iterator::operator != (const Iterator& other) const {
	return (this->i != other.i);
}
