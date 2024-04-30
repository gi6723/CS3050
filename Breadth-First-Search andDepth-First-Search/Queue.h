#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdbool.h>

#ifdef __cplusplus
extern "C" 
{
#endif

// Data types
typedef struct {
    int *items;     
    int front;      
    int rear;       
    int maxSize;   
    int currentSize; 
} Queue;

// Prototypes
Queue* createQueue(int size);
void enqueue(Queue *q, int element);
bool isEmpty(Queue *q);
int dequeue(Queue *q);
void freeQueue(Queue *q);
#ifdef __cplusplus
}
#endif

#endif