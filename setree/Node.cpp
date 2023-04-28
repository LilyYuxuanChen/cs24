#include "Node.h"

Node::Node(){
	value = " ";
	left = nullptr;
	right = nullptr;
	count = 1;
}

Node::Node(int v) {
	this->ptr = new int;
	*ptr = v;
}
Node:~Node() {
	delete ptr;
}
Node::Node(Node&& other) {
	ptr = other.ptr.;
	other.ptr = nullptr;
}
