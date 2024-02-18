#include<stdio.h>
#include<stdlib.h>
#define MAXNODES 10

int graph[MAXNODES][MAXNODES];
int numnodes;
int visited[MAXNODES];

void dfs(int node)
{
    printf("Pushing %d ",node);
    visited[node]=1;
    for(int i=0;i<numnodes;i++)
    {
        if(graph[node][i]==1 && visited[i]==0)
        {
            dfs(i);
        }
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
        graph[node1][node2]=1;
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


