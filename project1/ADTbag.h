#ifndef _ARRAY_BAG
#define _ARRAY_BAG
#include <vector>

//const int MAX_LIST=20;  // Maximum capacity of the bag
// bag capacity? ha

template <class ItemType>
class ArrayBag
{
public:
	ArrayBag();  //default constructor. Create an empty list.
	// initialize with an item
	ArrayBag(ItemType);
 
	// test if the bag is empty
	bool isEmpty() const;
	// get the number of items in the bag
	int getCurrentSize() const;
 	// insert bag into heap, swim up down as needed
	bool addItem(const ItemType&);
	// remove bag from heap, swim up and down as needed
	bool removeItem(const ItemType&);
	//Remove an item from the bag that matches the newEntry
	// To count the number of times a given object occurs in a bag.
	// return Node.value for given key`
	// return 0 or less if no such key is in the bag
	int getFrequencyOf (const ItemType&) const;
	// return true if key is an entry in bag
	bool contains(const ItemType&) const;
	// delete the tree
	void clear(); // Remove all items from the bag.
	// return the tree's raw vector
	vector <ItemType> toVector() const; 

private:
	struct Node
	{
		// item type must be comparable
		ItemType key;
		// count of items
		int value;
		// color
		// r = red
		// b = black
		char color;
		// left leaf
		Node *left;
		// right leaf
		Node *right;
	};
	
	Node tree_root;

	Node* findParent(ItemType key);
};
#endif

