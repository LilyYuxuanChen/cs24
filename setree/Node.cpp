#include "Node.h"

Node::Node(){
	value = " ";
	left = nullptr;
	right = nullptr;
	count = 1;
}
Node::Node(string val) {
	value = val;
	left = nullptr;
	right = nullptr;
	count = 1;
}
/*

Node::Node(int v) {
	this->ptr = new int;
	this->ptr = v;
}
Node:~Node() {
	delete ptr;
}
Node::Node(Node&& other) {
	this->ptr = other.ptr.;
	other.ptr = nullptr;
}
*/

