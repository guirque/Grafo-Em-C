#include <stdio.h>
#include "graphs.h"
#define pause int pause; scanf("%d", &pause);

int main()
{
    //Creating Graph
    graph graphExample = createGraph(4); 
    insertEdge(graphExample, 1, 2, 2);
    insertEdge(graphExample, 1, 3, 3);
    insertEdge(graphExample, 2, 1, 1);
    insertEdge(graphExample, 2, 3, 3);
    insertEdge(graphExample, 3, 1, 1);
    insertEdge(graphExample, 3, 2, 2);
    insertEdge(graphExample, 4, 2, 2);
    insertEdge(graphExample, 3, 4, 4);

    removeEdge(graphExample, 1, 2, 0);

    printf("-> Printing Created Graph -------------------\n");
    printGraph(graphExample);
    
    degree graugraphExample1 = vertexDegree(graphExample, 1);
    printf("\n-> Printing Graph Degree --------------------\n");
    printf("\n(Total) Degree: %d\nIndegree: %d\nOutdegree: %d\n", graugraphExample1.total, graugraphExample1.indegree, graugraphExample1.outdegree);
    
    printf("\n-> Is the Graph Complete? -------------------\n");
    printf("Is the graph complete? %d\n", isCompleteGraph(graphExample));
    
    printf("\n-> Printing Paths Between vertices ----------\n\n");
    printf("All paths between two chosen vertices:\n");
    printAllPaths(graphExample, 3, 1);
    printf("\"Cheapest\" Path between two chosen vertices: \n");
    printLowestWeightPath(graphExample, 3, 1);
    printf("Shortest path vetween two chosen vertices: \n");
    printShortestPath(graphExample, 3, 1);

    pause;
    return 0;
}