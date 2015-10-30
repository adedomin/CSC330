#include"Queue.h"

void displayQ(Queue & queue)
{
	cout << "The queue contains :\n" ;
	vector<int> queueItems=queue.toVector();
	for (int i=0; i<queue.getSize(); i++)
	{
		cout <<queueItems[i] << " ";
	}
	cout << endl;
}

int main()
{
	Queue q;  //create an empty queue

	bool flag=q.empty(); // To test if the queue is really empty.
	if (flag)  
		cout <<"The queue is empty.\n";
	
	q.enqueue(1);  //To test the enqueue function by inserting a set of numbers (1-10) into q. 
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	displayQ(q);  // Display the contents in q.

	int buffer;   // To test the peekFront function. The buffer should hold the the value of the front entry  
	q.peekFront(buffer);
	cout << "The front entry of the queue is " << buffer << " .\n";
	 
	flag=q.enqueue(11); // To test the returned value of the enqueue fnction. It returns flase when the q has no room 
	if (!flag)
		cout << "THe queue is full. No room for insertion.\n";
	
	q.dequeue(); // To test the dequeue function. Remove the first two entries from the q.
	q.dequeue();
	displayQ(q);  // Display the contents in q.

	q.enqueue(11);  // Does the q have room to hold two more new entry?
	q.enqueue(12);
	displayQ(q);  // Display the contents in q.

	q.peekFront(buffer); // what's the front entry of the q now?  
	cout << "The front entry of the queue is " << buffer << " .\n";

}
