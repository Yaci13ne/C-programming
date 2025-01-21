#include <stdio.h>
#include <stdlib.h>

// ure for a binary tree node
 typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;

// Function to create a new node
 node* createNode(int value) {
     node* newNode = ( node*)malloc(sizeof( node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a node into the binary search tree
 node* insertNode( node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    // Insert into the left subtree
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    // Insert into the right subtree
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to perform in-order traversal and print elements in sorted order
void inOrderTraversal( node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory allocated for the binary tree
void freeTree( node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
     node* root = NULL;
    int nodeValue;
    char choice;

    // Insert nodes into the binary search tree
    do {
        printf("Input a value to insert into the binary search tree (enter 0 to stop): ");
        scanf("%d", &nodeValue);

        if (nodeValue != 0) {
            root = insertNode(root, nodeValue);
        }

    } while (nodeValue != 0);

    // Perform in-order traversal and print elements in sorted order
    printf("\nIn-order Traversal (Sorted Order) of the Binary Search Tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}