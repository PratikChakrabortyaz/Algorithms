#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* graph[MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;
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
}

// Function to add a node to the queue
void enqueue(int node) {
    if (rear == MAX_NODES - 1) {
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = node;
}

// Function to remove a node from the queue
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    int node = queue[front];
    front++;
    return node;
}

// Breadth First Search traversal function
void BFS(int start) {
    enqueue(start); // Enqueue the starting node
    visited[start] = 1; // Mark starting node as visited

    while (front != -1) {
        int current = dequeue(); // Dequeue a node

        if (current == -1) {
            break; // Break the loop if the queue is empty
        }

        printf("%d ", current); // Print the dequeued node

        // Visit all adjacent nodes of the dequeued node
        struct Node* temp = graph[current];
        while (temp != NULL) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                enqueue(adjNode); // Enqueue adjacent node if not visited
                visited[adjNode] = 1; // Mark adjacent node as visited
            }
            temp = temp->next;
        }
    }
}

int main() {
    int numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
        graph[i] = NULL;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Input edges
    printf("Enter the edges (format: node1 node2):\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        addEdge(node1, node2);
    }

    int start;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    printf("\n");

    return 0;
}
