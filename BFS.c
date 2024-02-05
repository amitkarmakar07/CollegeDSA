#include<stdio.h>
int graph[100][100];
int visited[100]={0};
int vertex;
int que[100];
int front=-1;
int rare=-1;
void enqueue(int data){
    if(rare==99) return;
    else if(front==-1&&rare==-1) {
        front=0;
        rare=0;
        que[rare]=data;
    }
    else{
        rare++;
        que[rare]=data;
    }
}
int isempty(){
    if((front==-1&&rare==-1)||(front>rare)) return 1;
    return 0;
}
int deque(){
    int d;
    if(rare==-1&&front==-1) return 0; 
    else{
        d=que[front];
        front++;
    }
    return d;
}
void bfs(int v){
            printf("%d->",v);
            enqueue(v);
            visited[v]=1;
            while(!isempty()){
                int node=deque();
                for(int i=0;i<vertex;i++){
                    if(!visited[i]&&graph[node][i]==1){
                        enqueue(i);
                        visited[i]=1;
                        printf("%d->",i);
                    }
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
    bfs(1);
return 0;
}
