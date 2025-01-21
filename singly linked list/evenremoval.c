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

node *remove_even(node *head)
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
            // Remove the current node (even data)
            if (tmpprev == NULL)
            {
                // If head node is even, update the head pointer
                head = tmp->next;
                free(tmp);
                tmp = head;
            }
            else
            {
                // For non-head even nodes
                tmpprev->next = tmp->next;
                free(tmp);
                tmp = tmpprev->next;
            }
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