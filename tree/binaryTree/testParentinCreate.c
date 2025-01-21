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

   node* x = root->left->right;
 node* result = Parent(root, x);

    if (result != NULL) {
        printf("Le père de %d est %d\n", x->data, result->data);
    } else {
        printf("Le nœud donné n'a pas de père (racine ou non trouvé).\n");
    }
   

    printf("\nPreorder Traversal of the Binary Tree:\n");
    display(root);

    return 0;
}
