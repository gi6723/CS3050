#ifdef DEBUG
#endif
#include <stdlib.h>
#include "bst.h"
#include<stdio.h>

// local functions

//recursively does InorderTreeWalk
void InOrderTreeWalk(NODE *node, NODEVISITFUNC func)
{
    //checks if current node is null
    if(node == NULL)
    {
        return;
    }
    else
    {
        //recursively calls left child
        InOrderTreeWalk(node->left, func);
        //proccesses current node's sattelite data
        func(node->satellite);
        //recurisvley calls right child
        InOrderTreeWalk(node->right, func);
    }
}

//recursively does PreorderTreeWalk
void PreOrderTreeWalk(NODE *node, NODEVISITFUNC func)
{
    //checks if current node is null
    if(node == NULL) 
    {
        return;
    }
    else
    {
        //processes current node's data
        func(node->satellite);
        //recusrively calls left child
        PreOrderTreeWalk(node->left, func);
        //recursivley calls right child
        PreOrderTreeWalk(node->right, func);
    } 
}

//recursively does PostorderTreeWalk
void PostOrderTreeWalk(NODE *node, NODEVISITFUNC func)
{
    //check if node is null
    if(node == NULL) 
    {
        return;
    }
    else
    {
        //recursively calls left child
        PostOrderTreeWalk(node->left, func);
        //recusrivley calls right child
        PostOrderTreeWalk(node->right, func);
        //processes current nodes data
        func(node->satellite);
    }
}


//transplant fro treeDelete function
void transplant(BST *pBST, NODE *u, NODE *v) {
    //checks if u is the root
    if (u->parent == NULL) 
    {
        //sets v as the new root if u was root
        pBST->root = v;
    } 
    //checks is u is a left child
    else if (u == u->parent->left) 
    {
        //sets v as the new left child of u's parent
        u->parent->left = v;
    } 
    //check if u is right child
    else 
    {
        //sets v as new right child of u's parent
        u->parent->right = v;
    }
    //checks if v is null
    if (v != NULL)  
    {
        //makes v's parent to u's parent
        v->parent = u->parent;
    }
}
// These are stubs.  That is, you need to implement these functions.

BST * NewBST() //xxx
{
    //allocates memory for bst
    BST *pBST = (BST *)malloc(sizeof(BST));
    //checks for successful allocation
    if(pBST == NULL)
    {
        return NULL;
    }
    //sets root to null
    pBST->root = NULL;
    //returns new bst
    return pBST;
}

void TreeInsert(BST * pBST, void * satellite, long long key) { //xxx
    //checks if bst is null
    if (pBST == NULL) 
    {
        return;
    }

    //allocated memory for new node
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    //checks for successful allocation
    if (newNode == NULL) 
    {
        return;
    }

    //sets newNodes data
    newNode->satellite = satellite;
    newNode->key = key;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;

    //checks if BST is empty
    if (pBST->root == NULL) 
    {
        //makes new node root
        pBST->root = newNode;
        return;
    }
    //starts from root of BST
    NODE *currentNode = pBST->root;
    // initilizes parent pointer for new node
    NODE *parent = NULL;

    //traverses tree to find correct location for node
    while (currentNode != NULL) 
    {
        //updates parent pointer
        parent = currentNode;
        //moves left if new key is smaller than current nodes key
        if (key < currentNode->key) 
        {
            currentNode = currentNode->left;
        } 
        //moves right if new key is greater or equal to the current nodes key
        else 
        {
            currentNode = currentNode->right;
        }
    }

    //sets parent of new node
    newNode->parent = parent;

    //Insert new node as left child if its key is smaller than parents key
    if (key < parent->key) 
    {
        parent->left = newNode;
    } 
    //Inserts new node as right child if its key is greater or equal to parents key
    else 
    {
        parent->right = newNode;
    }
}


void InOrder(BST * p, NODEVISITFUNC func) //xxx
{
    //checks if BST is null
    if(p == NULL)
    {
        return;
    }
    //calls helper function to perfrom in-order traversal 
    else
    {
        InOrderTreeWalk(p->root, func);
    }
}


void PreOrder(BST * pBST, NODEVISITFUNC func) //xxx
{
    //checks if BST is null
    if(pBST == NULL)
    {
        return;
    }
    //calls helper function to perform pre-order traversal
    else
    {
        PreOrderTreeWalk(pBST->root, func);
    }
}

void PostOrder(BST * pBST, NODEVISITFUNC func) //xxx
{
    //checks if BST is null 
    if(pBST == NULL)
    {
        return;
    }
    //calls helper function to perform post-order tree walk 
    else
    {
        PostOrderTreeWalk(pBST->root, func);
    }
}

void * Search(BST * pBST, long long key)
{
    //checks if BST is null
    if(pBST == NULL)
    {
        return NULL;
    }
    //starts from root of tree
    NODE * currentNode = pBST->root;

    //traverses tree to find the node
    while(currentNode != NULL)
    {
        //if key is found returns satellite data 
        if(key == currentNode->key)
        {
            return currentNode->satellite;
        }
        //moves left is key is smaller than current nodes key
        else if(key < currentNode->key)
        {
            currentNode = currentNode->left;
        }
        //moves right if key is greater than current nodes key
        else
        {
            currentNode = currentNode->right;
        }
    }
    //returns NULL if nothings found 
    return NULL;
}

void TreeDelete(BST *pBST, long long key) {
    //starts from root of BST
    NODE *z = pBST->root;
    //traverses tree to find node with given key
    while (z != NULL && z->key != key) 
    {
        //move left if key is smaller than current nodes key
        if (key < z->key) 
        {
            z = z->left;
        } 
        //moves right is key is greater than current nodes key
        else 
        {
            z = z->right;
        }
    }

    //if node to delete isn't fount we just return 
    if (z == NULL)
    {
        return; 
    } 

    //if node has no left child transplant its right child
    if (z->left == NULL) 
    {
        transplant(pBST, z, z->right);
    } 
    //if node has no right child transplant its left child
    else if (z->right == NULL) 
    {
        transplant(pBST, z, z->left);
    } 
    //if node has two childre
    else 
    {
        //find the minimum node in right subtree
        NODE *y = z->right;
        while (y->left != NULL) 
        {
            y = y->left;
        }

        //if successor is not the direct child of the node to be deleted...
        if (y->parent != z) 
        {
            //transplant the successor with its right child
            transplant(pBST, y, y->right);
            //attach the right subtree of the node to be deleted to its successor
            y->right = z->right;
            //set the parent of the right subtree to be the successor
            y->right->parent = y;
        }
        //replace node to be deleted with its successor in the bst
        transplant(pBST, z, y);
        //atach left subtree of z to y
        y->left = z->left;
        //sets parent of left subtree to be y
        y->left->parent = y;
    }
    // Free the memory of the deleted node
    free(z); 
}


