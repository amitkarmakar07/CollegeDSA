#include<stdio.h>
void merge(int arr[],int lb,int mid,int ub){
    int i=lb , j=mid+1 , k=lb;
    int b[ub+1];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
             b[k]=arr[i];
             k++;i++;
        }
        else {b[k]=arr[j];
         j++;k++;
        }
    }
    while(j<=ub){
        b[k]=arr[j];
        k++;j++;
    }
    while(i<=mid){
        b[k]=arr[i];
        k++;
        i++;
    }
    for(int i=lb;i<=ub;i++){
        arr[i]=b[i];
    }
}
void mergesort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);

        merge(arr,lb,mid,ub);
    }
}
int main(){
int arr[6]={5,4,3,2,1,0};
mergesort(arr,0,5);

for(int i=0;i<6;i++){
    printf("%d ",arr[i]);
}
return 0;
}
