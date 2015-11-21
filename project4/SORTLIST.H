#ifndef SORTLIST_H
#define SORTLIST_H
#define LCHILD(x) x*2+1
#define RCHILD(x) x*2+2
#define PARENT(x) (int)((x-1)/2)

#include <stdio.h>
#include "LIST.H"
#include "KEY.H"
#include "RECORD.H"
//#include "RANDOM.H"

template <class T>
class Sortable_list: public List<T> {

public:

	Sortable_list();
	void insertion_sort(); // done: implement insertion sort
	void selection_sort(); // done: implement selection sort
	void shell_sort();   // todo; implement shell sort 
	void quick_sort();  // done; implement quick sort
	void heap_sort();  // todo; implement heap sort (optional)
	void bubble_sort(); // todo; implement bubble sort
	void merge_sort(); // todo; implement merge sort

private:
	
	Random random;
	// for Shuffle

	void swap(int,int);
	// array indicies to sawp.
	void copy_array(T*,int,int);
	// copy array for merge sort
	void shuffle();
	// to gaurd against
	// intentionally given
	// data sets that will
	// slow quick sort

	// --- qsort --- //
	int partition(int,int);
	// partitioning for qsort
	void quick_sort2(int,int);
	// --- qsort --- //

	// --- merge --- //
	void merge_sort2(T*,int,int);
	// split into sub arrays
	void merge(T*,int,int,int);
	// merge and sort sub arrays
	// --- merge --- //
	
	// --- hsort --- //
	void swim_down(int);
	// swim parents down
	// to create heap property
	void heapify(int);
	// create heap property
	// for the array
	void heap_pop();
	// move largest elements
	// to back of array in order
	// --- hsort --- //
};

template <class T>
Sortable_list<T>::Sortable_list() {

	this->size = 0;
}

// ----- BEGIN ARRAY HELP FUNCTIONS ----- //

template <class T>
void Sortable_list<T>::swap(int ele1, int ele2) {

	T temp = this->items[ele1];
	this->items[ele1] = this->items[ele2];
	this->items[ele2] = temp;
}

template <class T>
void Sortable_list<T>::copy_array(
		T* copyArr, int begin, int end) {

	for (int i=begin; i<end; ++i) {
		this->items[i] = copyArr[i];
	}
}

template <class T>
void Sortable_list<T>::shuffle() {

	for (int i=0; i < this->size-1; ++i) {
		// random_integer's upper bound is inclusive (i,j)
		int shuffle_by = random.random_integer(i,this->size-1);
		swap(shuffle_by, i);
	}
}

// ------ END ARRAY HELP FUNCTIONS ------ //

template <class T>
void Sortable_list<T>::bubble_sort() {

	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int i=1; i < this->size; ++i) {
			if (this->items[i-1] > this->items[i]) {
				swap(i, i-1);
				swapped = true;
			}
		}
	}
}

template <class T>
void Sortable_list<T>::selection_sort() {

	for (int i=0; i<this->size-1; ++i) {
		int minimum = i;

		for (int j=i+1; j<this->size; ++j) {
			if (this->items[j] < this->items[minimum]) {
				minimum = j;
			}
		}

		if (minimum != i) {
			swap(i, minimum);
		}
	}
}

template <class T>
void Sortable_list<T>::insertion_sort() {

	for (int i=1; i<this->size; ++i) {
		for (int j=i;j > 0 && this->items[j-1] > this->items[j]; --j) {
			swap(j-1, j);
		}
	}
}

template <class T>
void Sortable_list<T>::shell_sort() {

	// Gaps from Robert Sedgewick's paper
	// Analysis of Shellsort and Related Algorithms
	int gaps[] = 
		{ 1391376, 463792, 198768, 
		  86961, 33936, 13776, 4592, 
		  1968, 861, 336, 112, 48, 21, 
		  7, 3, 1 };
	for (int i=0; i<16; ++i) {
		for (int j=gaps[i]; j<this->size; ++j) {
			for (int itr=j;itr > gaps[i] && this->items[j-gaps[i]] > this->items[j]; --j) {
				swap(j-gaps[i], j);
			}
		}
	}
}

// ----- BEGIN QUICK SORT ----- //

// pick a pivot
// make it such that 
// left <= pivot < right
template <class T>
int Sortable_list<T>::partition(int lo, int hi) {

	T pivot = this->items[hi-1];
	int i = lo;
	for (int j=lo; j < hi-1; ++j) {
		if (this->items[j] <= pivot) {
			swap(i,j);
			i++;
		}
	}
	swap(i,hi-1);
	return i;
}

// partitions and splits by
// partition value/s is/are NOT included
// in future splits
template <class T>
void Sortable_list<T>::quick_sort2(int lo, int hi) {

	if (lo >= hi) {
		return;
	}

	int mid = partition(lo,hi);
	quick_sort2(lo,mid);
	quick_sort2(mid+1,hi);
}

template <class T>
void Sortable_list<T>::quick_sort() {

	shuffle();
	quick_sort2(0, this->size);
}

// ------ END QUICK SORT ------ //

// ----- BEGIN MERGE SORT ----- //

// merges the two parts
// left is [lo, mid)
// right is [mid, hi)
template <class T>
void Sortable_list<T>::merge(
		T* copy,
		int lo,
		int mid,
		int hi) {

	int iter_left = lo;
	int iter_right = mid;

	for (int i=lo; i<hi; ++i) {
		
		if (iter_left < mid && (iter_right >= hi || 
		    this->items[iter_left] <= this->items[iter_right])) {
			copy[i] = this->items[iter_left];
			iter_left++;
		}

		else {
			copy[i] = this->items[iter_right];
			iter_right++;
		}
	}
}

// splits array into parts
// then merges them
template <class T>
void Sortable_list<T>::merge_sort2(
		T* copy,
		int lo, int hi) {

	if (hi - lo < 2) {
		return;
	}

	int mid = (int)((lo + hi) /2);
	merge_sort2(copy,lo,mid);
	merge_sort2(copy,mid,hi);
	merge(copy,lo,mid,hi);
	copy_array(copy,lo,hi);
}

// creates a copy array
// then calls the recursive sort algo
template <class T>
void Sortable_list<T>::merge_sort() {

	T* copy = new T[this->size];
	merge_sort2(copy, 0, this->size);
	delete[] copy;
}

// ------ END MERGE SORT ------ //

// ----- BEGIN HEAP SORT ----- //

// from an arbitrary root
// check if left or right child
// is greater than root
// swap if greater
template <class T>
void Sortable_list<T>::swim_down(int root) {

	if (LCHILD(root) > this->size-1) {
		return;
	}

	int swap_pos = root;
	if (this->items[swap_pos] < this->items[LCHILD(root)]) {
		swap_pos = LCHILD(root);
	}

	if (RCHILD(root) <= this->size-1 && 
		(this->items[swap_pos] < this->items[RCHILD(root)]))
	{
		swap_pos = RCHILD(root);
	}

	if (swap_pos == root) {
		return;
	}

	swap(swap_pos, root);
	return swim_down(swap_pos);
}

// moves the highest values in order
// to the rear of the array
template <class T>
void Sortable_list<T>::heap_pop(){
	swap(0,this->size-1);
	this->size--;
	swim_down(0);
}

// takes first parent and goes through every other parent
template <class T>
void Sortable_list<T>::heapify(int parent) {
	
	if (parent < 0) {
		return;
	}

	swim_down(parent);
	heapify(parent-1);
}

// pretty dirty, I know.
// in place heapify's the tree using swim down
// then "pops" them till the root is the minimum
// then dirtily sets size to it's previous value
template <class T>
void Sortable_list<T>::heap_sort() {
	heapify(PARENT(this->size-1));

	int s2 = this->size;
	while(this->size > 0) {
		heap_pop();
	}
	this->size = s2;
}

// ------ END HEAP SORT ------ //

#endif

