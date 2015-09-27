#ifndef CSC330_REDBLACK_TREE
#define CSC330_REDBLACK_TREE
#include <stddef.h>

template<class Key, class Value>
class BSTree
{
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

	// count of how many nodes
	int count;
	// root of tree
	Node *root;

	static void printNodeData(Node*);

	// standard binary search tree
	// insertion, calls above
	// cases in ord to ensure
	// the tree is balanced
	// in accordance with redblack
	// properties
	void standardInsert(Node*,Node*);

	// go through tree in order
	// and execute some callback
	void traverse(Node*,void(*f)(Node*));
	// go through tree to delete all
	// nodes
	void deleteAllNodes(Node*);

	Node* search(Key,Node*);

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

	bool isEmpty();
	int getSize();
};

#include "BSTree.tcc"
#endif

