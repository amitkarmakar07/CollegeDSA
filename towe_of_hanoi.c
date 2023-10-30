#include  <stdio.h> 
int count=0;
void tower_of_hanoi(int n, char source , char help , char dest){
   
   if (n ==1) {
      printf("Move the %d disk form %c to %c \n",n,source, dest);
      count++;
      return ;
   }
   else{
      tower_of_hanoi(n-1,source,dest,help);
      printf("Move the %d disk form %c to %c \n",n,source, dest);
      count++;
      tower_of_hanoi(n -1,help,source,dest );
      
   }
}
int main(){
int n;
printf("Enter the disk number : ");
scanf("%d",&n);
tower_of_hanoi(n,'A','B','C');
printf("Count=%d\n",count);
return 0;
}