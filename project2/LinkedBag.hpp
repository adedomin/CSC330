#ifndef _LINKED_BAG
#define _LINKED_BAG
#include "Node.hpp"
#include "LinkedList.hpp"
#include <vector>
using namespace std;


template <class ItemType>
class LinkedBag {

	LinkedList<ItemType> list;
	
	public:

	LinkedBag();  //default constructor. Create an empty list.
    
	LinkedBag(LinkedBag<ItemType>& aBag);  // Copy constructor. 
    
	virtual ~LinkedBag(); // Destructor should be virtual

	bool isEmpty();  // Test if the bag is empty
	
	int getCurrentSize(); // Get the number of items in the bag
	
	bool add(const ItemType& newEntry);
	//Insert the newEntry into a bag. Place it right after the last item in the array.
	
	bool remove(const ItemType& anEntry);
	//Remove an item from the bag that matches the newEntry
	
	int getFrequencyOf (const ItemType& anEntry);
	// To count the number of times a given object occurs in a bag.
    
	bool contains(const ItemType& anEntry);
	// To test if the item "anEntry" is in the bag.
    
	void clear(); // Remove all items from the bag.
   
	std::vector <ItemType> toVector();
	// Get the entries that are in a bag and return them within a vector.
};

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() {
};

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(LinkedBag<ItemType>& rh) {

	std::vector<ItemType> vect = rh.toVector();
	typename std::vector<ItemType>::iterator itr = vect.begin();
	for (; itr != vect.end(); ++itr) {
		
		this->add(*itr);
	}
};

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
};

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() {

	return this->list.isEmpty();
};

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() {

	return this->list.getSize();
};

template<class ItemType>
bool LinkedBag<ItemType>::add(
		const ItemType& newEntry) {

	Node<ItemType>* node 
		= new Node<ItemType>(newEntry);

	if (node == NULL) {
		
		return false;
	}

	return list.pushBack(node);

};

template<class ItemType>
bool LinkedBag<ItemType>::remove(
		const ItemType& removeBy) {

	list.toBegin();
	int index = 0;
	while (!list.isNull()) {

		if (*list == removeBy) {
		
			list.deleteAt(index);
			return true;
		}

		++index;
		++list;
	}

	return false;
};

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(
		const ItemType& countBy) {

	list.toBegin();
	int count = 0;
	while (!list.isNull()) {

		if (*list == countBy) {

			++count;
		}

		++list;
	}

	return count;
};

template<class ItemType>
bool LinkedBag<ItemType>::contains(
		const ItemType& findBy) {

	this->list.toBegin();
	while (!list.isNull()) {

		if (*list == findBy) {

			return true;
		}
		++list;
	} 

	return false;
};

template<class ItemType>
void LinkedBag<ItemType>::clear() {

	this->list.deleteAll();	
};

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() {

	std::vector<ItemType> retVect;

	list.toBegin();
	while (!list.isNull()) {

		retVect.push_back(*list);
		++list;
	}

	return retVect;
};

#endif

