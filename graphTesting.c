#include <stdio.h>
#include "graphs.h"
#define pause int pause; scanf("%d", &pause);

int main()
{
    //Creating Graph
    graph graphExample = createGraph(5); 
    insertEdge(graphExample, 1, 2, 2);
    insertEdge(graphExample, 1, 3, 3);
    insertEdge(graphExample, 2, 1, 1);
    insertEdge(graphExample, 2, 3, 3);
    insertEdge(graphExample, 3, 1, 3);
    insertEdge(graphExample, 3, 2, 2);
    insertEdge(graphExample, 4, 2, 2);
    insertEdge(graphExample, 3, 4, 4);
    insertEdge(graphExample, 5, 3, 0);
    insertEdge(graphExample, 3, 5, 0);
    insertEdge(graphExample, 5, 1, 1);
    insertEdge(graphExample, 2, 5, 1);

    removeEdge(graphExample, 1, 2, 0);

    printf("-> Printing Created Graph -------------------\n");
    printGraph(graphExample);
    
    degree graphExampleDegree = vertexDegree(graphExample, 1);
    printf("\n-> Printing Graph Degree --------------------");
    printf("\n(Total) Degree: %d. Indegree: %d. Outdegree: %d\n", graphExampleDegree.total, graphExampleDegree.indegree, graphExampleDegree.outdegree);
    
    printf("\n-> Is the Graph Complete? -------------------\n");
    printf("Is the graph complete? %d\n", isCompleteGraph(graphExample));
    
    printf("\n-> Printing Paths Between vertices ----------\n\n");
    int vertex1 = 3, vertex2 = 1;

    printf("All paths between vertices %d and %d:\n", vertex1, vertex2);
    printAllPaths(graphExample, vertex1, vertex2);
    printf("\"Cheapest\" Path between %d and %d: \n", vertex1, vertex2);
    printLowestWeightPath(graphExample, vertex1, vertex2);
    printf("Shortest path between vertices %d and %d: \n", vertex1, vertex2);
    printShortestPath(graphExample, vertex1, vertex2);
    printf("\n");

    pause;
    return 0;
}