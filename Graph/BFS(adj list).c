#include<stdio.h>
#include<stdlib.h>
#define MAXNODES 10

struct Node
{
    int data;
    struct Node *next;
};

struct Node* graph[MAXNODES];
int visited[MAXNODES];
int numnodes;

struct Node* newNode(int node)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=node;
    newnode->next=NULL;
    return newnode;
};

void addedge(int src,int des)
{
    struct Node* newnode=newNode(des);
    newnode->next=graph[src];
    graph[src]=newnode;
}

int queue[MAXNODES];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAXNODES - 1)
        printf("\nQueue is Full!!");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    int item;
    if (rear == -1)
    {
        printf("\nQueue is Empty!!");
        item = -1;
    }
    else
    {
        item = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
    return item;
}

void bfs(int start)
{
    printf("BFS Traversal: ");
    visited[start] = 1;
    enqueue(start);

    while (!(front == -1 || rear == -1)) {
        int node = dequeue();
        printf("%d ", node);

        struct Node* temp = graph[node];
        while (temp != NULL) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                enqueue(adjNode);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    printf("Enter no. of nodes:\n");
    scanf("%d",&numnodes);
    int edges=0;
    printf("Enter no. of edges:\n");
    scanf("%d",&edges);
    printf("Enter the connections: node1 node2 \n");
    int node1,node2;
    for(int i=0;i<edges;i++)
    {
        scanf("%d %d",&node1,&node2);
        addedge(node1,node2);
    }
    for(int i=0;i<numnodes;i++)
    {
        visited[i]=0;
    }
    int start;
    printf("Enter starting node:\n");
    scanf("%d",&start);
    bfs(start);
    
    return 0;
}
