#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    int data;
    struct noeud *suiv;
} noeud;

noeud *last = NULL;

void insertion_tete(int valeur);
void insertion_queue(int valeur);
void afficher_liste();
void liberer_liste();
void menu();
void creer_liste_initiale();

// Insertion en tete
void insertion_tete(int valeur){
    noeud *temp = (noeud*)malloc(sizeof(noeud));
    if (temp == NULL){
        printf("Erreur : Allocation mémoire.\n");
        return;
    }
    temp->data = valeur;
    if (last == NULL){
        last = temp;
        last->suiv = last;
    } else {
        temp->suiv = last->suiv;
        last->suiv = temp;
    }
    printf("INSERTION DE %d EN TETE REUSSIE.\n", valeur);
}

// Insertion en queue
void insertion_queue(int valeur){
    noeud *temp = (noeud*)malloc(sizeof(noeud));
    if (temp == NULL){
        printf("Erreur : Allocation mémoire.\n");
        return;
    }
    temp->data = valeur;
    if (last == NULL){
        last = temp;
        last->suiv = last;
    } else {
        temp->suiv = last->suiv;
        last->suiv = temp;
        last = temp;
    }
    printf("INSERTION DE %d EN QUEUE REUSSIE.\n", valeur);
}

// Affichage de la liste
void afficher_liste(){
    noeud *p;
    if (last == NULL){
        printf("Etat actuel de la liste : [Vide]\n");
        return;
    }
    p = last->suiv;
    printf("ETAT ACTUEL DE LA LISTE : ");
    do{
        printf("%d", p->data);
        p = p->suiv;
        if(p != last->suiv){
            printf(" -> ");
        }
    } while (p != last->suiv);
    printf(" -> (DEBUT)\n");
}

// Libération de la mémoire
void liberer_liste(){
    if (last == NULL) return;
    
    noeud *courant = last->suiv;
    noeud *temp;
    last->suiv = NULL;

    while (courant != NULL){
        temp = courant;
        courant = courant->suiv;
        free(temp);
    }
    last = NULL;
}

// Création de la liste initiale
void creer_liste_initiale(){
    int taille, i, valeur;
    
    printf("\n=== CREATION DE LA LISTE INITIALE ===\n");
    
    // Demander la taille de la liste
    do {
        printf("Entrez la taille de la liste (au moins 1) : ");
        if (scanf("%d", &taille) != 1) {
            printf("Saisie invalide. Veuillez entrer un nombre.\n");
            while(getchar() != '\n');
            continue;
        }
        if (taille < 1) {
            printf("La taille doit etre au moins 1.\n");
        }
    } while (taille < 1);
    
    // Saisie des éléments
    printf("\nSaisie des %d elements de la liste :\n", taille);
    for(i = 0; i < taille; i++){
        printf("Element %d : ", i + 1);
        if (scanf("%d", &valeur) != 1) {
            printf("Saisie invalide. Veuillez entrer un nombre entier.\n");
            while(getchar() != '\n');
            i--; // Répéter cette itération
            continue;
        }
        insertion_queue(valeur);
    }
    
    printf("\nListe initiale creee avec succes !\n");
    afficher_liste();
}

// Menu principal
void menu() {
    int choice, value;

    printf("\n--- GESTION DE LISTE SIMPLEMENT CHAINEE CIRCULAIRE ---\n");

    // Créer la liste initiale d'abord
    creer_liste_initiale();
    
    // Menu des opérations
    do {
        printf("\n=========================================\n");
        afficher_liste();
        printf("\nQue souhaitez-vous faire ?\n");
        printf("1. Insérer en TETE\n");
        printf("2. Insérer en QUEUE\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Saisie invalide. Veuillez entrer un nombre.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
            case 2:
                printf("Entrez la valeur numérique à insérer : ");
                if (scanf("%d", &value) != 1) {
                    printf("Saisie invalide pour la valeur.\n");
                    while(getchar() != '\n');
                    break;
                }
                if (choice == 1) {
                    insertion_tete(value);
                } else {
                    insertion_queue(value);
                }
                printf("\nApres insertion : ");
                afficher_liste();
                break;
            case 3:
                printf("\nSortie du programme...\n");
                break;
            default:
                printf("Choix invalide. Veuillez sélectionner 1, 2 ou 3.\n");
        }
    } while (choice != 3);
}

// Fonction principale
int main() {
    menu();
    liberer_liste();
    printf("MEMOIRE DE LA LISTE LIBEREE. AU REVOIR!\n");
    return 0;
}