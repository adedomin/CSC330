#ifndef CSC330_REDBLACK_TREE
#define CSC330_REDBLACK_TREE
#include <stddef.h>
#include <vector>

template<class Key, class Value>
class Node
{
	public:
	// MUST OVERLOAD
	// < > ==
	// or be primitive
	Key key;
	Value value;
	
	Node *left;
	Node *right;
	Node *parent;
};


template<class Key, class Value>
class BSTree
{
	// count of how many nodes
	int count;
	// root of tree
	Node<Key,Value> *root;

	static void printNodeData(Node<Key,Value>*);

	// standard binary search tree
	// insertion, calls above
	// cases in ord to ensure
	// the tree is balanced
	// in accordance with redblack
	// properties
	void standardInsert(Node<Key,Value>*,Node<Key,Value>*);

	// go through tree in order
	// and execute some callback
	void traverse(Node<Key,Value>*,void(*f)(Node<Key,Value>*));
	void traverseToVector(Node<Key,Value>,std::vector<Node<Key,Value>>&);
	// go through tree to delete all
	// nodes
	void deleteAllNodes(Node<Key,Value>*);

	Node<Key,Value>* search(Key,Node<Key,Value>*);

	public:

	BSTree();
	// init with a root
	BSTree(Key, Value);
	~BSTree();

	void insertKey(Key, Value);
	void deleteKey(Key);
	bool changeValue(Key,Value);
	bool exists(Key);
	Value getValue(Key);

	void printInOrder();
	std::vector<Node<Key,Value>> toVector();

	bool isEmpty();
	int getSize();
};

#include "BSTree.tcc"
#endif

