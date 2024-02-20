/*****************************************************************************
 * CMP_SC 3050
 * SP 2023
 * Assignment #2
 * main.c
 * By Jim Ries
 ******************************************************************************/

// Includes
#include <stdio.h>
#include "sort.h"

// Main entry point
int main(void)
{
	// Run the tests
	printf("\n\nHeap Sort:\n");
	printf("--------------\n");
	RunTests(heapsort, true);

	//printf("\n\nQuick Sort:\n");
	//printf("--------------\n");
	//RunTests(qsort, true);
}
