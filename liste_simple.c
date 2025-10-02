#include <stdio.h>
#include <stdlib.h>


struct cellule 
{
    int val;
    struct cellule* suiv;
};


struct cellule* creercellule(int val) 
{
    struct cellule* q = (struct cellule*)malloc(sizeof(struct cellule));
    q->val = val;
    q->suiv = NULL;
    return q;
}

void inserer(struct cellule** tete, int val) 
{
    struct cellule* q = creercellule(val);
    struct cellule* p;

    if (*tete == NULL || (*tete)->val >= q->val) 
    {
        q->suiv = *tete;
        *tete = q;
    } else {
        
        p = *tete;
        while (p->suiv != NULL && p->suiv->val < q->val) 
        {
            p = p->suiv;
        }
        q->suiv = p->suiv;
        p->suiv = q;
    }
}


void afficherList(struct cellule* Cellule) {
    while (Cellule != NULL) {
        printf("%d -> ", Cellule->val);
        Cellule = Cellule->suiv;
    }
    printf("NULL\n");
}


int main() {
    struct cellule* tete = NULL;
    int val;
    while(1)
    {
      printf("entrer le nombre d'element a inserer:");
      scanf("%d",&val);
      if(val==-1)
      {
        break;
      }
      
    inserer(&tete, val);
    
    printf("Liste triée : ");
    afficherList(tete);
  }
    struct cellule *p=tete;
    struct cellule*Cellule;
    while(p!=NULL)
    {
      Cellule=p->suiv;
      free(p);
      p=Cellule;
    }

    return 0;
}

