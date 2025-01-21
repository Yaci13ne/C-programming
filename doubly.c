/*Question:
Write a C program that creates a doubly linked list and allows for the insertion of new elements in sorted order. The program should:

Initialize an empty list (head and tail are set to NULL).
Insert new elements either at the beginning, middle, or end, ensuring that the list remains sorted in ascending order.
Display the entire linked list after all insertions.
The program should also handle the case when the list is empty, and new elements should be inserted at the appropriate position based on their value.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *prev;
    struct node *next;
} node;

node *initializer_list(node *liste)
{
    liste = NULL;
    return liste;
}

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void display(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d\t", tmp->value);
        tmp = tmp->next;
    }
}

node *add_begin(node *head, int value)
{
    node *newnode = createNode(value);
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    return newnode; // new node becomes the head
}

node *add_end(node *tail, int value)
{
    node *newnode = createNode(value);
    tail->next = newnode;
    newnode->prev = tail;
    return newnode; // new node becomes the tail
}

void insert_element(node **head, node **tail, int value)
{
    node *tmp = *head;
    node *newnode = createNode(value);
    int flag = 0;

    // If the list is empty or value is smaller than the head value, insert at the beginning
    if ((*head) == NULL || (*head)->value >= value)
    {
        *head = add_begin(*head, value);
        if (*tail == NULL)
        { // If the list was empty, the new node is also the tail
            *tail = *head;
        }
        return;
    }

    // Traverse to find the correct position
    while (tmp != NULL && tmp->value < value)
    {
        tmp = tmp->next;
    }

    if (tmp != NULL && tmp->value > value)
    {
        flag = 1; // Insert between nodes
    }

    // Inserting in the middle (when flag is set)
    if (flag)
    {
        newnode->prev = tmp->prev;
        newnode->next = tmp;
        tmp->prev->next = newnode;
        tmp->prev = newnode;
    }
    // Inserting at the end
    else
    {
        *tail = add_end(*tail, value);
    }
}

int main()
{
    node *head;
    node *tail;
    head = tail = initializer_list(head); // Initialize head and tail to NULL

    // Create the initial linked list
    node *newnode1 = createNode(1);
    node *newnode2 = createNode(2);
    node *newnode3 = createNode(7);
    node *newnode4 = createNode(9);

    head = tail = newnode1;
    newnode1->next = newnode2;
    newnode2->prev = newnode1;
    newnode2->next = newnode3;
    newnode3->prev = newnode2;
    newnode3->next = newnode4;
    newnode4->prev = newnode3;

    tail = newnode4; // Update tail to the last node

    // Insert elements
    insert_element(&head, &tail, 5);
    insert_element(&head, &tail, 15);
    insert_element(&head, &tail, 0);

    // Display the list
    display(head);

    return 0;
}
