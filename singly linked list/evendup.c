#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(int x)
{
    node *newnode = malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

node *insert_begin(node *head, int v)
{
    if (head == NULL)
        return NULL;

    node *newnode = malloc(sizeof(node));
    newnode->data = v;
    newnode->next = head;
    return newnode;
}

void insert_End(node *head, int v)
{
    if (head == NULL)
        return;

    node *newnode = malloc(sizeof(node));
    newnode->data = v;
    newnode->next = NULL;

    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newnode;
}

void display(node *head)
{
    node *tmp = head;
    if (head == NULL)
        return;

    while (tmp != NULL)
    {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

node *dup_even(node *head)
{
    node *tmp = head, *tmpprev = NULL;

    while (tmp != NULL)
    {
        if (tmp->data % 2 != 0)
        {
            // Move to the next node
            tmpprev = tmp;
            tmp = tmp->next;
        }
        else
        {
            // Create a new node
            node *newnode = malloc(sizeof(node));
            if (newnode == NULL)
            {
                // Handle memory allocation failure
                return head;
            }
            newnode->data = tmp->data;
            newnode->next = tmp->next;

            // Insert the new node after the current node
            tmp->next = newnode;

            // Move to the next node
            tmp = newnode->next;
        }
    }

    return head;
}

int main()
{
    // Create two sorted linked lists
    node *list1 = create(1);
    list1->next = create(3);
    list1->next->next = create(5);
    list1->next->next->next = create(7);
    remove_even(list1);
    display(list1);

    return 0;
}