#include "RBTree.h"
#include <stddef.h>

template<class Key, class Value>
RBTree<Key,Value>::RBTree()
{
	this->count = 0;
	this->root = NULL;
}

template<class Key, class Value>
RBTree<Key,Value>::RBTree(Key key, Value value)
{
	this->count = 1;
	this->root = new RBTree::Node();
	this->root->key = key;
	this->root->value = value;
	this->root->color = BLACK;
}

template<class Key, class Value>
RBTree<Key,Value>::~RBTree()
{
	deleteAllNodes(root);
}

template<class Key, class Value>
void RBTree<Key,Value>::printInOrder()
{
	traverse(root,&printNodeData);
}

template<class Key, class Value>
void RBTree<Key,Value>::traverse(
		Node *node,
		void (*f)(Node*))
{
	if (node == NULL)
	{
		return;
	}

	traverse(node->left,f);
	(*f)(node);
	traverse(node->right,f);
}

template<class Key, class Value>
void RBTree<Key,Value>::deleteAllNodes(
		Node *node)
{
	if (node == NULL)
	{
		return;
	}

	deleteAllNodes(node->left);
	deleteAllNodes(node->right);
	delete node;
}

template<class Key, class Value>
void RBTree<Key,Value>::leftRotate(
		Node *x)
{
	Node *y;
	// y is right child
	y = x->right;
	if (y != NULL)
	{
		// set x's right child
		// to y's left child
		x->right = y->left;
		// if it exists
		if (y->left == NULL)
		{
			// let child know
			// its new parent
			y->left->parent = x;
		}
		// if root, y new root
		if (x->parent == NULL)
		{
			root = y;	
		}
		// if x was left of its parent
		else if ((x->parent->left) == x)
		{
			// make parent's left
			// point to y
			x->parent->left = y;	
		}
		else
		{
			x->parent->right = y;
		}
		// y->left is now x
		y->left = x;
		// x's parent is now y
		x->parent = y;
	}
}

template<class Key, class Value>
void RBTree<Key,Value>::rightRotate(
		Node *x)
{
	Node *y;
	// y is left child
	y = x->left;
	if (y != NULL)
	{
		// set x's left child
		// to y's right child
		x->left = y->right;
		// if it exists
		if (y->right == NULL)
		{
			// let child know
			// its new parent
			y->right->parent = x;
		}
		// if root, y new root
		if (x->parent == NULL)
		{
			root = y;	
		}
		// if x was left of its parent
		else if ((x->parent->left) == x)
		{
			// make parent's left
			// point to y
			x->parent->left = y;	
		}
		else
		{
			x->parent->right = y;
		}
		// y's right child is now x
		y->right = x;
		// x's parent is now y
		x->parent = y;
	}
}

template<class Key, class Value>
void RBTree<Key,Value>::insertCaseOne(
		Node *node)
{
	// node is nonexistent
	// ???
	// nothing to do
	if (node == NULL)
	{
		return;
	}

	if (node->parent == NULL)
	{
		node->color = BLACK;
	}
	else
	{
		return insertCaseTwo(node);
	}
}

template<class Key, class Value>
void RBTree<Key,Value>::insertCaseTwo(
		Node *node)
{	
	// node is nonexistent
	// ???
	// nothing to do
	if (node == NULL)
	{
		return;
	}

	if (node->parent->color == BLACK)
	{
		return;
	}

	return insertCaseThree(node);
}

template<class Key, class Value>
void RBTree<Key,Value>::insertCaseThree(
		Node *node)
{	
	// node is nonexistent
	// ???
	// nothing to do
	if (node == NULL)
	{
		return;
	}

	Node *grandparent;
	Node *uncle = UNCLE(node);

	if ((uncle != NULL) &&
		(uncle->color == RED))
	{
		grandparent = GRANDPARENT(node);
		uncle->color = BLACK;
		node->parent->color = BLACK;
		grandparent->color = RED;
		insertCaseOne(grandparent);
	}

	return insertCaseFour(node);
}

template<class Key, class Value>
void RBTree<Key,Value>::insertCaseFour(
		Node *node)
{	
	// node is nonexistent
	// ???
	// nothing to do
	if (node == NULL)
	{
		return;
	}
	
	Node *grandparent = GRANDPARENT(node);

	if ((node->parent->left == node) &&
		(node->parent == grandparent->right))
	{
		rightRotate(node->parent);
		node = node->right;
	}
	else if ((node->parent->right == NULL) &&
			 (node->parent == grandparent->left))
	{
		leftRotate(node->parent);
		node = node->left;
	}

	return insertCaseFive(node);
}

template<class Key, class Value>
void RBTree<Key,Value>::insertCaseFive(
		Node *node)
{	
	// node is nonexistent
	// ???
	// nothing to do
	if (node == NULL)
	{
		return;
	}
	
	Node *grandparent = GRANDPARENT(node);
	node->parent->color = BLACK;
	grandparent->color = RED;
	if (node->parent->left == node)
	{
		leftRotate(grandparent);
	}
	else
	{
		rightRotate(grandparent);
	}
}	

template<class Key, class Value>
void RBTree<Key,Value>::standardInsert(
		Node *node, Node *parent)
{
	// node is nonexistent
	if (node == NULL)
	{
		return;
	}

	if (parent == NULL)
	{
		parent = root;
	}

	if (parent->key > node->key)
	{
		if (parent->left == NULL)
		{
			parent->left = node;
		}
		else
		{
			standardInsert(node,parent->left);
		}
	}
	else
	{
		if (parent->right == NULL)
		{
			parent->right = node;
		}
		else
		{
			standardInsert(node,parent->right);
		}
	}

	return insertCaseOne(node);
}

template<class Key, class Value>
RBTree<Key,Value>::Node* RBTree<Key,Value>::search(
		Key key, Node* node)
{
	if (node == NULL)
	{
		return NULL;
	}

	if (node->key == key)
	{
		return node;
	}
	else if (node->key > key)
	{
		search(key,node->left);
	}
	else
	{
		search(key,node->right);
	}
}

template<class Key, class Value>
void RBTree<Key,Value>::insert(
		Key key, Value value)
{
	Node *node = new Node();
	++count;

	node->key = key;
	node->value = value;
	node->color = RED;
	
	return standardInsert(node);
}

template<class Key, class Value>
bool RBTree<Key,Value>::changeValue(
		Key key,Value value)
{
	Node *found = search(key, root);
	
	if (found == NULL)
	{
		return false;		
	}

	found->value = value;
	return true;
}

template<class Key, class Value>
Value RBTree<Key,Value>::getValue(Key key)
{
	return search(key, root)->value;
}

template<class Key, class Value>
bool RBTree<Key,Value>::isEmpty()
{
	return (count < 1);
}

template<class Key, class Value>
int RBTree<Key,Value>::getSize()
{
	return count;
}

