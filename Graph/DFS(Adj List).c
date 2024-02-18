#include<stdio.h>
#include<stdlib.h>
#define MAXNODES 10

struct Node
{
    int data;
    struct Node *next
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
void dfs(int node)
{
    printf("Pushing %d ",node);
    visited[node]=1;
    struct Node* temp=graph[node];
    while(temp!=NULL)
    {
        int dt=temp->data;
        if(visited[dt]==0)
        {
            dfs(dt);
        }
        temp=temp->next;
    }
    printf("Popping %d ",node);
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
    printf("DFS traversal:\n");
    dfs(start);
}
