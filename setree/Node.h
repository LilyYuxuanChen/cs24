#ifndef NODE
#define NODE_H
#include <cstddef>
#include <cstring>
using namespace std;
// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.
class Node{
		string value;
		Node* left;
		Node* right;
		size_t count;
	public:
		Node();
		Node(string val);
		~Node();
		Node (const Node& other);
		int node() const;
	
		Node(Node&& other); //move constructor

};
#endif
