#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

struct Node* graph[MAX_NODES];
int visited[MAX_NODES];
int numnodes;
int stack[MAX_NODES];
int top=-1;
void push(int node)
{
    stack[++top]=node;
}
int pop()
{
    return stack[top--];
}

struct Node* createNode(int value)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
};

void addedge(int src,int des)
{
    struct Node* newnode=createNode(des);
    newnode->next=graph[src];
    graph[src]=newnode;
}

void DFS(int node)
{
    visited[node]=1;
    struct Node* temp=graph[node];
    while(temp!=NULL)
    {
        int dt=temp->data;
        if(visited[dt]==0)
        {
            DFS(dt);
        }
        temp=temp->next;
    }
    push(node);
}

void topsort(int node)
{
    if(visited[node]==0)
    {
        DFS(node);
    }

    while(top!=-1)
    {
        printf("%d ",pop());
    }
}

void main()
{
    printf("Enter no. of nodes:\n");
    scanf("%d",&numnodes);
    int edges=0;
    printf("Enter no. of edges:\n");
    scanf("%d",&edges);
    printf("Enter the connections:node 1 node 2 \n");
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
    printf("Topological Sort traversal:\n");
    topsort(start);
}
