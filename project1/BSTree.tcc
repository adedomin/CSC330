#define DEBUG 0
#include <stddef.h>
#include <iostream>
#include <vector>

template<class Key, class Value>
BSTree<Key,Value>::BSTree()
{
	this->count = 0;
	this->root = NULL;
}

template<class Key, class Value>
BSTree<Key,Value>::BSTree(Key key, Value value)
{
	this->count = 1;
	this->root = new Node<Key,Value>();
	this->root->key = key;
	this->root->value = value;
}

template<class Key, class Value>
BSTree<Key,Value>::~BSTree()
{
	deleteAllNodes(root);
}

template<class Key, class Value>
void BSTree<Key,Value>::printInOrder()
{
	if (root == NULL)
	{
		std::cout << "!!!Empty!!!\n";
		return;
	}
	traverse(root,&printNodeData);
}

template<class Key, class Value>
void BSTree<Key,Value>::printNodeData(
		Node<Key,Value> *node)
{
	std::cout << "Key: "<< node->key << '\n'
		      << "Value: "<<node->value << '\n';
}

template<class Key, class Value>
void BSTree<Key,Value>::traverse(
		Node<Key,Value> *node,
		void (*f)(Node<Key,Value>*))
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
void BSTree<Key,Value>::deleteAllNodes(
		Node<Key,Value> *node)
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
void BSTree<Key,Value>::standardInsert(
		Node<Key,Value> *node, 
		Node<Key,Value> *parent)
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
				return 
				standardInsert(
					node,parent->left);
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
				return
				standardInsert(
					node,parent->right);
			}
		}
	}
}

template<class Key, class Value>
Node<Key,Value>* BSTree<Key,Value>::search(
		Key key, Node<Key,Value>* node)
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
void BSTree<Key,Value>::insertKey(
		Key key, Value value)
{
	Node<Key,Value> *node = new Node<Key,Value>();
	++count;

	node->key = key;
	node->value = value;
	
	return standardInsert(node,root);
}

template<class Key, class Value>
void BSTree<Key,Value>::deleteKey(
		Key key)
{
	Node<Key,Value> *found = search(key,root);

	if (found == NULL)
	{
		return;
	}

	if (found->parent == NULL)
	{
		delete found;
		root = NULL;
	}

	if (found->left == NULL &&
		found->right == NULL)
	{
		if (found->parent->left
			== found)
		{
			found->parent->left
				= NULL;
		}
		else
		{
			found->parent->right
				= NULL;
		}
	}
	else if (found->left == NULL)
	{
		if (found->parent->left
			== found)
		{
			found->parent->left
				= found->right;
		}
		else
		{
			found->parent->right
				= found->right;
		}
	}
	else if (found->right == NULL)
	{
		if (found->parent->left
			== found)
		{
			found->parent->left
				= found->left;
		}
		else
		{
			found->parent->right
				= found->left;
		}
	}
	else
	{
		
	}
	delete found;
}

template<class Key, class Value>
bool BSTree<Key,Value>::exists(
		Key key)
{
	return search(key, root) != NULL;
}

template<class Key, class Value>
bool BSTree<Key,Value>::changeValue(
		Key key,Value value)
{
	Node<Key,Value> *found = search(key, root);
	
	if (found == NULL)
	{
		return false;		
	}

	found->value = value;
	return true;
}

template<class Key, class Value>
Value BSTree<Key,Value>::getValue(Key key)
{
	Node<Key,Value>* result = search(key, root);
	if (result != NULL)
	{
		return result->value;
	}
	return NULL;
}

template<class Key, class Value>
bool BSTree<Key,Value>::isEmpty()
{
	return (count < 1);
}

template<class Key, class Value>
int BSTree<Key,Value>::getSize()
{
	return count;
}

template<class Key, class Value>
void BSTree<Key,Value>::traverseToVector(
		Node<Key,Value> root,
		std::vector<Node<Key,Value>> &array)
{
	if (root == NULL)
	{
		return;
	}

	traverseToVector(root->left, array);
	array.push_back(Node<Key,Value>());
	array.back().key = root->key;
	array.back().value = root->value;
	traverseToVector(root->right, array);
}

template<class Key, class Value>
std::vector<Node<Key,Value>> BSTree<Key,Value>::toVector()
{
	std::vector<Node<Key,Value>> array;
	traverseToVector(root,array);
}
