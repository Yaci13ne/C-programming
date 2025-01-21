#include <stdio.h>
#include <stdlib.h>

// ure for a binary tree node
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *delete_leaf(node *root)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL; // Return NULL after deleting the leaf
    }

    // Recursively delete leaves from left and right subtrees
    root->left = delete_leaf(root->left);
    root->right = delete_leaf(root->right);

    return root; // Return the updated root
}

node *create()
{
    int x;
    printf("Enter data: ");
    scanf("%d", &x);

    if (x == 1000)
    {
        return NULL;
    }

    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = x;

    printf("Enter left child of %d: ", x);
    newnode->left = create();

    printf("Enter right child of %d: ", x);
    newnode->right = create();

    return newnode;
}

void display(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    display(root->left);
    display(root->right);
}

int main()
{
    node *root = NULL;

    root = create();

    printf("\nPreorder Traversal of the Binary Tree:\n");
    display(root);

    return 0;
}
