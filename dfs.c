#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int n;

void createGraph()
{
  int i, j;
  printf("Enter number of vertices : ");
  scanf("%d", &n);

  printf("Enter Adjacency Matrix : \n");
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      scanf("%d", &adj[i][j]);
}

void dfs(int v, int visited[])
{
  int i;
  visited[v] = 1;
  printf("%d ", v);

  for(i=0; i<n; i++)
  {
    if(adj[v][i] && !visited[i])
      dfs(i, visited);
  }
}

void DFS()
{
  int i;
  int visited[MAX];

  for(i=0; i<n; i++)
    visited[i] = 0;

  printf("Enter starting vertex for DFS : ");
  int start;
  scanf("%d", &start);

  dfs(start, visited);
}

int main()
{
  createGraph();
  DFS();
  return 0;
}
