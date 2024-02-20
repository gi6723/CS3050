#ifndef _sort_h
#define _sort_h
#include <cs3050.h>
void heapsort(void *array, 
				size_t nitems, 
				size_t size, 
				int (*CompareFunc)(const void *, const void*));
#endif
