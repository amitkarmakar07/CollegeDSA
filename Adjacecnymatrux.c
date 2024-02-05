#include<stdio.h>
int adj_mat[100][100];
void matrix(int start,int end){
    adj_mat[start][end]=1;
    adj_mat[end][start]=1;
}
void display(int v){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d",adj_mat[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("Enter the Vertex number : ");
    int v,e;
    scanf("%d",&v);
    printf("edges : ");
    scanf("%d",&e);
    int start,end;
    for(int i=0;i<e;i++){
        printf("Enter Connecting Vertex : ");
        scanf("%d %d",&start,&end);
        matrix(start,end);
    }
    display(v);
    return 0;
}
