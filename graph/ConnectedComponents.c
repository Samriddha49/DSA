#include <stdio.h>
#include <stdlib.h>

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

// Function to perform Breadth First Search
void BFS(struct Graph* graph, int startNode) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    // Enqueue the starting node
    queue[rear++] = startNode;
    graph->visited[startNode] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = graph->adjacencyList[current];
        while (temp != NULL) {
            int adjNode = temp->value;
            if (!graph->visited[adjNode]) {
                queue[rear++] = adjNode;
                graph->visited[adjNode] = 1;
            }
            temp = temp->next;
        }
    }
}

// Function to initialize graph
void initGraph(struct Graph* graph, int numNodes) {
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Function to identify connected components
void findConnectedComponents(struct Graph* graph) {
    printf("Connected Components:\n");
    for (int i = 0; i < graph->numNodes; ++i) {
        if (!graph->visited[i]) {
            BFS(graph, i);
            printf("\n");
        }
    }
}

int main() {
    struct Graph graph;
    initGraph(&graph, 7); // Initialize the graph with 7 nodes

    // Add edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 5, 6);

    findConnectedComponents(&graph);

    return 0;
}
