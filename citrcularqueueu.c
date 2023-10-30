#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = data;
    } else if ((rear + 1) % MAX == front) {
        printf("Overflow\n");
    } else {
        rear = (rear + 1) % MAX;
        queue[rear] = data;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Underflow\n");
    } else {
        printf("\nDequeued: %d\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is: ");
        int i = front;
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        printf("\n");
    }
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
