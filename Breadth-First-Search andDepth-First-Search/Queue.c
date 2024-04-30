#include "Queue.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//create and intitialize a new queue with a specified size
Queue* createQueue(int size)
{
    Queue *q = malloc(sizeof(Queue));
    q->items = malloc(sizeof(int)*size);
    q->maxSize = size;
    q->front = -1;
    q->rear = -1;
    q->currentSize = 0;

    return q;
}

//function to check if the queue is empty
bool isEmpty(Queue *q)
{
    bool empty = q->currentSize == 0;
    return empty;
}

//function to add an element to the rear of the queue 
void enqueue(Queue *q, int element)
{

    if(q->currentSize == q->maxSize)
    {
        return;
    }

    if(q->front == -1)
    {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % q->maxSize; 
    q->items[q->rear] = element;
    q->currentSize++;


}

//remove and return the element at the front of the queue
int dequeue(Queue *q) 
{
    if (isEmpty(q)) 
    {
        return -1;
    }

    int item = q->items[q->front];
    q->front = (q->front + 1) % q->maxSize; 
    q->currentSize--;

    if (q->currentSize == 0) 
    {  
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

//freeing the memory allocated for the queue
void freeQueue(Queue *q)
{
    free(q->items);
    free(q);
}