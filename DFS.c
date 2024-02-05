#include<stdio.h>
int graph[100][100];
int visited[100];
int vertex;
void dfs(int v){
    printf("%d->",v);
    visited[v]=1;
    for(int i=0;i<vertex;i++){
        if(!visited[i]&&graph[v][i]==1){
            dfs(i);
        }
    }
}
int main(){
    int v;
    printf("ENter the vertex : ");
    scanf("%d",&vertex);
    printf("ENter the matrix: ");
    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<vertex;i++) visited[i]=0;
    dfs(0);
    return 0;
}
