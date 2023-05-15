#include "DataStore.h"
#include <cstring>

using namespace std;
Node::Node(string key, int val) {
	k = key;
	v = val;
	nc = NULL;
	pc = NULL;
	ns = NULL;
	ps = NULL;	
}	
Node::~Node(){
	nc = nullptr;
	pc = nullptr;
	ns = nullptr;
	ps = nullptr;
}
	
	
