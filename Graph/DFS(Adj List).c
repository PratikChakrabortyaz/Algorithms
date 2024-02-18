#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* graph[MAX_NODES];
int visited[MAX_NODES];
int numNodes;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the adjacency list
void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;

    /*newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;*/
}

// Depth First Search recursive function
void DFS(int node) {
    printf("Pushing %d\n", node); // Print when pushing the node onto the stack
    printf("%d ", node);
    visited[node] = 1;

    struct Node* temp = graph[node];
    while (temp != NULL) {
        int adjNode = temp->data;
        if (!visited[adjNode]) {
            DFS(adjNode);
        }
        temp = temp->next;
    }

    printf("Popping %d\n", node); // Print when popping the node off the stack
}

int main() {
    int numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize adjacency list and visited array
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
        graph[i] = NULL;
    }

    // Input edges
    printf("Enter the edges (format: node1 node2):\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        addEdge(node1, node2);
    }

    printf("DFS Traversal starting from node 0: ");
    DFS(0); // Start DFS from node 0

    printf("\n");

    return 0;
}
