#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

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

        // Input data for the new node
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        // If the list is empty, set head to newnode
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode; // Link new node at the end
            temp = newnode;       // Move temp to the new end
        }

        // Ask the user if they want to add another node
        printf("Enter '1' to continue adding values or any other key to stop: ");
        scanf("%d", &choice);
    } while (choice == 1);

    // Display the linked list
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
