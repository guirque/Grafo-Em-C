#include <stdio.h>
#include "graphs.h"
#define pause int pause; scanf("%d", &pause);

int main()
{
    int stop = 0;
    int size = 0;

    printf("==================================================\n");
    printf("| Welcome!\n|\n");
    printf("| Please choose a graph size to begin. Graphs ids begin on number 1. \n| Number of nodes: ");
    scanf("%d", &size);

    graph aGraph = createGraph(size); 
    
    while(!stop)
    {

        int option = 0;

        system("clear");
        printf("==================================================\n");
        printf("| Current Graph ----------------------------------\n");
        printGraph(aGraph);
        printf("| Actions ----------------------------------------\n");
        printf("| 1. Add edge;\n| 2. Remove edge;\n| 3. Get lowest total weight between nodes and its corresponding path (Dijkstra);\n| 4. Check if graph is complete;\n| 5. Exit.");
        printf("\n| Option: ");
        scanf("%d", &option);

        int sourceNode, destNode, weight, res = 0;
        switch (option)
        {
            case 1:
                printf("| Source node: ");
                scanf("%d", &sourceNode);
                printf("| Destination node: ");
                scanf("%d", &destNode);
                printf("| Weight: ");
                scanf("%d", &weight);
                insertEdge(aGraph, sourceNode, destNode, weight);
                printf("Done!");
                break;
            case 2:
                printf("| Source node: ");
                scanf("%d", &sourceNode);
                printf("| Destination node: ");
                scanf("%d", &destNode);
                printf("| Weight: ");
                scanf("%d", &weight);
                removeEdge(aGraph, sourceNode, destNode, weight);
                printf("Done!");
                break;
            case 3:
                printf("| Source node: ");
                scanf("%d", &sourceNode);
                printf("| Destination node: ");
                scanf("%d", &destNode);
                res = printLowestWeightPath(aGraph, sourceNode, destNode);
                if(res) printf("\nDone!");
                else printf("No path was found.");
                break;
            case 4:
                res = isCompleteGraph(aGraph);
                if(res) printf("Yes.");
                else printf("No.");
                break;
            default:
                stop = 1;
                break;
        }

        if(!stop)
        {
            printf("\n| Insert a character to continue...");
            pause;
            getchar();
        }
    }
}