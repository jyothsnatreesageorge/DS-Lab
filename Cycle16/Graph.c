#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int i,j,v1,v2,bs,ds,vertices,edges,adj[10][10];
void addedge(int v1,int v2,int a[10][10])
{
    a[v1][v2]=1;
    a[v2][v1]=1;
}
void display(int a[10][10])
{
    printf("Printing the adjacency matrix \n");
    for(i=1;i<=vertices;i++)
    {
        for(j=1;j<=vertices;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void bfs(int start,int vertices,int a[10][10])
{
    int queue[100];
    bool visited[50]={false};
    int front=0,rear=0;
    queue[rear++]=start;
    visited[start]=true;
    while(front<rear)
    {
        int current=queue[front++];
        visited[current]=true;
        printf("%d\t",current);
        for(i=0;i<=vertices;i++)
        {
            if(visited[i]==false&&a[current][i]==1)
            {
                queue[rear++]=i;
                visited[i]=true;
            }
        }
    }
}
void dfs(int start,int vertices,int a[10][10])
{
    int stack[100];
    bool visited[50]={false};
    int top=-1;
    stack[++top]=start;
    visited[start]=true;
    while(top>=0)
    {
        int current=stack[top--];
        //visited[current]=true;
        printf("%d\t",current);
        for(i=vertices;i>=1;i--)
        {
            if(visited[i]==false&&a[current][i]==1)
            {
                stack[++top]=i;
                visited[i]=true;
            }
        }
    }
}
int main()
{
    printf("Enter the vertices:");
    scanf("%d",&vertices);
    printf("Enter the edges:");
    scanf("%d",&edges);
    for(i=0;i<edges;i++)
    {
        printf("Enter the two vertices (v1 v2):");
        scanf("%d %d",&v1,&v2);
        if(v1<1||v2<0||v1>vertices||v2>vertices)
        {
            printf("Invalid edge!");
            i--;
        }
        else
        {
            addedge(v1,v2,adj);
        }
    }
    display(adj);
    printf("Enter the starting vertex of bfs:");
    scanf("%d",&bs);
    bfs(bs,vertices,adj);
    printf("\nEnter the starting vertex of dfs:");
    scanf("%d",&ds);
    dfs(ds,vertices,adj);
    return 0;
}
