#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

//defining a stuct NODE for linked list 
typedef struct Node {
    void* key;
    void* data;
    struct Node* next;
} Node;

// These are stubs.  That is, you need to implement these functions.

int InsertFailCollision(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
    //checking for valid inputs
    if(hashtable == NULL || elementSize <= 0 || elementCountMax < 0 || element == NULL || HashFunc == NULL)
    {
        return -1;
    }

    //get the index from hash table
    int index = HashFunc(key);
    //casting hash table as a char pointer
    char* byteHashtable = (char*)hashtable;

    //creating an array to represent an empty slot 
    unsigned char emptySlot[elementSize];
    //filling slot with 0's
    memset(emptySlot, 0, elementSize);

    //checking if the slot is empty
    if(memcmp(byteHashtable + index * elementSize, emptySlot, elementSize) != 0)
    {
        return -1;
    }
    else
    {
        //copying the element into the hash table at the calculated index
        memcpy(byteHashtable + index * elementSize, element, elementSize);
    }
    return 0;
}

void * SearchNoCollision(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
    //checking for valid inputs 
    if(hashtable == NULL || elementSize <= 0 || HashFunc == NULL)
    {
        return NULL;
    }

    //get the index from hash table
    int index = HashFunc(key);
    //casting hash table as a char pointer
    char* byteHashtable = (char*)hashtable;

    //creating an array to represent an empty slot
    unsigned char emptySlot[elementSize];
    //filling slot with 0's
    memset(emptySlot, 0, elementSize);

    //checking if the slot is empty
    if(memcmp(byteHashtable + index * elementSize, emptySlot, elementSize) == 0)
    {
        return NULL;
    }
    else
    {
        //return the pointer to the data in the hashtable 
        return (void*)(byteHashtable + index * elementSize);
    }
}


int DivMethod(int key)
{
    int tableSize = TABLESIZE;
    //returns remainder as hash index
    return key % tableSize;
}

int MultMethod(int key)
{

    float CONSTANT = 0.6180339887;
    //multiplying key with constant
    float keyCONSTANT = key * CONSTANT;
    //getting fractional part
    float fraction = keyCONSTANT - floor(keyCONSTANT);
    //returning floor of fraction * table size
    return floor(TABLESIZE * fraction);
}


void * AllocateChainTable(int elementCountMax)
{
    //checking for valid input
    if (elementCountMax <= 0) {
        return NULL;
    }

    Node **chainTable = malloc(elementCountMax * sizeof(Node*));

    //returning NULL if malloc fails
    if (chainTable == NULL) {
        return NULL;
    }

    // Initialize all pointers to NULL
    for (int i = 0; i < elementCountMax; i++) {
        chainTable[i] = NULL;
    }
    return chainTable;
}

void FreeChainTable(void * hashtable)
{
    //checking for valid input
    if (hashtable == NULL) {
        return;
    }   

    //casting hashtable to node pointer
    Node **table = (Node **)hashtable;

    //freeing all the nodes in the table
    for (int i = 0; i < TABLESIZE; i++) {
        Node *currentNode = table[i];
        while (currentNode != NULL) {
            Node *nextNode = currentNode->next;
            free(currentNode->data);
            free(currentNode->key);
            free(currentNode);
            currentNode = nextNode;
        }
    }

    free(table);
}

int InsertChain(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
    //checks for valid inputs
    if(hashtable == NULL || elementSize <= 0 || elementCountMax < 0 || element == NULL || HashFunc == NULL)
    {
        return -1;
    }

    //casting hashtable to node for easier access
    Node **table = (Node **)hashtable;
    //calculating index
    int index = HashFunc(key);

    //allocating memory for a new node
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }

    //allocating memory for the data of the new node
    newNode->data = malloc(elementSize);
    if (newNode->data == NULL) {
        free(newNode);
        return -1;
    }

    //allocating memory for the key of the new node
    newNode->key = malloc(sizeof(int));
    if(newNode->key == NULL)
    {
        free(newNode->data);
        free(newNode);
        return -1;
    }

    //copying the element and key into the new node
    memcpy(newNode->data, element, elementSize);
    memcpy(newNode->key, &key, sizeof(int));
    //intilizing the next pointer to NULL
    newNode->next = NULL;

    //inser the new node into the table at the calculated index
    if(table[index] == NULL)
    {
        //if slot is empty place new node there
        table[index] = newNode;
    }
    else
    {
        //if slot is not empty iterate to the end of the linked list and insert the new node
        Node *currentNode = table[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    return 0;
}

void * SearchChain(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
    //checks to see if inputs are valid
    if(hashtable == NULL || elementSize <= 0 || HashFunc == NULL)
    {
        return NULL;
    }

    //casting hashtable to node for easier access
    Node **table = (Node **)hashtable;
    //calculating index
    int index = HashFunc(key);

    //get the firt node in the linked list at the calulated index
    Node *current = table[index];

    //iterating over linked list untill it finds the matching key 
    while (current != NULL) {
        if (*((int*)current->key) == key) {
            return current->data;
        }
        current = current->next;
    }
    //returns NULL if key is not found
    return NULL;
}