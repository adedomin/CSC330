#ifndef _NODE
#define _NODE

#include<iostream>
using namespace std;

template<class ItemType>
class Node
{
	public:

	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	void setLast(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
	Node<ItemType>* getLast() const;

	private:

	ItemType item;
	Node<ItemType>* next;
	Node<ItemType>* last;
};

template<class ItemType>
Node<ItemType>::Node():next(NULL), last(NULL)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem):item(anItem), next(NULL), last(NULL)
{
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr):item(anItem), next(nextNodePtr)
{
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}


template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

template<class ItemType>
void Node<ItemType>::setLast(Node<ItemType>* lastNodePtr)
{
	last = lastNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getLast() const
{
	return last;
}

#endif

