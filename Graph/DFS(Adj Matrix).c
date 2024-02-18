#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int numNodes;

void DFS(int node) {
    printf("Pushing %d\n", node); // Print when pushing the node onto the stack
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < numNodes; i++) {
        if (graph[node][i] && !visited[i]) {
            DFS(i);
        }
    }

    printf("Popping %d\n", node); // Print when popping the node off the stack
}

int main() {
    int numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize graph matrix and visited array
    for (int i = 0; i < numNodes; i++) {
        visited[i] = 0;
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    printf("Enter the edges (format: node1 node2):\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1;
        //graph[node2][node1] = 1; // If graph is undirected
    }

    printf("DFS Traversal starting from node 0: ");
    DFS(0); // Start DFS from node 0

    printf("\n");

    return 0;
}

