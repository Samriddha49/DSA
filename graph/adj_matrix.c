#include <stdio.h>

#define MAX_NODES 100

// Function to initialize adjacency matrix
void initGraph(int graph[][MAX_NODES], int numNodes) {
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            graph[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int graph[][MAX_NODES], int src, int dest) {
    graph[src][dest] = 1;
    graph[dest][src] = 1; // Assuming undirected graph
}

// Function to print adjacency matrix
void printGraph(int graph[][MAX_NODES], int numNodes) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numNodes = 5; // Number of nodes in the graph
    int graph[MAX_NODES][MAX_NODES];

    // Initialize the graph
    initGraph(graph, numNodes);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Print the adjacency matrix
    printGraph(graph, numNodes);

    return 0;
}
