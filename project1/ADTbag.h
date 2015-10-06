#ifndef _ARRAY_BAG
#define _ARRAY_BAG
#include <vector>

const int MAX_LIST=20;  // Maximum capacity of the bag

//using namespace std;

template <class ItemType>
class ArrayBag {

public:

	ArrayBag();  //default constructor. Create an empty list.

	bool isEmpty() const;  // test if the bag is empty
	
	int getCurrentSize() const; // get the number of items in the bag
	
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


private:

	ItemType items[MAX_LIST];  // Array of bag items
	int size; // current count of bag items
};

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() {

	this->size = 0;
};

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {

	return this->size < 1;
};

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {

	return this->size;
};

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry) {

	if (this->size >= MAX_LIST) {

		return false;
	}

	this->items[this->size] = newEntry;
	this->size += 1;
	return true;
};

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& removeBy) {

	int removedIndex = -1;
	for (int i=0; i<this->size; ++i) {

		if (removedIndex > -1) {
			
			this->items[removedIndex] = this->items[i];
			++removedIndex;
		}
		else if (this->items[i] == removeBy) {

			removedIndex = i;
		}
	}

	this->size -= 1;
	return removedIndex > -1;
};

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& findBy) const {

	int count = 0;
	for	(int i=0; i<this->size; ++i) {
		
		if (this->items[i] == findBy) {
			
			++count;
		}
	}

	return count;
};

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& findBy) const {

	for (int i=0; i<this->size; ++i) {

		if (this->items[i] == findBy) {

			return true;
		}
	}

	return false;
};

template<class ItemType>
void ArrayBag<ItemType>::clear() {

	this->size = 0;
}

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
	
	std::vector<ItemType> retVect;
	for (int i=0; i<this->size; ++i) {

		retVect.push_back(this->items[i]);
	}

	return retVect;
};

#endif

