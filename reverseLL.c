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
struct node* reverse(struct node *head){
       struct node *prev=NULL;
       struct node *nextnode=head;
       struct node* current=head;
       while(current!=NULL){
         nextnode=current->next;
         current->next=prev;
         prev=current;
         current=nextnode;
       }
       head=prev;
       return head;
}
int main(){
   int n;
   printf("Enter the node number : ");
   scanf("%d",&n);
   struct node *head = createLL(n);
   printf("The original linked list : \n");
   display(head);
   printf("\nAfter reversing : \n");
   head=reverse(head);
   display(head);
   return 0;
}