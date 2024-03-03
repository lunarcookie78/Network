#include<stdio.h>
 #include<stdlib.h>
int visited[10];
 int a[10][10];
 int n;
void readadjmatrix();
void dfs(int);
void main()
     {
int start;clrscr(); readadjmatrix();
printf("Enter the starting vertex:\n");
scanf("%d",&start);
dfs(start);
      }
  void readadjmatrix()
      {
               int i,j;
               printf("Enter the number of vertices:\n");
               scanf("%d",&n);
               printf("Enter adjacency matrix\n"); for(i=1;i<=n;i++)
               for(j=1;j<=n;j++)
               scanf("%d",&a[i][j]);
       }
   void dfs(int v)
      {
       int w;
                    visited[v]=1; 
                    for(w=1;w<=n;w++)
           {
                          if(visited[w]==0&&a[v][w]==1)
                  {
                                   printf("%d",w);
                                  dfs(w);
                  }
    }
 }