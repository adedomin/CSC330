#include "ADTbag.h"
#include <vector>


ArrayBag<class ItemType>::ArrayBag()
{
	tree_root.value = 0;
	tree_root.color = 'b';
	tree_root.left  = NULL;
	tree_root.right = NULL;
};

ArrayBag<class ItemType>::ArrayBag(ItemType item)
{
	tree_root.key = item;
	tree_root.value = 1;
	tree_root.color = 'b';
	tree_root.left  = NULL;
	tree_root.right = NULL;
};

ArrayBag::Node* ArrayBag::newNode()
{
	return
};

ArrayBag::Node* ArrayBag::findParent(const ItemType &item)
{
	Node* curr_root = &tree_root;
	while (curr_root != NULL) 
	{
		if (curr_root->key > item)
		{
			curr_root = curr_root->left;
		}
		else if (curr_root < item)
		{
			curr_root = curr_root->right;
		}
	}

	return curr_root;
};

void ArrayBag::addItem(
		const ItemType &item)
{
	Node *newNode = new Node()
	newNode->key = item;
	newNode->value = 1;
	newNode->color = "b";

	Node *parent = findParent(item);
	if (parent->key == item)
	{
		parent->value += 1;
		delete newNode;
	}
	else if (parent->key > item)
	{
		if (parent->color == 'r')
		{
			newNode->color = 'b';
		}
		else
		{
			newNode->color = 'r';
		}
		parent->right = newNode;

	}
	else
	{
		if (parent->color == 'r')
		{
			newNode->color = 'b';
		}
		else
		{
			newNode->color = 'r';
		}
		parent->left = newNode;
	}
}

void ArrayBag::removeItem(
		const ItemType &item)
{
	Node *node = findNode(item)
	if (node-value > 0)
	{
		node->value -= 1;
	}
}
