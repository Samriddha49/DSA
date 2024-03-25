#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure to represent a node in the graph
struct Node {
    int value;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numNodes;
    struct Node* adjacencyList[MAX_NODES];
    int visited[MAX_NODES];
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to perform Depth First Search
bool DFS(struct Graph* graph, int current, int parent) {
    graph->visited[current] = 1;

    struct Node* temp = graph->adjacencyList[current];
    while (temp != NULL) {
        int adjNode = temp->value;

        if (!graph->visited[adjNode]) {
            if (DFS(graph, adjNode, current))
                return true;
        } else if (adjNode != parent) {
            return true;
        }

        temp = temp->next;
    }
    return false;
}

// Function to detect cycles in the graph
bool detectCycle(struct Graph* graph) {
    for (int i = 0; i < graph->numNodes; ++i) {
        if (!graph->visited[i]) {
            if (DFS(graph, i, -1))
                return true;
        }
    }
    return false;
}

// Function to initialize graph
void initGraph(struct Graph* graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
}

int main() {
    struct Graph graph;
    initGraph(&graph, 6); // Initialize the graph with 6 nodes

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 0);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 5);

    if (detectCycle(&graph))
        printf("The graph contains a cycle.\n");
    else
        printf("The graph does not contain any cycle.\n");

    return 0;
}
