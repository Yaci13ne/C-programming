#include <stdio.h>
#include <stdlib.h>

// ure for a binary tree node
 typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}node;





node* Create(node* root, int value)
{

if(root == NULL) 
{
node* newnode = (node*) malloc(sizeof(node));
newnode->data= value;
newnode->right=NULL;
newnode->left=NULL;

return newnode;
}

else 

if(value<root->data)
    root->left= Create(root->left,value);
 
else 
root->right  =Create(root->right,value);









return root;
}

int main() {
    node* root = NULL; 

    
    root = Create(root, 10);
    root = Create(root, 5);
    root = Create(root, 20);
    root = Create(root, 3);
    root = Create(root, 7);

    printf("Binary Search Tree created.\n");
    
    return 0;
}
