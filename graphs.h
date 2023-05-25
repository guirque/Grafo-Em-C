#include <stdio.h>
#include <stdlib.h>
#include "listForGraphs.h"

// graph ---------------------------------------

typedef llist **graph; // graph (lista de arestas)

// Create graph structure, with chosen number of nodes / vertices
graph createGraph(int size) 
{ 
    graph newGraph = (graph)malloc(sizeof(llist **) * size); 
    for(int i = 0; i < size; i++)
    {
        newGraph[i] = NULL;
    }
    return newGraph;
}

// Insert Edge
void insertEdge(graph graph, int origin, int destination, int weight) {
  if (graph[origin] == NULL)
    graph[origin] = lcreate(destination, weight);
  else
    laddToStart(&graph[origin], destination, weight);
}

// Remove Edge
void removeEdge(graph graph, int origin, int destination, int weight) {
  lerase(&graph[origin], destination, weight);
}

// Print graph
void printGraph(graph graph, int tam) {
  for (int i = 1; i < tam; i++) {
    printf("%d: ", i);
    lprint(graph[i]);
    printf("\n");
  }
}