#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* graph[MAX_NODES];
int visited[MAX_NODES];
int numNodes;
int stack[MAX_NODES];
int top = -1;

struct Node* newNode(int node) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = node;
    newnode->next = NULL;
    return newnode;
}

void addEdge(int src, int dest) {
    struct Node* newnode = newNode(dest);
    newnode->next = graph[src];
    graph[src] = newnode;
}

void push(int node) {
    stack[++top] = node;
}

int pop() {
    return stack[top--];
}

void dfs(int node) {
    visited[node] = 1;
    struct Node* temp = graph[node];
    while (temp != NULL) {
        int adjNode = temp->data;
        if (!visited[adjNode]) {
            dfs(adjNode);
        }
        temp = temp->next;
    }
    push(node); // Push node onto the stack after visiting all its neighbors
}

void topologicalSort() {
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    printf("Topological Sorting: ");
    while (top != -1) {
        printf("%d ", pop()); // Pop nodes from the stack to get the topological order
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
        graph[i] = NULL;
    }

    printf("Enter the edges (format: node1 node2):\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        addEdge(node1, node2);
    }

    topologicalSort();

    printf("\n");

    return 0;
}
