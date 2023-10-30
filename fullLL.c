#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node *next;
};
struct node* inBegin(struct node *head,int data){
   if (head == NULL) { printf("No node Found !");}
   else{struct node *newnode = (struct node*) malloc (sizeof(struct node));
   newnode->data=data;
   newnode->next=head;
   head=newnode;
}
return head;
}
struct node* inLast(struct node *head,int data){
      struct node *newnode = (struct node*) malloc (sizeof(struct node));
      newnode->data=data;
      newnode->next=NULL;
      struct node*temp=head;
      while(temp->next!=NULL){
         temp=temp->next;
      }
      temp->next=newnode;
return head;
}
struct node* beforeNode(struct node *head,int node , int data){
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   newnode->data=data;
   struct node*temp=head;
    struct node*ptr;
   while(temp->data != node){
      ptr=temp;
      temp=temp->next;
   }
   newnode->next=temp;
   ptr->next=newnode;
   return head;
}
struct node *delbeforeNode(struct node * head,int node){
      struct node * temp=head;
      struct node *ptr=NULL;
      struct node *p=NULL;
      while(temp->data != node){
         p=ptr;
         ptr=temp;
         temp=temp->next;
      }
       p->next=ptr->next;
       free(ptr);
       return head;
}
struct node* afterNode(struct node *head,int node , int data){
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   newnode->data=data;
   struct node*temp=head;
   while(temp->data != node){
      temp=temp->next;
   }
   newnode->next=temp->next;
   temp->next=newnode;
   return head;
}
struct node *delafterNode(struct node * head,int node){
      struct node * temp=head;
      struct node *ptr=NULL;
      while(temp->data != node){
         temp=temp->next;
      }
       ptr=temp->next;
       temp->next=(temp->next)->next;
       free(ptr);
       return head;
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
struct node* delBegin(struct node *head){
   struct node *temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node* delEnd(struct node *head){
   struct node*temp=head;
   struct node*prev=NULL;
   while(temp->next!=NULL){
      prev=temp;
      temp=temp->next;
   }
   prev->next=NULL;
   free(temp);
   return head;
}
void display(struct node*head){
   struct node*temp=head;
   while(temp!=NULL){   
      printf("%d-> ",temp->data);
       temp=temp->next;
   }
}
int main(){
   //creating a new linked list
   struct node *head=NULL;
   int n;
   printf("Enter the number of node : ");
   scanf("%d",&n);
   head=createLL(n);
   head=inBegin(head,10);
   head=delBegin(head);
   head=inLast(head,10);
   head=delEnd(head);
   head=beforeNode(head,3,5);
   head=delbeforeNode(head,3);
   head=afterNode(head,3,6);
   head=delafterNode(head,3);
   display(head);
   return 0;
}