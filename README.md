# Gestion d'une Liste Doublement Chaînée Triée en C

Ce programme en langage C permet de manipuler une **liste doublement chaînée triée**.  
L'utilisateur peut insérer des entiers dans la liste, et ceux-ci sont automatiquement placés à la bonne position pour garder l'ordre croissant.

---

## Contenu du projet

- `exo33.c` : code source principal contenant :
  - La définition de la structure `cellule`
  - La fonction `NouveauNoeud` pour créer un nœud
  - La fonction `InsererTrie` pour insérer un élément dans la liste en respectant l’ordre
  - La fonction `AfficherListe` pour afficher le contenu de la liste
  - La fonction `main` pour gérer les entrées utilisateur et tester l’algorithme

---

##  Compilation et exécution

### Compilation
Utilisez `gcc` pour compiler le programme :
```bash
gcc exo33.c -o exo33
```

### Exécution
Lancez ensuite l’exécutable :
```bash
./exo33
```

---

##  Exemple d’utilisation

```
Entrez un entier à insérer (0 pour arrêter) : 5
Entrez un entier à insérer (0 pour arrêter) : 3
Entrez un entier à insérer (0 pour arrêter) : 8
Entrez un entier à insérer (0 pour arrêter) : 0

Liste triée : 3 5 8
```

---

## Structure de données utilisée

```c
typedef struct cellule {
    int val;
    struct cellule *suiv;  // pointeur vers le suivant
    struct cellule *prec;  // pointeur vers le précédent
} cellule;
```

Chaque élément contient une valeur entière (`val`) ainsi que deux pointeurs (`suiv` et `prec`) permettant de naviguer dans les deux sens.

---

## Fonctionnalités

- Insertion automatique dans l’ordre croissant
- Gestion des cas particuliers :
  - Liste vide
  - Insertion en tête
  - Insertion en milieu ou en fin
- Affichage de la liste complète après insertion

---

## Exemple de sortie

```
Insertion dans une liste doublement chaînée triée
---------------------------------
Entrez un entier à insérer (0 pour arrêter) : 10
Entrez un entier à insérer (0 pour arrêter) : 2
Entrez un entier à insérer (0 pour arrêter) : 15
Entrez un entier à insérer (0 pour arrêter) : 7
Entrez un entier à insérer (0 pour arrêter) : 0

Liste triée : 2 7 10 15
```

---

##  Auteur

