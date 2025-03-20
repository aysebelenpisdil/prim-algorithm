#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 9
enum { A, B, C, D, E, F, G, H, I };

int minKey(int key[], int mstSet[]){
    int min = INT_MAX, min_index = -1;
    for(int v = 0; v < V; v++){
        if(!mstSet[v] && key[v] < min){
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V]){
    int parent[V], key[V], mstSet[V];
    for(int i = 0; i < V; i++){
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int count = 0; count < V - 1; count++){
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for(int v = 0; v < V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printf("Edge \tWeight\n");
    for(int i = 1; i < V; i++){
        printf("%c - %c \t%d\n", 'A' + parent[i], 'A' + i, graph[i][parent[i]]);
    }
}

void addEdge(int graph[V][V], int src, int dest, int weight){
    graph[src][dest] = weight;
    graph[dest][src] = weight;
}

void printGraph(int graph[V][V]){
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
    printf("\nPrim MST:\n");
    primMST(graph);
    return 0;
}
