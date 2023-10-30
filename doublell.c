#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * prev;
    struct node *next;
};
struct node*createdll(int n){
   struct node *head=NULL,*temp,*newnode;
   printf("Enter the elemern : ");
   for(int i=0;i<n;i++){
      int val;
      scanf("%d",&val);
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=val;
      newnode->next=NULL;
      newnode->prev=NULL;
      if(head==NULL){
         head=newnode;      
         temp=newnode;
      }
      else{
         temp->next=newnode;
         newnode->prev=temp;
         temp=newnode;
      }
   }
   return head;
}
struct node *insertBegin(struct node *head){
   struct node *newnode = (struct node *) malloc(sizeof(struct node));
   printf("\n Enter value to be inserted at beginning:");
   scanf("%d", &newnode->data);
   head->prev=newnode;
   newnode->next=head;
   newnode->prev=NULL;
   head=newnode;
   return head;
}
struct node * insertatPosition(struct node * head){
   struct node *newnode = (struct node *) malloc(sizeof(struct node));
   struct node *temp=head;
   printf("Enter the postion to neter  : ");
   int pos;
   scanf("%d",&pos);
   printf("Enter the value to enter : ");
   scanf("%d",&newnode->data);
   newnode->prev=NULL;
   newnode->next=NULL;
   for (int i=0;i<pos-2;i++){
        temp=temp->next;
   }
   (temp->next)->prev=newnode;
   newnode->next=temp->next;
   newnode->prev=temp;
   temp->next=newnode;
   return head; 
} 
struct node*delPos(struct node* head){
   struct node *temp=head, *ptr;
   int pos;
   printf("Enter position of element you want to delete : ");
   scanf("%d",&pos);
   for(int i=0;i<pos-2;i++){
      temp=temp->next;
   }
   ptr=(temp->next);
   temp->next=ptr->next;
   ptr->prev=temp;
   free(ptr);
   return head;   
}
struct node*delBegin(struct node * head){
   struct node*temp=head;
   (head->next)->prev=NULL;
   head=head->next;
   free(temp);
   return head;
}
void display(struct node * head){
   struct node * ptr=head;
   while(ptr!=NULL){
      printf(" %d <->",ptr->data);
      ptr=ptr->next;
   }
}
int main(){
   int n;
   printf("Enter the number of elements you want in your doubly linked list: ");
   scanf("%d",&n);
   struct node*head=createdll(n);
   display(head); 
   head=insertBegin(head);
   display(head);
   head=insertatPosition(head);
   display(head);
   head=delPos(head);
   display(head);
   head=delBegin(head);
   display(head);
   return 0;
}