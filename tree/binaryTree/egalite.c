#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
typedef struct node
{
    int data;
    struct node *left, *right;
} node;

int egalite(node *A, node *B)
{
    // Base cases
    if (A == NULL && B == NULL)
        return 1; // Both trees are empty
    if (A == NULL || B == NULL)
        return 0; // One tree is empty
    if (A->data != B->data)
        return 0; // Data mismatch

    // Recursively compare left and right subtrees
    return egalite(A->left, B->left) && egalite(A->right, B->right);
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
    printf("\nTree 1 :\n");
    node *root = NULL;
    root = create();
    printf("\nTree 2 :\n");
    node *root32 = NULL;
    root32 = create();
    printf("\nPreorder Traversal of the Binary Tree 1 :\n");
    display(root);

    printf("\nPreorder Traversal of the Binary Tree 2 :\n");
    display(root32);

    int result = egalite(root, root32);

    if (result == 1 || result == -1)
    {
        printf("The trees are equal.\n");
    }
    else
    {
        printf("The trees are not equal.\n");
    }
    return 0;
}
