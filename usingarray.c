#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = data;
    } else {
        rear++;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n");
    } else if (front == rear) {
        printf("Dequeued: %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
    }
}

void display() {
    printf("The Queue is:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(4);
    enqueue(5);
    enqueue(10);
    enqueue(12);
    display();
    dequeue();
    display();
    return 0;
}
