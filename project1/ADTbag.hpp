#ifndef _ARRAY_BAG
#define _ARRAY_BAG
#include "BSTree.hpp"
#include <vector>

//const int MAX_LIST=20;  // Maximum capacity of the bag
// bag capacity? ha

template <class T>
class ArrayBag
{
	BSTree<T,int> *bag;	
	// BSTree's count does not
	// know how ADTbag counts
	// so, keep own internal
	// count
	int internal_count;

	public:
	ArrayBag();  //default constructor. Create an empty list.
	// initialize with an item
	ArrayBag(T);
	// delete bag
	~ArrayBag();
 
	// test if the bag is empty
	bool isEmpty();
	// get the number of items in the bag
	int getCurrentSize();
	void addItem(const T&);
	void removeItem(const T&);
	//Remove an item from the bag that matches the newEntry
	// To count the number of times a given object occurs in a bag.
	// return Node.value for given key`
	// return 0 or less if no such key is in the bag
	int getFrequencyOf (const T&);
	// return true if key is an entry in bag
	bool contains(const T&);
	// delete the tree
	void clear(); // Remove all items from the bag.
	// return the tree's raw vector
//	vector <T> toVector() const; 

	// print bag in order
	void printBag();
	std::vector<T> toVector();
};

#include "ADTbag.tcc"
#endif

