#define MAX_LIST 10000

template <class T>
class List
{
public:
	List();  //default constructor. Create an empty list.

	bool isEmpty() const;  // test if the list is empty
	
	bool isFull() const;  // test if the list is full
	
	int getLength() const; // get the length of the list
	
	void insert(int index, const T& newItem, bool& success);
	//Insert the newItem into the list at position index. NOTE: 0<=index<=getlength()
	
	void remove(int index, bool& success);
	//Remove an item from the list at position index. NOTE: 0<=index<=getlength()
	
	void retrieve(int index, T& dataItem, bool& success) const;
	// Retrieve a list item by position index. NOTE: 0<=index<=getlength()

	void traverse (void(*visit)(T &)); 
	//Traverse all items in the list from the beginning to the end
	
	void clear(); // Remove all items from the list.

protected:
	T items[MAX_LIST];
	int size; // number of items in the list
};

template <class T>
List<T>::List()
{
	size=0;
}

template <class T>
bool List<T>::isEmpty() const
{
	return (size==0);
}

template <class T>
bool List<T>::isFull() const
{
	return (size >= MAX_LIST);
}


template <class T>
int List<T>::getLength() const
{
	return size;

}

template <class T>
void List<T>::clear()
{
	size=0;
}

template <class T>
void List<T>::insert(int index, const T& newItem, bool& success)
{
	success=(index>=0)&&(index<=size)&&(size<MAX_LIST);
	if (success)
	{
		for (int i=size-1; i>=index; i--)
		{
			items[i+1]=items[i];
		}
		items[index]=newItem;
		size++;
	}

}

template <class T>
void List<T>::remove(int index, bool& success)
{
	success=(index>=0)&&(index<size);
	if (success)
	{
		for (int i=index; i<size; i++)
			items[i]=items[i+1];
	
		size--;
	}
}

template <class T>
void List<T>::retrieve(int index, T& dataItem, bool& success) const
{
	success=(index>=0)&&(index<size);
	if (success)
	{
		dataItem=items[index];
	}
}


template <class T>
void List<T>::traverse(void (*visit)(T &))
{
	for (int i=0; i<size; i++)
		(*visit)(items[i]);
}
