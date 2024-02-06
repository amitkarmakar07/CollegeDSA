#include<stdio.h>
int partition(int arr[],int lb,int ub){
    int i=lb;
    int j=ub;
    int pivot=arr[lb];
    while(i<j){
        while(arr[i]<=pivot){ i++;}
        while(arr[j]>pivot){ j--;}
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int p=arr[lb];
    arr[lb]=arr[j];
    arr[j]=p;

    return j;
}
void quicksort(int arr[],int lb,int ub ){
    if(lb<ub){
        int part=partition(arr,lb,ub);
        quicksort(arr,lb,part-1);
        quicksort(arr,part+1,ub);
    }
}
int main(){
int arr[6]={5,4,3,2,1,0};
quicksort(arr,0,5);

for(int i=0;i<6;i++){
    printf("%d ",arr[i]);
}
return 0;
}
