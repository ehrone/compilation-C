#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*----------------------------------------------------------------*/
 void creat_eleves(char *p, int nb_eleves, int nb_infos, int taille_chaine)
 {
    
    //printf("\ntest : %d",*p);
    for (int i =0; i < 2; i++)// on crée 5 eleves
    {
        char b = (char) i;
        printf("chaine %i \n", i);

        //printf("\n Elève %i \n", i);
        //strcpy((p+(i*taille_chaine*nb_infos)), "test " );//*(p+i).prenom
        strncat( (p+(i*taille_chaine*nb_infos)), &b, 1 );
        printf("modif %s \n", (p+(i*taille_chaine*nb_infos)));
        
        strcpy((p+i*taille_chaine*nb_infos+20), "test");

        strcpy((p+i*taille_chaine*nb_infos+40), "test");

        strcpy((p+i*taille_chaine*nb_infos+60), "test");
     
        strcpy((p+i*taille_chaine*nb_infos+80), "test");  
    }
    
    //printf(" début %i \n", i);
    /*
    for(int i = 0; i < nb_eleves; i++)
    {
        // toute les infos de l'étudiant
        char b = (char) i;
        printf("tour %i \n", i);
        //printf("premiere case %d \n", *(p+(i*taille*infos)));
        printf("pointeur %s \n", p );
        printf("contenue adresse pointeur %s \n", p );
        // Nom
        strcpy( (p+(i*taille*infos)) , "Nom "); // p[i][a][0] = *p+i+a ?
        strcat(  (p+(i*taille*infos)), &b );
        // prenom
        strcpy( (p+(i*taille*infos+20)) , "Prenom "); // p[i][a][0] = *p+i+a ?
        strcat(  (p+(i*taille*infos+20)), &b );
        // adresse
        strcpy( (p+(i*taille*infos+40)) , "Adresse "); // p[i][a][0] = *p+i+a ?
        strcat(  (p+(i*taille*infos+40)), &b );
        // note prog_C
        b = (char) rand()%101;
        strcpy( (p+(i*taille*infos+40)) , "Note prog_C "); // p[i][a][0] = *p+i+a ?
        strcat(  (p+(i*taille*infos+40)), &b );
        // note systeme d'exploitation
        b = (char) rand()%101 ;
        strcpy( (p+(i*taille*infos+40)) , "Note sys_exp "); // p[i][a][0] = *p+i+a ?
        strcat(  (p+(i*taille*infos+40)), &b );
    }*/
 }

/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
 void disp_eleves(char  *p, int nb, int nb_infos, int taille_chaine)
 {

    for (int i =0; i < nb; i++)// on crée 5 eleves
    {
        printf(" Elève %i \n", i+1);
        printf(" Prénom : %s \n ", (p+(i*taille_chaine*nb_infos)) );//*(p+i).prenom
        
        printf("Nom : %s \n ", (p+i*taille_chaine*nb_infos+20));

        printf("Adresse : %s \n ", (p+i*taille_chaine*nb_infos+40));

        printf("Note prog_c :  %s \n ", (p+i*taille_chaine*nb_infos+60));
     
        printf("Note sys_exp :  %s \n ", (p+i*taille_chaine*nb_infos+80));  
    }
 }

/*----------------------------------------------------------------*/


#define nb_eleves 2 // le nombre d'élèves dont il faut renseigner les données
#define nb_infos 5 // le nb d'info sur chaque élève
#define taille_max 20 // taille de chaine de carat max par info


int main (void)
{
    char eleves[nb_eleves][nb_infos][taille_max]= {
        {"nom ", "prenom 1", "addresse 1", "note 1", "note 1.1"},
        {"nom ", "prenom 2", "addresse 2", "note 2", "note 2.1"}

    };

    // on crée nos eleves
    creat_eleves(eleves[0][0],nb_eleves, nb_infos, taille_max);

    // on affiche les données de nos elèves
    disp_eleves(eleves[0][0], nb_eleves, nb_infos, taille_max);
}