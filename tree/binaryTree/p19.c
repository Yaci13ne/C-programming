p#include <stdio.h>
#include <stdlib.h>

#define VIDE NULL

// Définition de la structure d'un nœud
typedef struct Node {
    int value;
    struct Node* left;  // Fils gauche
    struct Node* right; // Fils droit
    struct Node* parent; // Pointeur vers le parent
} Node;

// Alias pour simplifier les manipulations
typedef Node* Tree;

// Fonction pour créer un nouveau nœud
Tree Create(int value) {
    Tree newNode = (Tree)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur : Allocation mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->left = VIDE;
    newNode->right = VIDE;
    newNode->parent = VIDE;
    return newNode;
}

// Fonction pour rechercher le parent d'un nœud (si la structure n'a pas de pointeur parent)
Tree Parent(Tree root, Tree child) {
    if (root == VIDE || child == VIDE || root == child) {
        return VIDE;
    }
    if (root->left == child || root->right == child) {
        return root;
    }
    Tree tmp = Parent(root->left, child);
    if (tmp != VIDE) {
        return tmp;
    }
    return Parent(root->right, child);
}

// Fonction pour supprimer une feuille
void DeleteLeaf(Tree* root, Tree f) {
    if (*root == VIDE || f == VIDE) {
        return; // Rien à supprimer
    }

    if (*root == f) { // Cas où f est la racine
        free(f); // Libère la mémoire
        *root = VIDE; // L'arbre devient vide
        return;
    }

    // Recherche du parent
    Tree p = Parent(*root, f);
    if (p != VIDE) {
        if (p->left == f) {
            p->left = VIDE; // Supprime le lien avec le fils gauche
        } else if (p->right == f) {
            p->right = VIDE; // Supprime le lien avec le fils droit
        }
        free(f); // Libère la mémoire du nœud
    }
}

// Exemple d'utilisation
int main() {
    // Création d'un arbre binaire
    Tree root = Create(1);
    root->left = Create(2);
    root->right = Create(3);
    root->left->left = Create(4); // Feuille
    root->left->left->parent = root->left;

    // Suppression de la feuille
    printf("Suppression de la feuille 4.\n");
    DeleteLeaf(&root, root->left->left);

    // Vérification
    if (root->left->left == VIDE) {
        printf("La feuille a été supprimée avec succès.\n");
    }

    return 0;
}
