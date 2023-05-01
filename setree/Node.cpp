#include "Node.h"
#include <iostream>
using namespace std;


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
	else {
		return 0;
	}
}
void Node::PrintNode(Node* curr) {
	if (left == nullptr && right == nullptr) {
		return;
	}
	else if (left == nullptr) {
		cout << "(- " << curr->value << " ";
		PrintNode(curr->right); 
		cout << ")";
	}
	else if (right == nullptr) {
		cout << "( ";
		PrintNode(curr->left);
		cout << " " << curr->value << " -)";
	}
	else {
		cout << "(";
	        PrintNode(curr->left);
	        cout << " " << curr->value << " ";
	        PrintNode(curr->right);
	        cout << ")";
	}
}
