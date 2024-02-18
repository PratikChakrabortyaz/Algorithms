#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* graph[MAX_NODES];
int indegree[MAX_NODES];
int numNodes;

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
    indegree[dest]++; // Increment indegree of destination node
}

void topologicalSort() {
    int sorted[MAX_NODES];
    int sortedIndex = 0;

    // Find nodes with indegree 0 and add them to the sorted array
    for (int i = 0; i < numNodes; i++) {
        if (indegree[i] == 0) {
            sorted[sortedIndex++] = i;
        }
    }

    // Process nodes until there are no more with indegree 0
    while (sortedIndex < numNodes) {
        int nodeToRemove = -1;
        for (int i = 0; i < numNodes; i++) {
            if (indegree[i] == 0) {
                nodeToRemove = i;
                break;
            }
        }

        if (nodeToRemove == -1) {
            return;
        }

        printf("%d ", nodeToRemove);
        indegree[nodeToRemove] = -1; // Mark node as visited

        struct Node* temp = graph[nodeToRemove];
        while (temp != NULL) {
            indegree[temp->data]--; // Decrement indegree of adjacent nodes
            temp = temp->next;
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numNodes; i++) {
        graph[i] = NULL;
        indegree[i] = 0; // Initialize all indegrees to 0
    }

    printf("Enter the edges (format: node1 node2):\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        addEdge(node1, node2);
    }

    printf("Topological Sorting: ");
    topologicalSort();

    printf("\n");

    return 0;
}
