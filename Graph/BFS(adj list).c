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
int queue[MAX_NODES];
int front=-1;int rear=-1;
void enqueue(int node)
{
    if(rear==MAX_NODES-1)
    {
        return;
    }
    queue[++rear]=node;
}
int dequeue()
{
    if(front==-1||front>rear)
    {
        return -1;
    }
    if(front==-1)
    {
        front=0;
    }
    return queue[front++];
}

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

void bfs(int node)
{
    enqueue(node);
    visited[node]=1;
    while(front!=-1)
    {
        int current=dequeue();
        if(current==-1)
        {
            break;
        }
        printf("%d ",current);
        struct Node* temp=graph[current];
        while(temp!=NULL)
        {
            int dt=temp->data;
            if(visited[dt]==0)
            {
                enqueue(dt);
                visited[dt]=1;

            }
            temp=temp->next;
        }
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    int numEdges;
    int start;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numNodes; i++) {
        graph[i] = NULL;
    }

    printf("Enter the edges (format: node1 node2):\n");
    for (int i = 0; i < numEdges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        addEdge(node1, node2);
    }
    printf("Enter starting node:\n");
    scanf("%d",&start);

    printf("BFS:\n");
    bfs(start);

    printf("\n");

    return 0;
}
