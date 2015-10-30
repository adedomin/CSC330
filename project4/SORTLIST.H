#ifndef SORTLIST_H
#define SORTLIST_H

#include "LIST.H"
#include "KEY.H"
#include "RECORD.H"

template <class Record>
class Sortable_list: public List<Record> {
public:
	void insertion_sort(); // todo: implement insertion sort
	void selection_sort(); // todo: implement selection sort
	void shell_sort();   // todo; implement shell sort 
	void quick_sort();  // todo; implement quick sort
	void heap_sort();  // todo; implement heap sort (optional)
	void bubble_sort(); // todo; implement bubble sort
	void merge_sort(); // todo; implement merge sort

private:
	// add private member functions if needed
	void swap(int, int);
	// array indicies to sawp.
	void copy_array(Record*,Record*);
	// copy array for merge sort
	
	void quick_sort2(Record*, int);

	void merge_sort2(Record*, Record*, int, int);
};

template <class Record>
void Sortable_list::swap(int ele1, int ele2) {

	Record temp = items[ele1];
	items[ele1] = items[ele2];
	items[ele2] = temp;
}

template <class Record>
void Sortable_list::insertion_sort() {

	for (int i=1; i<count; ++i) {
		
		for (int j=i; 
			 j>0&&items[j-1]>[j]
			 ; --j) {
			swap(j-1, j);
		}
	}
}

template <class Record>
void Sortable_list::selection_sort() {

	for (int i=0; i<count-1; ++i) {
		int minimum = i;

		for (int j=i+1; j<count; ++j) {
			if (items[j] < items[minimum]) {
				minimum = j;
			}
		}

		if (minimum != i) {
			swap(i, minimum);
		}
	}
}

template <class Record>
void Sortable_list::quick_sort2(
		Record items*, int size) {
	if (int size == 0) {
		return;
	}

	int pivot = size;
	while ()
}

template <class Record>
void Sortable_list::quick_sort() {

	quick_sort2(items,count);
}

template <class Record>
void Sortable_list::merge_sort2(
		Record* item, Record* copy
		int begin, int end) {

	if (end - begin < 2) {

		return;
	}

	int middle = (int)((begin + end) /2)
	merge_sort2(item,copy,begin,middle);
	merge_sort2(item,copy,middle,end);
}

template <class Record>
void Sortable_list::merge_sort() {

	Record copy[size];
	merge_sort2(items, copy, 0, size);
}
#endif


