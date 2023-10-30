#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *next;
};
void display(struct node*head){
   struct node*temp=head;
   while(temp!=NULL){   
      printf("%d-> ",temp->data);
       temp=temp->next;
   }
}
struct node *createLL(int n){
   struct node*head=NULL;
   int val;
   printf("Enter the od evalues : ");
   for (int i=0;i<n;i++){
        struct node *newnode = (struct node*) malloc (sizeof(struct node));
        scanf("%d",&val);
        newnode->data = val;
        newnode->next=NULL;
        if(head==NULL) head=newnode;
        else{
         struct node*temp=head;
         while(temp->next!=NULL){
            temp=temp->next;
         }
          temp->next=newnode;
        }
   }
   return head;
}
struct node*merge(struct node *head1,struct node*head2){
   struct node *temp;
   temp=head1;
   while(temp->next != NULL){
      temp=temp->next;
   }
   temp->next=head2;
   return head1;
}
int main(){
   int n,m;
   printf("Enter no of nodes in first linked list:");
   scanf("%d",&n);
   struct node *head1=createLL(n);
   printf("\nFirst Linked List is : \n");
   display(head1);
   printf("\nEnter no of nodes in second linked list:");
   scanf("%d",&m);
   struct node *head2=createLL(m);
   printf("\nSecond Linked List is : \n");
   display(head2);
   printf("\nAfter merging Linked list : \n");
   head1=merge(head1,head2);
   display(head1);
   return 0;
}