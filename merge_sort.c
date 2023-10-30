#include  <stdio.h> 
void printArray(int arr[],int size){
  for(int i=0;i<size;i++){
   printf("%d ",arr[i]);
  }
}
void merge(int arr[],int s, int mid , int e){
   int n1=mid-s+1;
   int n2=e-mid;
   int ar1[n1];
   int ar2[n2];

   for(int i=0;i<n1;i++){
      ar1[i]=arr[s+i];
   }
   for(int i=0;i<n2;i++){
      ar2[i]=arr[mid+1+i];
   }
   int i=0,j=0,k=s;
   while(i<n1 && j<n2){
      if(ar1[i]>=ar2[j]){
         arr[k]=ar2[j];
         j++;
      }
      else{
         arr[k]=ar1[i];
         i++;
      }
      k++;
   }
   while(i<n1){
      arr[k]=ar1[i];
      i++;k++;
   }
   while(j<n2){
      arr[k]=ar2[j];
      j++;
      k++;
   }
}
void mergeArray(int arr[],int s , int e){
  if(s<e){
   int mid=s+(e-s)/2;
   mergeArray(arr,s,mid);
   mergeArray(arr,mid+1,e);
   merge(arr,s,mid,e);
  }
}
int main(){
int n ;
printf("Enter the size : ");
scanf("%d",&n);
int arr[n];
printf("Enter the array element : ");
for(int i=0;i<n;i++){
   scanf("%d", &arr[i]);
}
mergeArray(arr,0,n-1);
printf("After the sort : ");
printArray(arr, n );
return 0;
}