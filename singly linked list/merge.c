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

void insert_sorted(node **head, int data)
{
    node *newnode = create(data);

    if (*head == NULL || (*head)->data >= data)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    node *tmp = *head;
    while (tmp->next != NULL && tmp->next->data < data)
    {
        tmp = tmp->next;
    }

    newnode->next = tmp->next;
    tmp->next = newnode;
}

node *fusion(node *head1, node *head2)
{
    node *head3 = NULL;

    // Merge the lists without sorting after
    node *tmp1 = head1;
    node *tmp2 = head2;

    while (tmp1 != NULL && tmp2 != NULL)
    {
        if (tmp1->data <= tmp2->data)
        {
            insert_sorted(&head3, tmp1->data);
            tmp1 = tmp1->next;
        }
        else
        {
            insert_sorted(&head3, tmp2->data);
            tmp2 = tmp2->next;
        }
    }

    // Add remaining nodes from head1 if any
    while (tmp1 != NULL)
    {
        insert_sorted(&head3, tmp1->data);
        tmp1 = tmp1->next;
    }

    // Add remaining nodes from head2 if any
    while (tmp2 != NULL)
    {
        insert_sorted(&head3, tmp2->data);
        tmp2 = tmp2->next;
    }

    return head3;
}

int main()
{
    // Create two sorted linked lists
    node *list1 = create(1);
    list1->next = create(3);
    list1->next->next = create(5);
    list1->next->next->next = create(7);

    node *list2 = create(2);
    list2->next = create(4);
    list2->next->next = create(6);

    // Display the original lists
    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);

    // Merge the two lists
    node *merged_list = fusion(list1, list2);

    // Display the merged list
    printf("Merged List: ");
    display(merged_list);

    return 0;
}
