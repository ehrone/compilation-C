#include "fichier.h"
#include <stdio.h>
#include "liste.h"

# define taille 10

int main()
{
    lire_fichier("test.txt");
    ecrire_fichier("test.txt", " bonjour 2");
    //printf(" apres ecriture\n");
    lire_fichier("test.txt");

    // création du tableau de couleurs
    struct Couleur liste_couleurs[taille];
    liste_couleurs = create_tab_couleurs(int taille);
    
    char text_couleur[1024];

    // on demande à l'utilisateur de saisir une valeur de couleur
    printf("Entrez la valeur de couleur comme suit : 'R G B A' ");
    scanf("%i %i %i %i",new_color.R );
    int R, G, B, A;
    sscanf(text_coouleur,"%i %i %i %i", &R, &G, &B, &A);

    // on remplit notre structure de couleur
    struct Couleur new_color;
    new_color.R =R;
    new_color.G =G;
    new_color.B =B;
    new_color.A =A;
    insertion (struct couleur *, struct liste_couleurs *) // on ajoute notre structure a notre tableau

    // on affiche le contenu du tableau de couleurs
    parcours (liste_couleurs *);

}