#include <stdio.h>
#include <stdlib.h>
int cmp = 0;
// Definition of a binary tree node
typedef struct node {
    int data;
    struct node *left, *right;
} node;

// Recursive function to create a binary tree
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


int count_leaf(node* root) {
    if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return 1; 
    
    return count_leaf(root->left) + count_leaf(root->right);
}

int count_nodes(node* root) {
    if (root == NULL) 
        return 0; 
    
   
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}



void display(node* root) {
    if (root == NULL) { 
        return;
    }

    
    display(root->left);      
    printf("%d ", root->data); 
    display(root->right);      
}

int main() {
    node* root = NULL;

   
    root = create();

   
    printf("\n the Binary Tree:\n");
    display(root);

    return 0;
}
