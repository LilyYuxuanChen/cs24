#ifndef NODE
#define NODE_H
#include <cstddef>
#include <string>
using namespace std;
// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.
class Node{
public:
	string value;
	Node* left;
	Node* right;
	size_t count;
		//Node();
		Node(const std::string& val);
		static size_t InsertNode(const std::string& val, Node*& curr);
		void PrintNode(Node* curr);
		size_t countN(Node* curr);
		bool contains(const std::string& val, Node* curr) const;
		~Node();
		void ClearN(Node* curr);
		size_t rm(const std::string& val, Node*& curr);
		const std::string& lookupN(size_t n, Node* curr);
		//Node (const Node& other);
		//int node() const;
	
		//Node(Node&& other); //move constructor

};
#endif
