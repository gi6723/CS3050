/*********************************************
*CMP_SC3050
*By Gianni Ioannou
*gci5k8
*Feburary 15,2024
*Assignment 2
*SS 2024
***********************************************/
#include <cs3050.h>

void buildMaxHeap(void *array, size_t nitems, size_t size, int (*CompareFunc)(const void *, const void*));
void heapify(void *array, size_t size, size_t heapSize, int (*CompareFunc)(const void *, const void*), int i);

void heapsort(void *array, 
				size_t nitems, 
				size_t size, 
				int (*CompareFunc)(const void *, const void*))
{
	//checks for null array, empty array or invalid size 
	if (array == NULL || nitems == 0 || size <= 0) 
	{
        return;
    }

	//Called to rearrange the array into a max heap
	buildMaxHeap(array, nitems, size, CompareFunc);

	//After MaxHeap is built, this swaps the the root of the heap(largest element) with the last element in the unsorted part of the array 
	//size reduced by on to keep track of unsorted vs. sorted portion
	for(int i = nitems-1; i>0; i--)
	{
		Swap(array, array + i*size, size);
		heapify(array,size, i, CompareFunc, 0);
	}
}

void buildMaxHeap(void *array, size_t nitems, size_t size, int (*CompareFunc)(const void *, const void*))
{
	//iteratively calls heapify starting from the lasts non-leaf node to the root
	//Each call makes sure that each subtree satisfies the max heap property
	for(int i = (nitems/2)-1; i >= 0; i--)
	{
		heapify(array,size, nitems, CompareFunc, i);
	}
	
}

//recursively called, checks subtree heap property and swaps when neccessary 
void heapify(void *array, size_t size, size_t heapSize, int (*CompareFunc)(const void *, const void*), int i)
{
	//grabs index of starting node based off where we are in the array
	int largest = i;
	//grabs index of left child
	int leftChild = 2*i + 1;
	//grabs index of righChild 
	int rightChild = 2*i + 2;

	//checks if leftChild exsists, checks if leftChild greater than "root"
	if(leftChild < heapSize && CompareFunc(array + leftChild*size, array + largest*size) > 0)
	{	
		//if larger largest inherits lefChilds index
		largest = leftChild;
	}
	//does the same thing but for the righChild
	if(rightChild < heapSize && CompareFunc(array + rightChild*size, array + largest*size)>0)
	{
		largest = rightChild;
	}

	//checks to make sure each subtree maintains its heap proptery during heapify process
	if(largest != i)
	{
		//swaps node at i with one of it's children
		Swap(array + i*size, array + largest*size, size);
		//recursively calls itself
		heapify(array, size, heapSize, CompareFunc, largest);
	}
}	