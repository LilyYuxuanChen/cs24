#include "Set.h"
#include <cstddef>
#include <iostream>
using namespace std;

Set::Set() {
	mRoot = nullptr;
}
Node* myclone(const Node* node) {
	        if (node == nullptr) {
	                return nullptr;
	        }
	        else {
	                Node* newNode = new Node(node->value);
	                newNode->left = myclone(node->left);
	                newNode->right = myclone(node->right);
	                return newNode;
	        }
}

Set::Set(const Set& other) {
	//mRoot = other.mRoot;
	//mRoot->right = other->right;
	//mRoot = new Node();
	//*mRoot = other.mRoot;
	/*
	Node* mRoot = new Node(other.mRoot->value);
	mRoot->left = Set(other.mRoot->left);
	mRoot->right = Set(other.mRoot->right);
	*/
	mRoot = myclone(other.mRoot);
//	
//	mRoot = clone(other);	

}
/*
Node* myclone(const Node* node) {
	if (node == nullptr) {
		return nullptr;
	}
	else {
		Node* newNode = new Node(node->value);
		newNode->left = myclone(node->left);
		newNode->right = myclone(node->right);
		return newNode;
	}
}
*/
/*
Node* clone(const Set& other) {
	if (other.mRoot == nullptr) {
		return nullptr;
	}
	else {
		Node* newNode = new Node(other.mRoot->value);
		newNode->left = clone(Set(other.mRoot->left));
		newNode->right = clone(Set(other.mRoot->right));
		return newNode;
	}
}
*/
Set::Set(Set&& other) {
	mRoot = other.mRoot;
	//mRoot->right = other->right;
	//mRoot->value = other->value;
	//other->left = nullptr;
	other.mRoot = nullptr;

}
Set::~Set(){
	mRoot->ClearN(mRoot);
}

size_t Set::clear(){
	if (mRoot == nullptr) {
		return 0;
	}
	else {
	size_t n = count();
	mRoot->ClearN(mRoot);	
	mRoot = nullptr;
	return n;
	}
}

bool Set::contains(const std::string& value) const {
	if (mRoot == nullptr) {
		return false;
	}
	else {
		return mRoot->contains(value, mRoot);
	}
}
size_t Set::count() const {
	if (mRoot == nullptr) {
		return 0;
	}
	else {
		return mRoot->countN(mRoot);
	}
}
void Set::debug() {
}
size_t Set::insert(const std::string& value){
	if (mRoot == nullptr) {
		mRoot = new Node(value);
		return 1;
	}
	else {
		//return inserthelper(value, mRoot);
		//cout <<  mRoot->InsertNode(value, mRoot);
		return Node::InsertNode(value, mRoot);
	}
}
/*
size_t inserthelper(const std::string& value, Node* curr) {
	if (curr == nullptr) {
		curr = new Node(value);
		return 1;
	}
	else if (value == curr->value) {
		return 0;
	}
	else if (value < curr->value) {
		return inserthelper(value, curr->left);
	}
	else if (value > curr->value) {
		return inserthelper(value, curr->right);
	}
}
*/
const std::string EMPTY;
const std::string& Set::lookup(size_t n) const {
	Node* temp = mRoot->lookupN(n, mRoot);
	return temp->value;

}

void Set::print() const{
	if (mRoot == nullptr) {
		cout << "-" << endl;
	}
	else {
		mRoot->PrintNode(mRoot);
		cout << endl;
	}
}
size_t Set::remove(const std::string& value) {
	return mRoot->rm(value, mRoot);
}

