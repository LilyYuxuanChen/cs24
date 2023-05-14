#include "DataStore.h"
#include <cstring>

using namespace std;
Node::Node(string key, int val, Node* nchain = nullptr, Node* pchain = nullptr, Node* nseq = nullptr, Node* pseq = nullptr) {
	k = key;
	v = val;
	nc = nchain;
	pc = pchain;
	ns = nseq;
	ps = pseq;	
}	
Node::~Node(){
	nc = nullptr;
	pc = nullptr;
	ns = nullptr;
	ps = nullptr;
}
	
	
