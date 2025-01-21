#include <stdio.h>
#include <stdlib.h>

// ure for a binary tree node
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *Create(node *root, int value)
{

    if (root == NULL)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = value;
        newnode->right = NULL;
        newnode->left = NULL;

        return newnode;
    }

    else

        if (value < root->data)
        root->left = Create(root->left, value);

    else
        root->right = Create(root->right, value);

    return root;
}

int treeHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

int main()
{
    node *root = NULL;

    root = Create(root, 12);
    root = Create(root, 8);
    root = Create(root, 3);
    root = Create(root, 4);
    root = Create(root, 9);
    root = Create(root, 85);
    root = Create(root, 50);
    int hauteur = treeHeight(root);
    printf("Binary Search Tree created.and the hauteur is %d\n", hauteur);

    return 0;
}
