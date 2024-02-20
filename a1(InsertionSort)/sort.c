/*********************************************
*CMP_SC3050
*By Gianni Ioannou
*gci5k8
*Feburary 2,2024
*Assignment 1
*SS 2024
***********************************************/
#include <cs3050.h>
#include <stdio.h>
void bubblesort(void *array, 
				size_t nitems, 
				size_t size, 
				int (*CompareFunc)(const void *, const void*))
{
	for (int i=0;i<nitems;i++)
	{
		for (int j=0;j<nitems-1;j++)
		{
			void * item1 = array + j*size;
			void * item2 = array + (j+1)*size;
			if (CompareFunc(item1,item2)>0)
			{
				Swap(item1,item2,size);
			}
		}
	}
}

void insertionsort(void *array, 
				size_t nitems, 
				size_t size, 
				int (*CompareFunc)(const void *, const void*))
{
	//checks for null array, empty array or invalid size
	if (array==NULL || nitems==0 || size<= 0)
	{
		return;
	}
	//intilizing a temp variable to store the value of my key
	void * temp = malloc(size);
	//checking if malloc was successful 
	if(temp == NULL)
	{
		printf("Malloc Failed");
	}
	//start at index one and loop through the given array
	for(int i=1; i<nitems; i++)
	{
		//currentItem stores the key based off the iteration we are in
		void * currentItem = array + i*size;
		/*
		I then copy the value of the key into the temp variable becuase when the array shifts
		my key will get copied over so I need a way to keep track of it
		*/
		Copy(temp, currentItem, size);
		//int index to keep track of where I am in the array
		int index = i - 1;
		//checks to make sure I am not outside of array boundires and if previous item is greater than the key
		while(index>=0 && CompareFunc(array + index*size, temp)>0)
		{	//takes previous index and copies it to the index infront of it effictivley shifting the array right
			Copy(array + (index+1)*size, array + index*size, size);
			//decrementing index to properly check all indexes
			index = index - 1;
		}
		//I now copy the key into it's new correct position
		Copy(array + (index+1)*size, temp, size);
	}
	//freeing allocated memory
	free(temp);
}
