#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* front = 0;
node* rear = 0;

void enqueue(int x) {
    node* newnode = malloc(sizeof(node));
    newnode->data = x;
    newnode->next = 0;

    if (front == 0 && rear == 0) { // empty queue
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == 0 && rear == 0) {
        printf("Empty queue\n");
        return;
    }
    node* tmp = front;
    front = front->next;
    free(tmp);

    if (front == 0) { // If the queue is now empty
        rear = 0;
    }
}

void display() {
    node* tmp = front;
    if (front == 0 && rear == 0) { // nothing in the queue
        printf("Empty\n");
        return;
    }
    while (tmp != NULL) {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n"); // To indicate the end of the queue
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display(); // Output: 10->20->30->NULL

    dequeue();
    display(); // Output: 20->30->NULL

    dequeue();
    dequeue();
    display(); // Output: Empty

    dequeue(); // Output: Empty queue
    return 0;
}
