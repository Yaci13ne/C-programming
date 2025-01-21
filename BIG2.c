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

void display(node *head)
{
    node *tmp = head;
    while (tmp != 0)
    {
        printf("%d\t", tmp->value);
        tmp = tmp->next;
    }
}

node *add_begin(node *head, int value)
{
    node *newnode = malloc(sizeof(node));
    newnode->value = value;
    newnode->prev = NULL;
    head->prev = newnode;
    newnode->next = head;

    return newnode;
}
node *add_end(node *tail, int value)
{
    node *newnode = malloc(sizeof(node));
    newnode->value = value;
    newnode->next = NULL;

    tail->next = newnode;
    newnode->prev = tail;
    return newnode;
}

node *delete_begin(node *head)
{
    node *tmp = head->next;
    free(tmp->prev);

    return tmp;
}

node *delete_end(node *tail)
{
    node *tmp = tail->prev;

    free(tmp->next);
    tmp->next = 0;

    return tmp;
}

node *insert_sorted(node *head, int x)
{

    node *tmp = head;
    if (head == 0)
    {

        head = add_begin(head, x);
    }
    else
    {
        node *newnode = malloc(sizeof(node));

        while (tmp->next != NULL && tmp->value < x)
        {
            tmp = tmp->next;
        }

        newnode->next = tmp;
        newnode->prev = tmp->prev;
        tmp->prev = newnode;
        tmp->prev->next = newnode;
    }

    return head;
}

void deletion(node *head)
{
    int pos = 2;
    node *tmp = head;
    while (pos > 1 && tmp != NULL)
    {
        tmp = tmp->next;
        pos--;
    }
    node *tmp2 = tmp->prev;
    tmp2->next = tmp->next;

    tmp2->next->prev = tmp2;
    free(tmp);
}

void display_rec(node *tmp)
{
    if (tmp == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d->", tmp->value);
    display_rec(tmp->next);
}

void display_invrec(node *tmp)
{
    if (tmp == NULL)
    {
        printf("NULL->");
        return;
    }

    display_invrec(tmp->next);
    printf("%d->", tmp->value);
}

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    node *head;
    node *tail;
    head = initializer_list(head);

    node *newnode1 = createNode(1);

    node *newnode2 = createNode(2);
    node *newnode3 = createNode(5);
    node *newnode4 = createNode(7);

    head = tail = newnode1;

    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode3->next = newnode4;

    while (tail->next != 0)
    {
        tail = tail->next;
    }
    printf("\n adding 0 to beginning : \n");

    head = add_begin(head, 0);
    display(head);

    printf("\n adding 13 to beginning : \n");
    tail = add_end(tail, 16);
    display(head);

    printf("\n delete beginning : \n");
    head = delete_begin(head);
    display(head);

    printf("\n delete end : \n");
    tail = delete_end(tail);
    display(head);

    printf("\n the linked list inversed: \n ");
    display_invrec(head);

    printf("\n the linked list : \n");
    head = insert_sorted(head, 15);

    deletion(head);
    display(head);
    return 0;
}
