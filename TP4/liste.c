#include <stdio.h>

void insertion (struct couleur *, struct liste_couleurs *);                
void parcours (struct liste_couleurs *);

typedef struct couleur
{
    char R[255];
    char G[255];
    char B[255];
}couleur;

void insertion (struct couleur *, struct liste_couleurs *)
{
    int taille = sizeof( struct couleur)
    int len_liste = sizeof(liste_couleur)/taille;

    // on crée un plus grand tableau avec une couleur en plus
   static couleur *tab_couleur = malloc( (len_liste+1)*taille );

   for(int i=0; i<= len_liste; i++)
   {
        if (i == len_liste ) // on ajoute la nouvelle couleur en fin de tableau
        {
            printf("Entrez la valenr de rouge : ");
            scanf("%s",*(tab_couleur +i)->R );
            printf("\nEntrez la valenr de vert: ");
            scanf("%s",*(tab_couleur +i)->G );
            printf("\nEntrez la valenr de bleu : ");
            scanf("%s",*(tab_couleur +i)->B );
        }
        else 
        {
            *(tab_couleur +i)->R = *(liste_couleurs+i)->R ;
            *(tab_couleur +i)->G = *(liste_couleurs+i)->G ;
            *(tab_couleur +i)->B = *(liste_couleurs+i)->B ;
        }
   }
   liste_couleurs = tab_couleur;// on donne au pointeur de la liste de couleur originale la nouvelle adresse de départ de la nouvlle liste de couleurs
  
}

void parcours (struct liste_couleurs *)
{
    int len_liste = sizeof(liste_couleur)/sizeof(*liste_couleurs);
    for (int i=0; i < len_liste; i++ )
    {
        printf("Couleur %i %s %s %s \n", i+1, *(liste_couleurs+i)->R, *(liste_couleurs+i)->G, *(liste_couleurs+i)->B);
    }
}