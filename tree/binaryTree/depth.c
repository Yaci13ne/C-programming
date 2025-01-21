#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
typedef struct node {
    int data;
    struct node *left, *right;
} node;


node* create() {
    int x;
    printf("Enter data: ");
    scanf("%d", &x);

    if (x == 1000) { 
        return NULL;
    }

    
    node *newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
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

void display(node* root) {
    if (root == NULL) { 
        return;
    }

    printf("%d ", root->data); 
    display(root->left);      
    display(root->right);      
}




int profondeur(node* root, node* v) {
    if (root == NULL)
        return -1; //tree is empty or the node is not found

    if (root == v)
        return 0; // Base case: the depth of the node itself is 0

    // Search the left subtree
    int leftDepth = profondeur(root->left, v);
    if (leftDepth != -1)
        return 1 + leftDepth;

    // Search the right subtree
    int rightDepth = profondeur(root->right, v);
    if (rightDepth != -1)
        return 1 + rightDepth;

    
    
    return -1; // If the node is not found in either subtree
}




int main() {
    node* root = NULL;

   
    root = create();

   
    printf("\nPreorder Traversal of the Binary Tree:\n");
    display(root);

int depth = profondeur(root,root->left->left);

printf("%d",depth);

    return 0;
}
