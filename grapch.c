#include <stdio.h>
#include <stdlib.h>
#define V 9
enum { A, B, C, D, E, F, G, H, I }; //enumeration assigns integer values to the vertex labels

void addEdge(int graph[V][V], int src, int dest, int weight) {
    graph[src][dest] = weight;
    graph[dest][src] = weight; //It updates the matrix in both directions (graph[src][dest] and graph[dest][src]) because the graph is undirected
}

void printGraph(int graph[V][V]) {
    int i, j;
    printf("    ");
    for(i = 0; i < V; i++)
        printf("%4c", 'A' + i);
    printf("\n");
    for(i = 0; i < V; i++){
        printf("%c | ", 'A' + i);
        for(j = 0; j < V; j++){
            if(graph[i][j] == 0)
                printf("%4c", '.');
            else
                printf("%4d", graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int graph[V][V] = {0};
    addEdge(graph, A, B, 4);
    addEdge(graph, A, H, 8);
    addEdge(graph, B, C, 8);
    addEdge(graph, B, H, 11);
    addEdge(graph, C, D, 7);
    addEdge(graph, C, I, 2);
    addEdge(graph, C, F, 4);
    addEdge(graph, D, E, 9);
    addEdge(graph, E, F, 10);
    addEdge(graph, F, G, 2);
    addEdge(graph, G, H, 1);
    addEdge(graph, G, I, 6);
    printGraph(graph);
    return 0;
}
