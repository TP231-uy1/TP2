#include <stdio.h>
#include <stdlib.h>

// Définition de la structure pour une liste doublement chaînée
typedef struct cellule {
    int val;
    struct cellule *suiv;
    struct cellule *prec;
} cellule;

typedef cellule* Liste;

// Fonction pour créer un nouvel élément
cellule* NouveauNoeud(int x) {
    cellule* n = (cellule*)malloc(sizeof(cellule));
    if (n == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    n->val = x;
    n->suiv = NULL;
    n->prec = NULL;
    return n;
}

// Fonction d'insertion triée dans une liste doublement chaînée
Liste InsererTrie(Liste l, int x) {
    cellule* n = NouveauNoeud(x);

    // Cas 1 : liste vide
    if (l == NULL)
        return n;

    cellule* p = l;

    // Cas 2 : insertion en tête
    if (x <= p->val) {
        n->suiv = p;
        p->prec = n;
        return n;  // nouvelle tête
    }

    // Parcours pour trouver la position
    while (p->suiv != NULL && p->suiv->val < x) {
        p = p->suiv;
    }

    // Insertion après p
    n->suiv = p->suiv;
    n->prec = p;
    if (p->suiv != NULL)
        p->suiv->prec = n;
    p->suiv = n;

    return l;  // tête ne change pas
}

// Fonction pour afficher la liste dans les deux sens
void AfficherListe(Liste l) {
    cellule* p = l;
    printf("Liste avant → : ");
    while (p != NULL) {
        printf("%d ", p->val);
        if (p->suiv == NULL) break; // dernier élément
        p = p->suiv;
    }
    printf("\n");

    printf("Liste arrière ← : ");
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->prec;
    }
    printf("\n");
}

// Programme principal
int main() {
    Liste l = NULL;
    int n, x, i;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Entrez l'element %d : ", i+1);
        scanf("%d", &x);
        l = InsererTrie(l, x);
    }

    printf("\n=== Resultat final ===\n");
    AfficherListe(l);

    return 0;
}
