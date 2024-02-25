#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10

struct Node {
    int data;
    struct Node *next;
};

struct Node* graph[MAX_NODES];
int visited[MAX_NODES];
int recursionStack[MAX_NODES];
int numnodes;

struct Node* newNode(int node) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = node;
    newnode->next = NULL;
    return newnode;
}

void addEdge(int src, int des) {
    struct Node* newnode = newNode(des);
    newnode->next = graph[src];
    graph[src] = newnode;
}

int hasCycleUtil(int v) {
    if (visited[v] == 0) {
        visited[v] = 1;
        recursionStack[v] = 1;

        struct Node* currentNode = graph[v];
        while (currentNode != NULL) {
            int adjacentNode = currentNode->data;
            if (!visited[adjacentNode] && hasCycleUtil(adjacentNode))
                return 1;
            else if (recursionStack[adjacentNode])
                return 1;
            currentNode = currentNode->next;
        }
    }
    recursionStack[v] = 0;
    return 0;
}

int hasCycle() {
    for (int i = 0; i < numnodes; ++i) {
        visited[i] = 0;
        recursionStack[i] = 0;
    }

    for (int i = 0; i < numnodes; ++i) {
        if (hasCycleUtil(i))
            return 1;
    }
    return 0;
}

void dfs(int node) {
    printf("Pushing %d ", node);
    visited[node] = 1;
    struct Node* temp = graph[node];
    while (temp != NULL) {
        int dt = temp->data;
        if (visited[dt] == 0) {
            dfs(dt);
        }
        temp = temp->next;
    }
    printf("Popping %d ", node);
}

int main() {
    printf("Enter no. of nodes:\n");
    scanf("%d", &numnodes);

    int edges = 0;
    printf("Enter no. of edges:\n");
    scanf("%d", &edges);

    printf("Enter the connections: node 1 node 2\n");
    int node1, node2;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &node1, &node2);
        addEdge(node1, node2);
    }

    int start;
    printf("Enter starting node:\n");
    scanf("%d", &start);

    printf("DFS traversal:\n");
    dfs(start);

    printf("\n");

    if (hasCycle())
        printf("Graph contains cycle\n");
    else
        printf("Graph does not contain cycle\n");

    return 0;
}
