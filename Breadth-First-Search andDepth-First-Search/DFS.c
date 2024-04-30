#include "MUCSGraph.h"
#include "DFS.h"
#include <stdio.h>
#include <stdlib.h>

void PrintDFS(Vertex * V, int countV, Edge * E, int countE);
void DFSVisit(Vertex * V, int u, int countV);

static int time; 

void PrintDFS(Vertex * V, int countV, Edge * E, int countE) 
{
    if(V == NULL || countV <= 0)
    {
        return;
    }
    
    //initialize the vertices
    for (int i = 0; i < countV; i++) 
    {
        V[i].color = WHITE;
        V[i].d = 0;
        V[i].f = 0;
        V[i].predecessor = -1;  
    }

    //resetting gloabl timer 
    time = 0;  
    printf("DFS: ");
    //if first vertex is unvisitied
    if (V[0].color == WHITE) 
    {
        //visit it
        DFSVisit(V, 0, countV);
    }
    //loop to make sure all vertices are visited
    for (int i = 1; i < countV; i++) 
    {
        if (V[i].color == WHITE) 
        {
            //preforming DFS on unvisited vertices
            DFSVisit(V, i, countV);
        }
    }
    printf("\n");
}

void DFSVisit(Vertex * V, int u, int countV) 
{
    //incrementing gloabl time counter
    V[u].d = ++time;  
    //marking vertex u as currently being explored
    V[u].color = GRAY;  

    //Iteratie through all adjacent vertices of vertex u
    for (PAdjacency adj = V[u].list; adj != NULL; adj = adj->next) 
    {
        //convert the to vertex to be 0-based
        int v = adj->pEdge->to - 1;  
        //if the to vertex has not been visited
        if (V[v].color == WHITE) 
        {
            //setting predevvessor of vertex v to u
            V[v].predecessor = u;  
            //recursively visiting vertex v
            DFSVisit(V, v, countV);
        }
        
        //converting the from vertex index to be 0-based
        int w = adj->pEdge->from - 1;
        //check if from vertex is different from to vertex an has not been visited
        if (w != v && V[w].color == WHITE) 
        {
            //set the predecessor of vertex w to u
            V[w].predecessor = u;
            //recursively visit vertex w 
            DFSVisit(V, w, countV);
        }
    }

    //after exploring all adjacent verticies color marking vertex u as complete
    V[u].color = BLACK;  
    //Increment the global time counter and assign it as the finish time  of vertex u
    V[u].f = ++time;  
    printf("%d(%d) ", u + 1, V[u].f);  
}




