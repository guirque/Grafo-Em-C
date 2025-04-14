#include <stdio.h>
#include <stdlib.h>
#include "listForGraphs.h"
#define INT_MAX 2147483647

// graph ---------------------------------------

typedef llist **graph; // graph

// Create graph structure, with chosen number of nodes / vertices
graph createGraph(int size) 
{ 
    graph newGraph = (graph)malloc(sizeof(llist **) * (size+1)); 
    llist* storeMemory = (llist*)malloc(sizeof(llist));
    storeMemory->weight = size;
    newGraph[0] = storeMemory;
    newGraph[0]->weight = size;
    for(int i = 1; i <= size; i++)
    {
        newGraph[i] = NULL;
    }//size + 1 because position 0 is used in order to make index positions more intuitive, and to store the graph size.
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
void printGraph(graph graph) {
  for (int i = 1; i <= graph[0]->weight; i++) {
    printf("%d: ", i);
    lprint(graph[i]);
    printf("\n");
  }
}

//Graph Degree
//Returns a struct with 3 values: the amount of edges ponting to the vertex, the ones coming from the vertex to the outside and the total degree (sum of the two)
  typedef struct degree
  {
    int indegree;
    int outdegree;
    int total;
  } degree;
struct degree vertexDegree(graph aGraph, int vertex)
{
  struct degree answer;
  answer.indegree = 0;
  answer.outdegree = 0;

  //For each vertex in graph
  for(int i = 1; i <= aGraph[0]->weight; i++)
  {
    llist *currentvertex = aGraph[i];
    int countindegree = 0; //bool

    if(i == vertex) countindegree = 1;
    //For each edge in the currentvertex
    for(llist* j = currentvertex; j != NULL; j = j->next)
    {
      if(j->destination == vertex) answer.indegree++;
      if(countindegree) answer.outdegree++;
    }
  }
    answer.total = answer.indegree + answer.outdegree;
    return answer;
}

//Analyzes if a simple (undirected) graph is complete.
int isCompleteGraph(graph aGraph)
{
  int complete = 1; //bool 
  int size = 0;
  int lowestNumOfEdges = 0; //If lowest number of edges of a node is equal to size-1, then the graph is complete.

  //If a vertex isn't connected to all other vertices, the graph isn't complete.
  //Simple graphs can't have self-loops. Undirected graphs don't allow vertices to have more than one edge with another vertex. 
  //In order to represent an edge between to nodes with this structure, the programmer must set an edge in both directions between those nodes.

  //For each vertex
  for(int i = 1; i <= aGraph[0]->weight; i++)
  {
    size++;
    
    //For each 
    int numOfEdges = 0;;
    for(llist* j = aGraph[i]; j != NULL; j = j->next)
    {
      numOfEdges++;
    }
    if(numOfEdges <  lowestNumOfEdges || i == 1) lowestNumOfEdges = numOfEdges;
  }

  return lowestNumOfEdges == size-1;
}

void printAllPathsR(graph aGraph, int origin, int destination, int position, int v[], int* foundPath)
{
  //Stop if origin is equal to destination (finishing for loop will also cause it to stop)
  if(origin != destination)
  {
    //Call the same function for different paths beginning in this origin (iterate through list)
    for(llist* i = aGraph[origin]; i != NULL; i = i->next)
    {
      //Add this origin to path array (v)
      v[position] = origin;
      
      //Keep checking if there's another path, now beginning in the destination
      //Make sure the new origin is not a vertex that has already been visited
      int newOrigin = 1;
      for(int checkV = 0; checkV < position; checkV++) 
        if(v[checkV] == i->destination) newOrigin = 0;

      if(newOrigin) printAllPathsR(aGraph, i->destination, destination, position + 1, v, foundPath);
    }
  }
  else
  {
    //Now print it
    printf("[");
    for(int i = 0; i < position; i++)
    {
      if(i != position - 1) printf("%d -> ", v[i]);
      else printf("%d -> %d]\n", v[i], destination);
    }
    *foundPath = 1;
  }
}

//Prints all paths between an origin and its destination.
int printAllPaths(graph aGraph, int origin, int destination)
{
  int *v = (int*)malloc(sizeof(int) * aGraph[0]->weight);
  int foundPath = 0;
  printAllPathsR(aGraph, origin, destination, 0, v, &foundPath);
  free(v);

  if(foundPath) return 1;
  else return 0;
}

void printLowestWeightPathR(graph aGraph, int origin, int destination, int position, int v[], int totalWeight, int* lowestWeight, int* answer, int* foundPath)
{
  //Stop if origin is equal to destination (finishing for loop will also cause it to stop)
  if(origin != destination && position < aGraph[0]->weight)
  {
    //Call the same function for different paths beginning in this origin (iterate through list)
    for(llist* i = aGraph[origin]; i != NULL; i = i->next)
    {
      //Add this origin to path array (v)
      v[position] = origin;
      
      //Keep checking if there's another path, now beginning in the destination
      //Make sure the new origin is not a vertex that has already been visited
      int newOrigin = 1;
      for(int checkV = 0; checkV < position; checkV++) 
        if(v[checkV] == i->destination) newOrigin = 0;

      //vertex to be visited is new and the total weight won't exceed the lowest found so far
      if(newOrigin) printLowestWeightPathR(aGraph, i->destination, destination, position + 1, v, totalWeight+i->weight, lowestWeight, answer, foundPath);
    }
  }
  else
  {
    //Path done
    if(totalWeight < *lowestWeight && position < aGraph[0]->weight) 
    {
      *lowestWeight = totalWeight;
      //printf("Lowest weight found: %d\n", *lowestWeight);
      v[position] = -1;
      
      //Copy answer to array
      for(int i = 0; i <= position; i++)
      {
        answer[i] = v[i];
      }
      
      *foundPath = 1;
    }
  }
}

//Prints the path of lowest total weight between an origin and its destination
int printLowestWeightPathBacktrack(graph aGraph, int origin, int destination)
{
  int *v = (int*)malloc(sizeof(int) * aGraph[0]->weight);
  int *answer = (int*)malloc(sizeof(int) * (aGraph[0]->weight + 1));
  int lowestWeight = INT_MAX;
  int foundPath = 0;
  printLowestWeightPathR(aGraph, origin, destination, 0, v, 0, &lowestWeight, answer, &foundPath); //returns array of lowest total weight
  
  //Now print it
  if(foundPath){
    printf("total: %d\n[", lowestWeight);
    int i = 0;
    for(; answer[i] != -1; i++)
    {
      printf("%d -> ", answer[i]);
    }
    printf("%d]\n", destination);
  }
  
  free(v); free(answer);

  if(foundPath) return 1;
  else return 0;
}

void printShortestPathR(graph aGraph, int origin, int destination, int position, int v[], int* shortestPath, int* answer, int* foundPath)
{
  //Stop if origin is equal to destination (finishing for loop will also cause it to stop)
  if(origin != destination && position < aGraph[0]->weight)
  {
    //Call the same function for different paths beginning in this origin (iterate through list)
    for(llist* i = aGraph[origin]; i != NULL; i = i->next)
    {
      //Add this origin to path array (v)
      v[position] = origin;
      
      //Keep checking if there's another path, now beginning in the destination
      //Make sure the new origin is not a vertex that has already been visited
      int newOrigin = 1;
      for(int checkV = 0; checkV < position; checkV++) 
        if(v[checkV] == i->destination) newOrigin = 0;

      //vertex to be visited is new
      if(newOrigin) printShortestPathR(aGraph, i->destination, destination, position + 1, v, shortestPath, answer, foundPath);
    }
  }
  else
  {
    //Path done
    if(position+1 < *shortestPath && position < aGraph[0]->weight) 
    {
      *shortestPath = position+1;
      //printf("Lowest weight found: %d\n", *lowestWeight);
      v[position] = -1;
      
      //Copy answer to array
      for(int i = 0; i <= position; i++)
      {
        answer[i] = v[i];
      }
      *foundPath = 1;
    }
  }
}

// Returns graph size (number of nodes, other than the special node 0).
int getGraphSize(graph aGraph)
{
  return aGraph[0]->weight;
}

// Prints the shortest path between an origin and its destination.
// Returns 1 if path was found. 0, otherwise.
int printShortestPath(graph aGraph, int origin, int destination)
{
  int *v = (int*)malloc(sizeof(int) * aGraph[0]->weight);
  int *answer = (int*)malloc(sizeof(int) * (aGraph[0]->weight + 1));
  int shortestPath = INT_MAX;
  int foundPath = 0;
  printShortestPathR(aGraph, origin, destination, 0, v, &shortestPath, answer, &foundPath); //returns array of lowest total weight
  
  //Now print it, if a result was found
  if(foundPath){
    printf("total: %d\n[", shortestPath);
    int i = 0;
    for(; answer[i] != -1; i++)
    {
      printf("%d -> ", answer[i]);
    }
    printf("%d]\n", destination);
  }
  
  free(v); free(answer);

  if(foundPath) return 1;
  else return 0;
}

//Prints the path of lowest total weight between an origin and its destination. Uses the Dijkstra algorithm.
// Returns 1 if path was found. 0, otherwise.
int printLowestWeightPath(graph aGraph, int origin, int destination)
{
  // Variables
  // List of visited nodes
  // List of minimum weight between nodes (algorithm output)
  // Each node has an associated previous node (which gave it its minimum total weight), stored in a list.
  
  // Algorithm
  // We will iterate through every node. On every iteration, we'll analyze the node with lowest distance to the origin that hasn't been analyzed yet.
  // On every iteration, we will check the neighbors of the current node and update their distances if we can find lower paths.
  // The current distance to compare will be the node's cost + the distance to the destination node.

  // PS.: nodes start on 1, since node 0 is a special node.

  int VERBOSE = 0;

  // Setting up variables -------------------------
  int graphSize = getGraphSize(aGraph);
  if(destination > graphSize || origin > graphSize || origin < 1 || destination < 1) return 0;
  
  int* minimumWeightsToNodes = (int*)malloc(sizeof(int)*(graphSize+1)); // distance between origin and each node (determined by index).
  for(int i = 0; i < graphSize+1; i++) minimumWeightsToNodes[i] = INT_MAX; //distance to other nodes starts as inf (or, in this case, INT_MAX).
  minimumWeightsToNodes[origin] = 0; //distance to origin is 0.

  int* visitedNodes = (int*)malloc(sizeof(int)*(graphSize+1)); // 1 if visited. 0 if not. Index is the node id.
  for(int i = 0; i < graphSize+1; i++) visitedNodes[i] = 0; // every node starts unvisited.

  int* prev = (int*)malloc(sizeof(int)*(graphSize+1)); // Index is the node id.
  for(int i = 0; i < graphSize+1; i++) prev[i] = 0; // every node starts with prev = 0.

  // Algorithm ------------------------------------
  for(int i = 1; i < graphSize+1; i++)
  {
    // Get node with lowest minimum total weight value (could be updated to ease finding it)
    int lowestIndex = origin; // lowest total weight index to unvisited node
    int chosen = 0;
    for(int j = 1; j < graphSize+1; j++)
    {
      if(!visitedNodes[j] && (!chosen || minimumWeightsToNodes[j] <= minimumWeightsToNodes[lowestIndex])) {lowestIndex = j; chosen = 1;}
    }
    int currentNodeIndex = lowestIndex;
    if(VERBOSE) printf("\n- Visiting node %d\n", currentNodeIndex);

    // Check all paths from it to nearby nodes
    for(llist* currentNeighborEdge = aGraph[currentNodeIndex]; currentNeighborEdge != NULL; currentNeighborEdge = currentNeighborEdge->next)
    {
      // Updating minimum total weights
      int newWeight = INT_MAX;
      if(minimumWeightsToNodes[currentNodeIndex] != INT_MAX) newWeight = minimumWeightsToNodes[currentNodeIndex] + currentNeighborEdge->weight; //comparison to avoid scenarios of nodes that can't be reached by origin but have a one-way edge to a reachable node (resulting in INT_MAX + edge weight).
      
      if(VERBOSE)
      {
        printf("  - Checking neighbor %d, of minimum known total weight = %d\n", currentNeighborEdge->destination, minimumWeightsToNodes[currentNeighborEdge->destination]);
        printf("    - New weight would be: %d\n", newWeight);
        printf("    - Worth it? %d\n", newWeight < minimumWeightsToNodes[currentNeighborEdge->destination]);
      }
      
      if(newWeight < minimumWeightsToNodes[currentNeighborEdge->destination]) 
      {
        minimumWeightsToNodes[currentNeighborEdge->destination] = newWeight; //update minimum weight
        prev[currentNeighborEdge->destination] = currentNodeIndex; //update prev
      }

    }

    visitedNodes[currentNodeIndex] = 1;
  }

  int minimunWeight = minimumWeightsToNodes[destination];
  int pathFound = minimunWeight != INT_MAX;
  if(pathFound)
  {
    printf("Dijkstra minimum total weight from node %d to node %d: %d\n", origin, destination, minimunWeight);
    printf("Minimum path: [%d", destination);
    
    // Could use a stack
    // Go from destination to origin, using the prev values to get the path.
    for(int previousNode = prev[destination];  previousNode != 0; previousNode = prev[previousNode])
    {
      printf(" <- %d", previousNode);
    }
    printf("]");
  }
  
  free(minimumWeightsToNodes);
  free(visitedNodes);
  free(prev);

  return pathFound;
}