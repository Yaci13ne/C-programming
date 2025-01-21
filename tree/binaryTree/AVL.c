#include <stdio.h>
#include <stdlib.h>

// Structure of an AVL tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of the tree
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to get the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new AVL tree node
struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially added at a leaf
    return node;
}

// Right rotation
struct Node *rightRotate(struct Node *y)
{
    printf("Performing right rotation on node %d\n", y->key);
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // New root
}

// Left rotation
struct Node *leftRotate(struct Node *x)
{
    printf("Performing left rotation on node %d\n", x->key);
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // New root
}

// Function to get the balance factor of a node
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key into the AVL tree
struct Node *insert(struct Node *node, int key)
{
    // Perform the normal BST insertion
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicates are not allowed

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor to check if this node became unbalanced
    int balance = getBalance(node);
    printf("Node %d has balance factor %d\n", node->key, balance);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        printf("Left Left Case at node %d\n", node->key);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        printf("Right Right Case at node %d\n", node->key);
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        printf("Left Right Case at node %d\n", node->key);
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        printf("Right Left Case at node %d\n", node->key);
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return the (unchanged) node pointer
}

// Function to perform preorder traversal of the tree
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Function to print the tree structure
void printTree(struct Node *root, int space)
{
    int COUNT = 5; // Spacing
    if (root == NULL)
        return;

    space += COUNT;

    // Print right child first
    printTree(root->right, space);

    // Print current node
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Print left child
    printTree(root->left, space);
}

int main()
{
    struct Node *root = NULL;

    // Insert elements and visualize the tree
    root = insert(root, 12);
    printf("\nTree after inserting 40:\n");
    printTree(root, 0);

    root = insert(root, 8);
    printf("\nTree after inserting 50\n");
    printTree(root, 0);

    root = insert(root, 3);
    printf("\nTree after inserting 20:\n");
    printTree(root, 0);

    root = insert(root, 4);
    printf("\nTree after inserting 30:\n");
    printTree(root, 0);

    root = insert(root, 9);
    printf("\nTree after inserting 10:\n");
    printTree(root, 0);

    root = insert(root, 85);
    printf("\nTree after inserting 5:\n");
    printTree(root, 0);

    root = insert(root, 50);
    printf("\nTree after inserting 8:\n");
    printTree(root, 0);

    return 0;
}
