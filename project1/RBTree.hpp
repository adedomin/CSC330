#ifndef CSC330_REDBLACK_TREE
#define CSC330_REDBLACK_TREE
#include <stddef.h>

#define RED 'R'
#define BLACK 'B'

#define IS_RED(node) ( \
	node != NULL ? \
	node->color == RED : \
	NULL \
)

#define PARENT(node) ( \
	node != NULL ? \
	node->parent : \
	NULL \
)
#define GRANDPARENT(node) ( \
	PARENT(node) != NULL ? \
	PARENT(node)->parent : \
	NULL \
)
#define UNCLE(node) ( \
	GRANDPARENT(node) != NULL ? \
	(GRANDPARENT(node)->left == PARENT(node) ? \
	GRANDPARENT(node)->right : \
	GRANDPARENT(node)->left) : \
	NULL \
)
template<class Key, class Value>
class RBTree
{
	class Node
	{
		public:
		// MUST OVERLOAD
		// < > ==
		// or be primitive
		Key key;
		Value value;
		char color;
		
		Node *left;
		Node *right;
		Node *parent;
	};

	// count of how many nodes
	int count;
	// root of tree
	Node *root;

	static void printNodeData(Node*);

	// rotate subtree
	void leftRotate(Node*);
	void rightRotate(Node*);

	// insertion cases
	// makes sure nodes
	// are inserted and comply
	// with redblack tree
	//
	// CASE 1:
	// Newly inserted node may be root
	// being the first node in tree.
	// Make sure node is black
	// then exit
	void insertCaseOne(Node*);
	// CASE 2:
	// if new node's parent is black
	// then tree is ok
	// exit
	void insertCaseTwo(Node*);
	// CASE 3:
	// IF parent is red and
	// uncle is red
	// repaint them black
	// then call insertCaseOne
	// for grandparent
	// since this change can 
	// damage the redblack 
	// properties
	void insertCaseThree(Node*);	
	// CASE 4:
	// uncle may be black instead
	// parent and node are rotated
	// node and parent swap spaces
	void insertCaseFour(Node*);
	// CASE 5:
	// Parent of node is
	// still red. Node is also
	// red
	// uncle is still black
	// and grandparent is black
	// parent is painted black
	// grandparent is painted red
	// tree rotates around 
	// grandparent and parent
	// tree should be in order now
	void insertCaseFive(Node*);

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

	RBTree();
	// init with a root
	RBTree(Key, Value);
	~RBTree();

	void insert(Key, Value);
	bool changeValue(Key,Value);
	Value getValue(Key);

	void printInOrder();

	bool isEmpty();
	int getSize();
};

#include "RBTree.tcc"
#endif

