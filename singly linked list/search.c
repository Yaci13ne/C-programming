// 10

#include <stdio.h>
#include <stdlib.h>
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

node *delete_begin(node *head)
{
    if (head == NULL)
        return NULL;

    node *tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

node *delete_end(node *head)
{
    if (head == NULL)
    {
        printf("The list is empty. No nodes to delete.\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        // Only one node, delete it and return NULL
        free(head);
        return NULL;
    }

    node *tmp = head;
    node *tmp1 = NULL;

    while (tmp->next != NULL)
    {
        tmp1 = tmp;
        tmp = tmp->next;
    }

    free(tmp);
    tmp1->next = NULL;

    return head;
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
    printf("NULL");
}

int Search(node *head, int value)
{
    if (head == NULL)
        return -1;

    node *tmp = head;
    int i = 1;
    while (tmp->next != NULL)
    {
        if (tmp->data == value)
        {
            return i;
        }
        tmp = tmp->next;
        i++;
    }

    return 0;
}

int main()
{
    node *head = NULL;
    node *node1, *node2, *node3;
    head = create(5);
    node1 = create(8);
    node2 = create(7);
    node3 = create(10);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    head = insert_begin(head, 3);
    insert_End(head, 12);
    insert_End(head, 15);
    head = delete_begin(head);
    display(head);

    int pos = Search(head, 8);

    if (pos)
    {
        if (pos == -1)
            printf("the value doesnt exist ");

        else
            printf("the value exist at pos %d", pos);
    }
    else
        printf("the linked list is empty");
    return 0;
}