#include "Node.h"

/*Node::Node(){
	value = NULL;
	left = nullptr;
	right = nullptr;
	//:count = 1;
}*/
Node::Node(const std::string& val) {
	value = val;
	left = nullptr;
	right = nullptr;
	//count = 1;
}
size_t Node::InsertNode(const std::string& value, Node* curr) {
	if (value < curr->value) {
		if(left == nullptr) {
			left = new Node(value);
			return 1;
		}
		else {
			return InsertNode(value, curr);
		}
	}
	else if (value > curr->value) {
		if (right == nullptr) {
			right = new Node(value);
			return 1;
		}
		else {
			return InsertNode(value, curr);
		}
		
	}
	else (value == curr->value) {
		return 0;
	}
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

