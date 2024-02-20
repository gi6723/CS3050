#ifndef _cs3050_h
#define _cs3050_h
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Prototypes
void Swap(void * pItem1, void * pItem2, size_t itemsize);
void Copy(void * pDestItem, void * pSourceItem, size_t itemsize);
void RunTests(	void (*sortfunc)
						(	void *array, 
							size_t count_elements, 
							size_t size_element,
							int (*CompareFunc)(const void *, const void*)),
				bool fVerbose);

#endif
