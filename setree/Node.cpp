#include "Node.h"

Node::Node(){
	value = " ";
	left = nullptr;
	right = nullptr;
	//:count = 1;
}
Node::Node(string val) {
	value = val;
	left = nullptr;
	right = nullptr;
	//count = 1;
}
/*

Node::Node(int v) {
	this->ptr = new int;
	this->ptr = v;
}*/

/*Node:~Node() {
	//delete ptr;
}
Node::Node(Node&& other) {
	this->value = other.value;
	this->left = other.left;
	this->right = other.right;
	//this->count = 1;
	other.ptr = nullptr;
}
*/
