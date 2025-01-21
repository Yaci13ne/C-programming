// 12
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

int display(node *head, int T[])
{
    node *tmp = head;
    if (head == NULL)
        return 0;
    int i = 0;
    while (tmp != NULL)
    {

        T[i++] = tmp->data;
        tmp = tmp->next;
    }
    return i;
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
    int T[100];
    int size = display(head, T);
    for (int i = 0; i < size; i++)
    {
        printf("T[%d]=%d\n", i, T[i]);
    }
    return 0;
}