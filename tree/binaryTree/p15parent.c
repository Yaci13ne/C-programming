#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node;

node *Create(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
    {
        printf("Erreur : Allocation mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;

    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *Parent(node *root, node *x)
{
    if (root == NULL)
    {
        return NULL; // Cas où l'arbre est NULL
    }

    // Vérifie si x est un fils direct de la racine
    if (x == root->left || x == root->right)
    {
        return root; // Si x est un fils direct, renvoie le parent
    }

    // Recherche récursive dans les sous-arbres gauche et droit
    node *tmp = Parent(root->left, x);
    if (tmp != NULL)
    {
        return tmp; // Si x est trouvé dans le sous-arbre gauche
    }

    return Parent(root->right, x); // Recherche dans le sous-arbre droit
}

// Exemple d'utilisation
int main()
{
    // Création d'un arbre binaire pour le test

    node *root = Create(1);
    root->left = Create(2);
    root->right = Create(3);
    root->left->left = Create(4);
    root->left->right = Create(5);
    root->right->left = Create(6);
    root->right->right = Create(7);

    node *x = root->left->right;    // Rechercher le père du nœud contenant 5
    node *result = Parent(root, x); // pass nbr 1 and nbr 5

    if (result != NULL)
    {
        printf("Le père de %d est %d\n", x->value, result->value);
    }
    else
    {
        printf("Le nœud donné n'a pas de père (racine ou non trouvé).\n");
    }

    return 0;
}
