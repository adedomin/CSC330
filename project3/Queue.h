#ifndef _QUEUE
#define _QUEUE
#include<iostream>
#include<vector>
using namespace std;
const int MAX_SIZE=10;

typedef int itemType;
class Queue {
public:
	Queue();  // Constructor. Initialize front=0, back=0, count=0 
    bool empty() const; // To test if the queue is empty. Return true if it is, flase if it is not. 
    bool dequeue(); // Remove the front entry from the queue
    bool enqueue(const itemType &item); // Add new entry called item at the back of the queue. 
    bool peekFront(itemType &item) const; // Retrieve the front entry from the queue
	int getSize() const ;  // To get the number of the entries in the queue


	vector<itemType> toVector() const  // to convert the queue to a vector
	{
		vector<itemType> vectorQ;

		int i=front;
		int size=count;
		while (size>0)
		{
			i=i%MAX_SIZE;
			vectorQ.push_back(items[i]);
			i++;
			size--;
		}
		return vectorQ;

	}

private:

	bool isFull();

	int front, back; 
	int count;
	itemType items[MAX_SIZE];  // items is a circular array to store the queue.

};

#endif


