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


Node::~Node() {
	//ClearN(this);
	//     delete left;
	//     delete right;
	left = nullptr;
	right = nullptr;
}


void Node::ClearN(Node* curr) {
	if (curr == nullptr) {
		return;
	}
//	else if (curr->left == nullptr && curr->right == nullptr) {
//		delete curr;
//		return;
//	}
	else {
		ClearN(curr->left);
		ClearN(curr->right);
		delete curr;
		return;
	}	
}

size_t Node::InsertNode(const std::string& val, Node*& curr) {
	if (curr == nullptr) {
		curr = new Node(val);
		return 1;
	}
/*
	else if (curr->value == val) {
		return 0;
	}
	else if (val < curr->value) {
		return InsertNode(val, curr);
	}
	else if (val > curr->value) {
		return InsertNode(val, curr);
	}
	else {
		return 5;
	}
*/
	else if (val < curr->value) {
		if(curr->left == nullptr) {
			curr->left = new Node(val);
			return 1;
		}
		else {
			return InsertNode(val, curr->left);
		}
	}
	else if (val > curr->value) {
		if (curr->right == nullptr) {
			curr->right = new Node(val);
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
size_t Node::countN(Node* curr) {
	if (curr == nullptr) {
		return 0;
	}
	if (curr->left == nullptr && curr->right == nullptr) {
		return 1;
	}
	else{
		return 1 + countN(curr->left) + countN(curr->right);
	}	
}

size_t cntR = 0;
Node* Node::lookupN(size_t n, Node* curr) {
	if (curr == nullptr) {
		throw std::out_of_range("");
	}
	if (n > countN(curr)) {
		throw std::out_of_range("");
	}
	else if (countN(curr->left) == n){
		return curr;
	}
	else if (n < countN(curr->left)) {
		//move to left
		return lookupN(n, curr->left);
	}
	else {
		//move to right
		
		return lookupN(n-countN(curr)-1, curr->right);
		
	}


}


Node* getLargestVal(Node*& curr) { 
	if (curr->right == nullptr) {
		return curr;
	}
	else {
		return getLargestVal(curr->right);
	}
}
size_t Node::rm(const std::string& val, Node*& curr) {
	if (curr == nullptr) {
		//reached end of tree without finding val
		return 0;
	}
	else if (val < curr->value) {
		return rm(val, curr->left);
	}
	else if (val > curr->value) {
		return rm(val, curr->right);
	}
	else {
		//found node
		if (curr->left == nullptr && curr->right == nullptr) {
			delete curr;
			curr = nullptr;
			return 1;
		}
		else if (curr->left == nullptr) {
			//only one child, on the right
			Node* temp = curr;
			curr = curr->right;
			curr->right = temp;
			temp = nullptr;
			delete curr->right;
			curr->right = nullptr;
			return 1;
		}
		else if (curr->right == nullptr) {
			//only one child on the left
			Node* temp = curr; 
			curr = curr->left;
			curr->left = temp;
			temp = nullptr;
			delete curr->left;
			curr->left = nullptr;
			return 1;
		}
		else {
			//two children
			Node* temp = curr;
			Node* largest = getLargestVal(curr->left);
			curr = largest;
			largest = temp;
			temp = nullptr;
			delete largest;
			largest = nullptr;
			return 1;


/*
			Node* largest = getLargestVal(curr->left);
			curr->value = largest->value;
			return rm(largest->value, curr);
*/
		}
/*		else {
			if (curr->left->value < val && curr->left->value > curr->right->value){ 
				//left child should replace curr
				return 1;
			}
			else{
				//right child should replace curr
				return 1;
			}
		}*/
	}
/*
	else {
//		size_t left = rm(val, curr->left);
//		size_t right = rm(val, curr->right);
//		return left + right;
		
		if (val < curr->value) {
			return rm(val, curr->left);
		}
		else {
			return rm(val,curr->right);
		}
		
	}
*/

}



			
//}
//

bool Node::contains(const std::string& val, Node* curr) const {
	if (curr == nullptr) {
		return false;
	}
//	else if (curr->left == nullptr && curr->right == nullptr) {
//		return false;
//	}
	else if (curr->value == val) {
		return true;
	}
	else if(contains(val, curr->left)){
		return true;
	}
	else if (contains(val, curr->right)){
		return true;
	}
	else {
		return false;
	}
	
}


