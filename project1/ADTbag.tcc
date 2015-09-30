template<class T>
ArrayBag<T>::ArrayBag()
{
	bag = new BSTree<T,int>();
	internal_count = 0;
}

template<class T>
ArrayBag<T>::ArrayBag(T item)
{
	bag = new BSTree<T,int>(item);
	internal_count = 1;
}

template<class T>
ArrayBag<T>::~ArrayBag()
{
	delete bag;
}

template<class T>
bool ArrayBag<T>::isEmpty()
{
	return internal_count < 1;
}

template<class T>
int ArrayBag<T>::getCurrentSize()
{
	return internal_count;
}

template<class T>
void ArrayBag<T>::addItem(const T &item)
{
	if (!bag->exists(item))
	{
		bag->insertKey(item, 1);
		return;
	}

	int count = bag->getValue(item);
	bag->changeValue(item,count+1);
}

template<class T>
void ArrayBag<T>::removeItem(const T &item)
{
	if (!bag->exists(item))
	{
		return;
	}

	int count = bag->getValue(item);
	if (count > 0)
	{
		bag->changeValue(item,count-1);
	}
	return;
}

template<class T>
int ArrayBag<T>::getFrequencyOf(const T &item)
{
	return bag->getValue(item);
}

template<class T>
bool ArrayBag<T>::contains(const T &item)
{
	return bag->getValue(item) != 0;
}

template<class T>
void ArrayBag<T>::clear()
{
	delete bag;
	bag = new BSTree<T,int>;
}

template<class T>
void ArrayBag<T>::printBag()
{
	bag->printInOrder();
}

template<class T>
std::vector<T> ArrayBag<T>::toVector()
{
	std::vector<Node<T,int>> array = bag->toVector();
	std::vector<T> retArray;
	
	typename std::vector<Node<T,int>>::iterator i = array.begin();
	for (;i != array.end(); ++i)
	{
		for (int i2=0; i2<i->value; ++i2)
		{
			retArray.push_back(i->key);
		}
	}

	return retArray;
}
