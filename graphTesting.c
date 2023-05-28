#include <stdio.h>
#include "graphs.h"
#define pause int pause; scanf("%d", &pause);

int main()
{
    //Creating Graph
    graph umGrafo = createGraph(4); 
    insertEdge(umGrafo, 1, 2, 2);
    insertEdge(umGrafo, 1, 3, 3);
    insertEdge(umGrafo, 2, 1, 1);
    insertEdge(umGrafo, 2, 3, 3);
    insertEdge(umGrafo, 3, 1, 1);
    insertEdge(umGrafo, 3, 2, 2);
    insertEdge(umGrafo, 4, 2, 2);
    insertEdge(umGrafo, 3, 4, 4);

    removeEdge(umGrafo, 1, 2, 0);

    printf("-> Printing Created Graph -------------------\n");
    printGraph(umGrafo);
    
    degree grauUmGrafo1 = vertexDegree(umGrafo, 1);
    printf("\n-> Printing Graph Degree --------------------\n");
    printf("\n(Total) Degree: %d\nIndegree: %d\nOutdegree: %d\n", grauUmGrafo1.total, grauUmGrafo1.indegree, grauUmGrafo1.outdegree);
    
    printf("\n-> Is the Graph Complete? -------------------\n");
    printf("Is the graph complete? %d\n", isCompleteGraph(umGrafo));
    
    printf("\n-> Printing Paths Between vertices ----------\n\n");
    printf("All paths between two chosen vertices:\n");
    printAllPaths(umGrafo, 3, 1);
    printf("\"Cheapest\" Path between two chosen vertices: \n");
    printLowestWeightPath(umGrafo, 3, 1);
    printf("Shortest path vetween two chosen vertices: \n");
    printShortestPath(umGrafo, 3, 1);
    pause;
    return 0;
}