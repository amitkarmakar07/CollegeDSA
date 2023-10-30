#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data) {
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }
    struct node* temp = front;
    printf("Dequeued: %d\n", front->data);
    front = front->next;
    free(temp);
}

void display() {
    printf("The queue is: ");
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(12);
    enqueue(1);
    enqueue(13);
    display();
    dequeue();
    display();
    return 0;
}
