#define DEBUG 1
#include <stddef.h>
#include <iostream>

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
void RBTree<Key,Value>::printNodeData(
		Node *node)
{
	std::cout << "Key:   " << node->key
			  << '\n'
			  << "Value: " << node->value
			  << '\n'
			  << "Color: " << node->color
			  << '\n';
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
		Node *root)
{
	Node *pivot = root->right;
	if (pivot != NULL)
	{
		root->right = pivot->left;
		if (root->right != NULL)
		{
			root->right->parent = root;
		}
		pivot->left = root;

		if (root->parent == NULL)
		{
			root->parent = pivot;
			pivot->parent = NULL;
		}
		else if (root->parent->left == root)
		{
			pivot->parent = root->parent;
			pivot->parent->left = pivot;
			root->parent = pivot;
		}
		else
		{
			pivot->parent = root->parent;
			pivot->parent->right = pivot;
			root->parent = pivot;
		}
	}
}
template<class Key, class Value>
void RBTree<Key,Value>::rightRotate(
		Node *root)
{
	Node *pivot = root->left;
	if (pivot != NULL)
	{
		root->left = pivot->right;
		if (root->left != NULL)
		{
			root->left->parent = root;
		}
		pivot->right = root;

		if (root->parent == NULL)
		{
			root->parent = pivot;
			pivot->parent = NULL;
		}
		else if (root->parent->left == root)
		{
			pivot->parent = root->parent;
			pivot->parent->left = pivot;
			root->parent = pivot;
		}
		else
		{
			pivot->parent = root->parent;
			pivot->parent->right = pivot;
			root->parent = pivot;
		}
	}
}

template<class Key, class Value>
void RBTree<Key,Value>::insertCaseOne(
		Node *node)
{
#if DEBUG > 0
	std::cout << "in case one\n";
#endif
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
#if DEBUG > 0
	std::cout << "in case two\n";
#endif
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
#if DEBUG > 0
	std::cout << "in case three\n";
#endif	
	Node *grandparent = GRANDPARENT(node);
	Node *uncle = UNCLE(node);

	if ((uncle != NULL) &&
		(uncle->color == RED))
	{
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
#if DEBUG > 0
	std::cout << "in case four\n";
#endif	
	Node *grandparent = GRANDPARENT(node);

	if ((node->parent->left == node) &&
		(node->parent == grandparent->right))
	{
#if DEBUG > 0
	printNodeData(node);
#endif
		node = node->parent;
		rightRotate(node);
	}
	else if ((node->parent->right == NULL) &&
			 (node->parent == grandparent->left))
	{
#if DEBUG > 0
	printNodeData(node);
#endif
		node = node->parent;
		leftRotate(node);
	}
#if DEBUG > 0
	std::cout << "in case five\n";
	printNodeData(node);
	printNodeData(node->parent);
#endif	
	return insertCaseFive(node);
}

template<class Key, class Value>
void RBTree<Key,Value>::insertCaseFive(
		Node *node)
{
#if DEBUG > 0
	std::cout << "in case five\n";
	printNodeData(node);
	printNodeData(node->parent);
	printNodeData(node->parent->parent);
#endif	
	Node *grandparent = GRANDPARENT(node);
	node->parent->color = BLACK;
	node->parent->parent->color = RED;
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

	if (root == NULL)
	{
		root = node;
	}

	if (parent != NULL)
	{
		if (parent->key > node->key)
		{
			if (parent->left == NULL)
			{
				parent->left = node;
				node->parent = parent;
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
				node->parent = parent;
			}
			else
			{
				standardInsert(node,parent->right);
			}
		}
	}

	return insertCaseOne(node);
}

template<class Key, class Value>
typename RBTree<Key,Value>::Node* RBTree<Key,Value>::search(
		Key key, Node* node)
{
	#if DEBUG > 0
		std::cout << "SEARCHING...\n";
	#endif
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
		return search(key,node->left);
	}
	else
	{
		return search(key,node->right);
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
	
	return standardInsert(node,root);
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
	Node* result = search(key, root);
	if (result != NULL)
	{
		return result->value;
	}
	return NULL;
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
