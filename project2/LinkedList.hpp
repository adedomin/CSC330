#ifndef CSC330_LINKED_LIST
#define CSC330_LINKED_LIST
#include "Node.hpp"

/** 
 * doubly linked list
 */
template<class T>
class LinkedList {

	Node<T> *head;
	Node<T> *tail;
	Node<T> *curr;

	int size;

	// takes negative indices
	// boolean indicates if
	// functions should start from
	// HEAD or from current position
	// negative indices are not effected
	// as they always start from back
	traverse_to(int,bool);

	public:

	LinkedList();
	LinkedList(Node<T>*);

	~LinkedList();

	void pushFront(Node<T>*);
	void pushBack(Node<T>*);

	// returns value of deleted
	T popFront();
	T popBack();
	T deleteAt(int index);

	int getSize();
	bool isEmpty();

	// pointer like logic to make usage more natural

	// set currPtr to headPtr
	void toBegin();
	// set currPtr to tailPtr
	void toEnd();

	// if currPtr has next
	bool hasNext();
	// if currPtr has last
	bool hasLast();
    
	// moves up the currPtr unless next is null
	void operator++();
	void shiftRight();
	// moves back currPtr unless last is null
	void operator--();
	void shiftLeft();

	// return value of current currPtr
	T operator*();
	T getCurrValue();
	// return value at index given
	// note, traverses from currPtr
	// make sure to call toBegin()
	// if you don't want that
	//
	// Note, supports negative indices as well
	// so -1 will goto last and so on
	T operator[](int index);
	T getAt(int index);
};

template<class T>
LinkedList<T>::LinkedList() {
	
	this->head = NULL;
	this->curr = NULL;
	this->tail = NULL;
	this->size = 0;
}

template<class T>
LinkedList<T>::LinkedList(Node<T>* initial) {

	this->head = initial;
	this->curr = initial;
	this->tail = initial;
	if (initial != NULL) {

		this->size = 1;
	}
	else {

		this->size = 0;
	}
}

template<class T>
Node<T>* LinkedList<T>::traverses_to(int index, 
		bool fromCurr) {

	Node<T>* temp;
	if (index > -1) {

		if (!fromCurr) {
			temp = this->head;
		}
		else {
			temp = this->curr;
		}

		for (int i=0; i<index; ++i) {

			if (temp->getNext() != NULL) {
				
				temp = temp->getNext();
			}
			else {
			
				break;
			}
		}
	}
	else {

		temp = this->tail;
		for (int i=-1; i>index; --i) {

			if (temp->getLast() != NULL) {
				
				temp = temp->getLast();
			}
			else {
			
				break;
			}
		}
	}

	return temp;
}

template<class T>
void LinkedList<T>::pushFront(Node<T>* newHead) {

	if (newHead == NULL) {

		return;
	}

	if (isEmpty())
	{
		this->head = newHead;
		this->tail = newHead;
		this->++size;
		return;
	}

	newHead->setNext(this->head);
	newHead->setLast(NULL);
	this->head->setLast(newHead);
	this->head = newHead;
	this->++size;
}

template<class T>
void LinkedList<T>::pushBack(Node<T>* newTail) {

	if (newTail == NULL) {

		return;
	}

	if (isEmpty())
	{
		this->head = newTail;
		this->tail = newTail;
		this->++size;
		return;
	}

	newTail->setLast(this->tail);
	newTail->setNext(NULL);
	this->tail->setNext(newTail);
	this->tail = newTail;
	this->++size;
}

template<class T>
T LinkedList<T>::popFront() {

	if (isEmpty())
	{
		return T();
	}

	T retval = this->head->getItem();
	if (this->size == 1)
	{	
		delete this->head;
		this->head = NULL;
		this->tail = NULL;
		--size;
		return retval;
	}

	Node<T>* nextHead = this->head->getNext();
	delete this->head;
	this->head = nextHead;
	this->head->setLast(NULL);
	--size;
	return retval;
}

template<class T>
T LinkedList<T>::popBack() {

	if (isEmpty())
	{
		return T();
	}

	T retval = this->tail->getItem();
	if (this->size == 1)
	{	
		delete this->tail;
		this->head = NULL;
		this->tail = NULL;
		--size;
		return retval;
	}

	Node<T>* nextTail = this->tail->getLast();
	delete this->tail;
	this->tail = nextTail;
	this->tail->setNext(NULL);
	--size;
	return retval;
}

template<class T>
T LinkedList<T>::deleteAt(int index) {

	Node<T>* temp = traverse_to(index, false);

	if (temp == this->head) {

		return popFront();
	}

	if (temp == this->last) {
		return popBack();
	}
	
	if (temp->getNext() != NULL
		&& temp->getLast() != NULL) {

		temp->getNext()->setLast(temp->getLast());
		temp->getLast()->setNext(temp->getNext());
	}

	T retval = temp->getItem();
	delete temp;
	return retval;
}

template<class T>
void LinkedList<T>::toBegin() {

	this->curr = this->head;
};

template<class T>
void LinkedList<T>::toEnd() {

	this->curr = this->tail;
};


template<class T>
bool LinkedList<T>::hasNext() {

	return this->curr->getNext() != NULL;
};

template<class T>
bool LinkedList<T>::hasLast() {

	return this->curr->getLast() != NULL;
};

template<class T>
void LinkedList<T>::operator++() {

	this->shiftRight();
};

template<class T>
void LinkedList<T>::shiftRight() {

	if (this->hasNext()) {

		this->curr = this->curr->getNext();
	}
};

template<class T>
void LinkedList<T>::operator--() {

	this->shiftLeft();
};

template<class T>
void LinkedList<T>::shiftLeft() {

	if (this->hasLast()) {

		this->curr = this->curr->getLast();
	}
};

template<class T>
T LinkedList<T>::operator*() {

	return this->getCurrValue();
};

template<class T>
T LinkedList<T>::getCurrValue() {

	return this->curr->getItem();
};

template<class T>
T LinkedList<T>::operator[](int index) {

	return this->getAt(index);
};

template<class T>
T LinkedList<T>::getAt(int index) {

	return traverse_to(index, true)->getItem();
};

template<class T>
int LinkedList<T>::getSize() {

	return size;
}

template<class T>
bool LinkedList<T>::isEmpty() {

	return size < 1;
}
#endif
