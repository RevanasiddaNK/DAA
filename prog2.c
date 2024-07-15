#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void dfs(int adj[10][10], int visited[10], int s, int n){
    visited[s] =1;
    
    for(int v=0; v<=n; v++){
        if( adj[s][v] == 1 && visited[v] == 0 ){
            printf("%d -> %d \n",s,v );
            dfs(adj,visited,v,n);
        }
    }
}

int main(){

    int adj[10][10], visited[10];

    int n;
    printf("Enter number of vertices : ");
    scanf("%d",&n);

    int s;
    printf("Enter Source : ");
    scanf("%d", &s);

    for(int i=0; i<n; i++)
        visited[i] = 0;

    printf("Enter adjacency matrix : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    dfs(adj,visited,s,n);
   
    for(int i=0; i<n; i++){
        if(visited[i] == 0)
        printf(" %d is not reachable \n",i);
    else
        printf("  %d is reachable \n",i);
    }

    return 0;   
}