#include <stdio.h>
#include <stdlib.h>




typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;


Node* Create(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {

        printf("Erreur : Allocation mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }
    
    newNode->value = value;

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}

// Algorithme fait_FG
void fait_FG(Node* p, Node* fg) {
   
        p->left = fg; 
     
            fg->parent = p; 
}
   


int main() {
    
    Node* p = Create(1); // Racine
    Node* fg = Create(2); 

  
    fait_FG(p, fg);

    // Vérification
    if (p->left == fg) {
        printf("Le nœud %d est maintenant le fils gauche de %d.\n", fg->value, p->value);
    }
    if (fg->parent == p) {
        printf("Le nœud %d a maintenant %d comme parent.\n", fg->value, p->value);
    }

    return 0;
}
