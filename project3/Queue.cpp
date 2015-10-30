#include "Queue.h"

Queue::Queue() {

	front = 0;
	back  = 0;
	count = 0;
}

bool Queue::isFull() {

	if (empty()) {

		return false;
	}
	else {

		return back == front;
	}
}

bool Queue::empty() const {

	return count < 1;
}

bool Queue::dequeue() {

	if (empty()) {

		return false;
	}
	
	front++;
	count--;
	if (front == MAX_SIZE) {
		front = 0;
	}
	return true;
}

bool Queue::enqueue(const itemType& item) {

	if (isFull()) {

		return false;
	}

	items[back] = item;
	back++;
	count++;
	if (back == MAX_SIZE) {
		back = 0;
	}
	return true;
}

bool Queue::peekFront(itemType& item) const {

	if (empty()) {
		
		return false;
	}

	item = items[front];
	return true;
}

int Queue::getSize() const {
	
	return count;
}
