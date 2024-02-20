/*****************************************************************************
 * CMP_SC 3050
 * FS 2022
 * Assignment #1
 * main.c
 * By Jim Ries
 ******************************************************************************/

// Includes
#include <stdio.h>
#include "sort.h"

// Main entry point
int main(void)
{
	//Run the tests
	printf("\n\nBubble Sort:\n");
	printf("--------------\n");
	RunTests(bubblesort, true);

	printf("\n\nInsertion Sort:\n");
	printf("--------------\n");
	RunTests(insertionsort, true);

	printf("\n\nQuick Sort:\n");
	printf("--------------\n");
	RunTests(qsort, true);
}
