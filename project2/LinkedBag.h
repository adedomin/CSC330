#ifndef _LINKED_BAG
#define _LINKED_BAG
#include "Node.h"
#include <vector>
//using namespace std;


template <class ItemType>
class LinkedBag {    

	Node<ItemType> *headPtr;
	// the pointer pointing to the first linked node of the bag
	Node<ItemType> *tailPtr;
	// the pointer pointing to the last linked node of the bag
	int size; // current count of bag items

	void deleteAllNodes(Node<ItemType>*) const;
	// delete all nodes and free their memory

	Node<ItemType>* getPointerTo(const ItemType&,Node<ItemType>*) const; 
	// Return either a pointer to the node containing the given entry
    // or NULL if the entry is not in the bag.

	Node<ItemType>* getParentTo(const ItemType&,Node<ItemType>*) const;
	// return's parent of node who has a child with item requested
	// NULL otherwise
	// if it returns the tail, that means head is the child

	int countOf(const ItemType&,Node<ItemType>*) const;
	// count of times item is in the list

	void traverseToVector(std::vector<ItemType>&,Node<ItemType>*) const;

public:
	LinkedBag();  //default constructor. Create an empty list.
   
	LinkedBag(const LinkedBag<ItemType>& aBag);  // Copy constructor. 
   
	virtual ~LinkedBag(); // Destructor should be virtual

	bool isEmpty() const;  // Test if the bag is empty

	int getCurrentSize() const; // Get the number of items in the bag

	bool add(const ItemType& newEntry);
	//Insert the newEntry into a bag that is not full. Place it right after the last item in the array.

	bool remove(const ItemType& anEntry);
	//Remove an item from the bag that matches the newEntry

	int getFrequencyOf (const ItemType& anEntry) const;
	// To count the number of times a given object occurs in a bag.

	bool contains(const ItemType& anEntry) const;
	// To test if the item "anEntry" is in the bag.

	void clear(); // Remove all items from the bag.

	std::vector <ItemType> toVector() const;
	// Get the entries that are in a bag and return them within a vector.
};

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(
		const ItemType& item,
		Node<ItemType>* node) const {
	if (node == NULL) {
		
		return NULL;
	}

	if (node->getItem() != item) {
		
		return getPointerTo(item, node->getNext());
	}

	return node;
};

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getParentTo(
		const ItemType& item,
		Node<ItemType>* node) const {

	if (node == NULL || 
		(node->getNext() == NULL && 
		 node != this->headPtr)) {

		return NULL;
	}

	// consider tailPtr as head's parent
	if (node == this->headPtr && 
		this->headPtr->getItem() ==
		item) {

		return tailPtr;
	}

	if (node->getNext()->getItem() == item) {
		
		return node;
	}

	return getParentTo(item,node->getNext());
};

template<class ItemType>
int LinkedBag<ItemType>::countOf(
		const ItemType& item,
		Node<ItemType>* node) const {

	if (node == NULL) {

		return 0;
	}

	if (node->getItem() == item) {

		return 1 + countOf(item,node->getNext());
	}

	return countOf(item,node->getNext());
};

template<class ItemType>
void LinkedBag<ItemType>::traverseToVector(
		std::vector<ItemType>& items,
		Node<ItemType>* node) const {

	if (node == NULL) {

		return;
	}

	items.push_back(node->getItem());
	return traverseToVector(items,node->getNext());
};

template<class ItemType>
void LinkedBag<ItemType>::deleteAllNodes(Node<ItemType>* node) const {

	if (node == NULL) {

		return;
	}

	Node<ItemType>* child = node->getNext();
	delete node;
	return deleteAllNodes(child);
};

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() {

	this->headPtr = NULL;
	this->tailPtr = NULL;
	this->size = 0;
};

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag& bag) {

	this->headPtr = NULL;
	this->tailPtr = NULL;
	this->size = 0;

	std::vector<ItemType> items = bag.toVector();
	typename std::vector<ItemType>::iterator i = items.begin();
	for (; i!=items.end(); ++i) {

		this->add(*i);
	}

	return;
};

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {

	deleteAllNodes(this->headPtr);
};

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {

	return this->size < 1;
};

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {

	return this->size;
};

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& item) {

	Node<ItemType>* newNode = new Node<ItemType>(item);

	// Out of mem?
	if (newNode == NULL) {

		return false;
	}

	if (this->isEmpty()) {

		this->headPtr = newNode;
		this->tailPtr = newNode;
		++size;
		return true;
	}

	this->tailPtr->setNext(newNode);
	this->tailPtr = newNode;
	++size;
	return true;
};

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& item) {

	Node<ItemType>* parent = 
		this->getParentTo(item,headPtr);

	// not found
	if (parent == NULL) {
	
		return false;
	}

	// assume tailPtr is headPtr's parent
	if (parent == tailPtr) {
		
		Node<ItemType>* child = 
			this->headPtr->getNext();

		delete this->headPtr;
		this->headPtr = child;	
		--size;
		return true;
	}

	Node<ItemType>* child = parent->getNext();
	// ???
	if (child == NULL) {

		return false;
	}

	parent->setNext(child->getNext());
	if (child == tailPtr) {

		this->tailPtr = parent;
	}
	delete child;
	--size;
	return true;
};

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& item) const {

	return this->countOf(item,headPtr);
};

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& item) const {
	
	return getPointerTo(item,headPtr) != NULL;
};

template<class ItemType>
void LinkedBag<ItemType>::clear() {

	deleteAllNodes(headPtr);
	this->headPtr = NULL;
	this->tailPtr = NULL;
	this->size = 0;
};

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {

	std::vector<ItemType> items;
	traverseToVector(items,headPtr);
	return items; 
};

#endif

