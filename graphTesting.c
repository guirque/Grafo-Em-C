#include <stdio.h>
#include "graphs.h"
#define pause int pause; scanf("%d", &pause);

int main()
{
    graph umGrafo = createGraph(3);    // tres nos
    insertEdge(umGrafo, 1, 2, 0);  // 1 --0--> 2
    insertEdge(umGrafo, 1, 3, 10); // 1 --10--> 3

    printGraph(umGrafo, 3);
    printf("\n");
    //removeEdge(umGrafo, 1, 2, 0);
    removeEdge(umGrafo, 1, 3, 10);
    printGraph(umGrafo, 3);
    pause;
    return 0;
}