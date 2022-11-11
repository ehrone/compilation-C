#include <stdio.h>
#include "liste.h"

void insertion (struct couleur *, struct liste_couleurs *);                
void parcours (struct liste_couleurs *);



struct Couleur create_tab_couleurs(int taille)
{
    srand( time( NULL ) );

        int n;
        int R , G , B , A ;
        //int taille = 10;

        struct Couleur couleur;
        
        int intamax = 256;
        int intmin = 0;
        int total = 0;

        struct Couleur Couleurs[taille];

        struct Couleur Couleursdistinct[taille];

        int Nbocur[taille];
        
        for (int i = 0; i <= (taille-1); i++) 
        {
            couleur.R = rand() % intamax;
            couleur.G = rand() % intamax;
            couleur.B = rand() % intamax;
            couleur.A = rand() % intamax;

            Couleurs[i] = couleur; 
        }
    
    return(couleur);// on renvoit l'adresse de notre première case de notre tableau
}

void insertion (struct couleur *, struct liste_couleurs *)
{
    int taille = sizeof( struct couleur)
    int len_liste = sizeof(liste_couleur)/taille;

    // on crée un plus grand tableau avec une couleur en plus
   static struct Couleur *tab_couleur = malloc( (len_liste+1)*taille );

   for(int i=0; i<= len_liste; i++)
   {
        if (i == len_liste ) // on ajoute la nouvelle couleur en fin de tableau
        {
           
            *(tab_couleur +i)->R = couleur.R;
            *(tab_couleur +i)->G = couleur.G;
            *(tab_couleur +i)->G = couleur.G;
            *(tab_couleur +i)->A = couleur.A;
        }
        else 
        {
            *(tab_couleur +i)->R = *(liste_couleurs+i)->R ;
            *(tab_couleur +i)->G = *(liste_couleurs+i)->G ;
            *(tab_couleur +i)->B = *(liste_couleurs+i)->B ;
            *(tab_couleur +i)->A = *(liste_couleurs+i)->A ;
        }
   }
   free(liste_couleurs);
   liste_couleur = tab_couleur; // on donne a notre pointeur la nouvelle adresse du debut de notre tableau
   return(tab_couleur);
}

void parcours (struct liste_couleurs *)
{
    int len_liste = sizeof(liste_couleur)/sizeof(*liste_couleurs);
    for (int i=0; i < len_liste; i++ )
    {
        printf("Couleur %i %s %s %s %s \n", i+1, *(liste_couleurs+i)->R, *(liste_couleurs+i)->G, *(liste_couleurs+i)->B, *(liste_couleurs+i)->A);
    }
}