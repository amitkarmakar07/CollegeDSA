#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createcll(int n) {
    struct node *head = NULL;

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        int val;
        scanf("%d", &val);
        newnode->data = val;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;
        } else {
            struct node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }
    return head;
}
struct node*insertEnd(struct node * head){
       struct node *temp=head;
       struct node *newnode=(struct node*)malloc(sizeof(struct node));
       int value;
       printf("\nENter the value : ");
       scanf("%d",&value);
       newnode->data=value;
       newnode->next=NULL;
       while(temp->next != head){
         temp=temp->next;
       }
      temp->next=newnode;
      newnode->next=head;
return head;
}
struct node * delEnd(struct node* head){
   struct node *temp,*ptr;
   temp=head;
   while(temp->next != head){
      ptr=temp;
      temp=temp->next;
   }
   ptr->next=head;
   free(temp);
   return head;
}
void printlist(struct node *head) {
    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d", &n);
    struct node *head = createcll(n);
    printlist(head);
    head=insertEnd(head);
    printlist(head);
    head=delEnd(head);
    printlist(head);
    return 0;
}
