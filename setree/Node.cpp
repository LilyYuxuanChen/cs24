#include "Node.h"
#include <iostream>
using namespace std;


Node::Node(const std::string& val) {
	value = val;
	left = nullptr;
	right = nullptr;
	//count = 1;
}
/*
Node& operator = (const Node& other) {
	//delete 
}
*/
size_t Node::InsertNode(const std::string& val, Node* curr) {
	if (curr == nullptr) {
		curr = new Node(val);
		return 1;
	}
	else if (val < curr->value) {
		if(left == nullptr) {
			left = new Node(val);
			return 1;
		}
		else {
			return InsertNode(val, curr->left);
		}
	}
	else if (val > curr->value) {
		if (right == nullptr) {
			right = new Node(val);
			return 1;
		}
		else {
			return InsertNode(val, curr->right);
		}
		
	}
	else if (curr->value == val) {
		return 0;
	}
	else {
		return 5;
	}

}
void Node::PrintNode(Node* curr) {
	if(curr == nullptr) {
		return;
	}
	else if (curr->left == nullptr && curr->right == nullptr) {
		cout << curr->value;
		//return;
	}
	else if (curr->left == nullptr) {
		cout << "(- " << curr->value << " ";
		PrintNode(curr->right); 
		cout << ")";
	}
	else if (curr->right == nullptr) {
		cout << "(";
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

	/*
	else {
		cout << "(";
		if (curr->left == nullptr) {
			cout << "- ";
		}
		else {
			PrintNode(curr->left);
			cout << " ";
		}
		cout << curr->value;
		if (curr->right == nullptr) {
			cout << " -";
		}
		else {
			cout << " ";
			PrintNode(curr->right);
		}
		cout << ")";
		return;
	}
	*/
}
