#ifndef DATASTORE_H
#define DATASTORE_H
#include <string>
// Space to implement a separate datastore class, if you choose to do so.
// This can make things simpler by clearly separating functionality.
// The DataStore is in charge of storing pairs in insertion order.

using namespace std;
// DataStore Member Functions
// class kv{
// public:
//         string k;
//                 int v;
//                         Node* nc;
//                                 Node* pc;
//                                         Node* ns;
//                                                 Node* ps;
//
//                                                         kv(string k, int v, Node* nc = nullptr, Node* pc = nullptr, Node* ns = nullptr, Node* ps = nullptr);
//                                                                 ~kv();
//                                                                 
//

class Node{
public:
	string k;
	int v;
	Node* nc;
	Node* pc;
	Node* ns;
	Node* ps;

	Node(string key, int val);
	~Node();
};
#endif
