#include <stdio.h>
#include <stdlib.h>

typedef struct cellule{
    int info;
    struct cellule*suivant;
}Cellule;
typedef Cellule*liste;

liste l=NULL;

liste creer_liste (int val){
        liste n=(liste)malloc (sizeof(Cellule));
        if (n==NULL){
            printf ("erreur d'allocation\n");
            exit(1);
        }
        n->info=val;
        n->suivant=NULL;

        return n;
    } 

liste ajouter_fin(liste l, int val) {
    liste n = creer_liste(val); 
    if (l == NULL) {
        return n;
    }

    liste t = l;
    while (t->suivant != NULL) {
        t = t->suivant;
    }
    t->suivant = n;

    return l;
}

void afficher(liste l) {
    liste t = l;
    while (t != NULL) {
        printf("%d -> ", t->info);
        t = t->suivant;
    }
    printf("NULL\n");
}



  liste occurrence (liste l,int val){
    liste t;
 
   liste m=NULL;
   t = l;  

    while (l != NULL && l->info == val) {
        m = l;
        l = l->suivant;
        free(m);
    }
    t = l;

   
        while(t!=NULL && t->suivant != NULL){
            if(t->suivant->info == val){
                m=t->suivant;
                t->suivant=t->suivant->suivant;
                free(m);
            }else
            {
                t=t->suivant;

            }
        }return l;
    
  }
   

int main() {

l = ajouter_fin(l, 10);
l = ajouter_fin(l, 30);
l = ajouter_fin(l, 20);
l = ajouter_fin(l, 40);
l = ajouter_fin(l, 20);


    printf("Liste avant suppression :\n");
    afficher(l);

    int val = 20; 
    l = occurrence(l, val);

    printf("Liste après suppression de %d :\n", val);
    afficher(l);

    return 0;
}





