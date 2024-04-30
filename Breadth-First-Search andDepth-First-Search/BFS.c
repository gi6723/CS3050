#include "MUCSGraph.h"
#include "Queue.h"
#include "BFS.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s) 
{
    if (V == NULL || countV <= 0)
    {
        return;
    }
    //convert start node to be 0-based
    s = s - 1; 

    if (s < 0 || s >= countV)
    {
        return;
    }

    //create a queue
    Queue *q = createQueue(countV);
    if(q == NULL)
    {
        return;
    }
    
    //initialize the vertices
    for (int i = 0; i < countV; i++) 
    {
        V[i].color = WHITE;
        V[i].d = INT_MAX;
    }

    //initialize the start node as gray
    V[s].color = GRAY;
    //distance from start node to start node is 0
    V[s].d = 0;
    //enqueue the start node
    enqueue(q, s);

    printf("BFS: ");
    //while the queue is not empty
    while (!isEmpty(q)) 
    {
        //dequeue the next vertex to process
        int u = dequeue(q);
        //print current vertex and its distance from start
        printf("%d(%d) ", u + 1, V[u].d);

        //for each edge from the current vertex
        for (PAdjacency adj = V[u].list; adj != NULL; adj = adj->next) 
        {
            //Get the to vertex of the current edge
            int v = adj->pEdge->to - 1; 
            //if the to vertex has not been visited
            if (v != u && V[v].color == WHITE) 
            {
                //marking it as visited
                V[v].color = GRAY;
                //setting the distance of to vertex
                V[v].d = V[u].d + 1;
                //enqueue the to vertex
                enqueue(q, v);
            }

            //Get the from vertex of the current edge
            int w = adj->pEdge->from - 1; 
            //if the from vertex has not been visited
            if (w != u && V[w].color == WHITE) 
            {
                //marking it as visited
                V[w].color = GRAY;
                //setting the distance of from vertex
                V[w].d = V[u].d + 1;
                //enqueue the from vertex
                enqueue(q, w);
            }
        }
        //mark the vertex as fully proccessed
        V[u].color = BLACK;
    }
    printf("\n");

    //freeing allocated memory
    freeQueue(q);
}




