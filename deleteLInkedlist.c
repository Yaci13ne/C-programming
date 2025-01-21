#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

void delete_start(node **head)
{
    if (*head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }

    node *tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

void delete_end(node **head)
{
    node *tmp = *head;
    node *prevtmp;
    while (tmp->next != NULL)
    {
        prevtmp = tmp;
        tmp = tmp->next;
    }
    if (*head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }
    prevtmp->next = NULL;
    free(tmp);
}

int main()
{
    node *head = NULL, *newnode, *temp;
    int choice;

    do
    {
        newnode = (node *)malloc(sizeof(node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Enter '1' to skip adding: ");
        scanf("%d", &choice);
    } while (choice != 1);

    delete_start(&head);
    delete_end(&head);

    //                                               **Display the linked list**
    printf("Linked list: ");
    temp = head; // Start from the head
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}
