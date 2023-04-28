#include "Set.h"
#include <cstddef>


Set::Set() {
	mRoot = nullptr;
}

Set::Set(const Set& other) {

}
Set::Set(Set&& other) {

}
Set::~Set(){
	delete mRoot;
}

size_t Set::clear(){
	return 0;
}
bool Set::contains(const std::string& value) const {
	return false;
}
size_t Set::count() const {
	return 0;
}
void Set::debug() {
}
size_t Set::insert(const std::string& value){
	return 0;
}

const std::string EMPTY;
const std::string& Set::lookup(size_t n) const {
	return EMPTY;

}

void Set::print() const{

}
size_t Set::remove(const std::string& value) {
	return 0;
}

