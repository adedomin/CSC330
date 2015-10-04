#ifndef _LINKED_BAG
#define _LINKED_BAG
#include "Node.hpp"
#include "LinkedList.hpp"
#include <vector>
using namespace std;


template <class ItemType>
class LinkedBag
{
	LinkedList<ItemType> *list;
	
	public:

	LinkedBag();  //default constructor. Create an empty list.
    
	LinkedBag(const LinkedBag<ItemType>& aBag);  // Copy constructor. 
    
	virtual ~LinkedBag(); // Destructor should be virtual

	bool isEmpty() const;  // Test if the bag is empty
	
	int getCurrentSize() const; // Get the number of items in the bag
	
	bool add(const ItemType& newEntry);
	//Insert the newEntry into a bag. Place it right after the last item in the array.
	
	bool remove(const ItemType& anEntry);
	//Remove an item from the bag that matches the newEntry
	
	ItemType pop();
	// remove last element from list and return its val
	
	int getFrequencyOf (const ItemType& anEntry) const;
	// To count the number of times a given object occurs in a bag.
    
	bool contains(const ItemType& anEntry) const;
	// To test if the item "anEntry" is in the bag.
    
	void clear(); // Remove all items from the bag.
   
	vector <ItemType> toVector() const;
	// Get the entries that are in a bag and return them within a vector.
};
#endif

