#include <stdio.h>
#include <stdlib.h>

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

node* create_data(int x)
{ node * newnode = (node*)malloc(sizeof(node));
 newnode->data =x;
if(x == -1 ) return NULL;

printf("Enter left child of this node %d ",x);
  newnode->left =create(x);


printf("Enter right child of this node %d ",x);
  newnode->right =create(x);

return newnode; 
}







node* Parent(node* root, node* x) {
    if (root == NULL) {
        return NULL; // Cas où l'arbre est NULL
    }
    if (x == root ) {
        return NULL; // n existe pas
    }
 // Vérifie si x est un fils direct de la racine
    if (x == root->left || x == root->right ) {
        return root;
    }
 node* tmp = Parent(root->left, x);
    if (tmp == NULL) {
        tmp = Parent(root->right, x);
    }

    return tmp;
}
node* search(node* root, int x) {
    if (root == NULL) {
        return NULL; // Base case: tree is empty or we've reached a leaf
    }
   if (root->data == x) {
        return root; // Found the node with the desired value
    }

   
    node* tmp = search(root->left, x);
    if (tmp == NULL) {
        tmp = search(root->right,x); // Node found in left subtree
    }

    return tmp; // Continue search in the right subtree
}






void display(node* root) {
    if (root == NULL) { 
        return;
    }

    printf("%d ", root->data); 
    display(root->left);      
    display(root->right);      
}

int main() {
    node* root = NULL;

   
    root = create();

  int x =5;

  node* position = search(root,x);
 node* result = Parent(root,position);

if (position != NULL) {
        printf("the number %d exist .\n",x);
    } else {
        printf("the number %d doesnt exist.\n",x);
    }


    if (result != NULL) {
        printf("Le père de %d est %d\n", position->data, result->data);
    } else {
        printf("Le nœud donné n'a pas de père (racine ou non trouvé).\n");
    }
   

    printf("\nPreorder Traversal of the Binary Tree:\n");
    display(root);

    return 0;
}
