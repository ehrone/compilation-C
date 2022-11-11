#include "fichier.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define TAILLEMAX 1000

char lire_fichier(char *chemin)
{ 
    /*Cette fonction affiche le contenu d'un fichier
    entrée :
        char *chemin : le chemin du fichier dans lequel on veut écrire
    */
    char data[1000];

    int file= open(chemin, O_RDONLY);// on ouvre le fichier 
    int size = read(file, data, 1000);  // on récupère la taille du fichier, 
                                    //on le stock ele contenu dans le tableau data
    for(int i =0; i< size; i++)
    {
        printf("%c", data[i]);
    }

    close(file);
}

void ecrire_fichier(char *chemin, char *to_add)
{
    /*Cette fonction écrit dans un  fichier
    entrée :
        char *chemin : le chemin du fichier dans lequel on veut écrire
        char *to_add : la chaine que l'on veut ajouter au fichier
        int *present : le nombre d'apparition de la chaine recherchée dans la ligne du fichier
    */
    int file = open(chemin, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    int size = write(file, to_add, strlen(to_add) );
    close(file);
}

int chercher(char * line_file, char * phrase, int *present)
{
    /*Cette fonction cherche une chaine dans une ligne de fichier et donne combien de fois la chaine est présente dans la case mémoire à l'adresse present
    entrée :
        char *line_file : la ligne de fichier dasn laquelle on cherche
        char *phrase : la chaine dont on cherche la presence
        int *present : le nombre d'apparition de la chaine recherchée dans la ligne du fichier
    retour :
        0 : chaine nn trouvée
        1 : chaine trouvée
    */
    int taille_chaine = strlen(phrase);
    int compteur =0; // les positions dans la chaine ont été trouvées dans le fichier

    for(int i=0; i < strlen(line_file); i++)
    {
        if (compteur == strlen(phrase))// si on a trouvé la chaine recherchée complete dans la ligne du fichier on arrête 
        {
            printf("chaine trouvée dans le fichier");
            (*present)++;// on incrémente de 1 la présence de la phrase dans la ligne di fichier
        }
        else if ( *(line_file+i) == *(phrase+compteur)  )// si on a un caractere de la chaine recherchée dans la ligne du fichier on teste si le suivant cotrrespond au suivant recherché
        {
            compteur++;// on incrémente le compteur de caracteres à la suite trouvés
        }
        else if (i == (strlen(line_file)-1) && *present >=1)
        {
            return(1);
        }
        else
        {
            compteur = 0; // le caractere suivant de la ligne n'est pas dans la chaine recherchée donc on retombe à 0 cohérence avec la chaine cherchée
        }

    }


}

int chercherfichier(char *chemin, char *to_find)
{
    /*Cette fonction cherche une chaine dans un fichier et affiche les lignes ou elle est trouvée ainsi que le nb de fois
    entrée :
        char *chemin : le chemin du fichier dans lequel on cherche
        char *to_find: la chaine dont on cherche la presence
    */
    
    // on affiche le contenu du fichier
    lire_fichier(chemin);

    FILE * file = fopen(chemin, "r");

    char ligne[1000];
    memset(texte,0,sizeof(ligne)); // on s'assure d'initialiser le tableau de caract à 0
    int compteur_ligne = 1;
    int present =0;

    while( fgets(ligne, 1000, file)!= NULL)// on lit une ligne du fichier et on la stocke dans le tableau ligne
    {
        if(chercher(ligne, phrase, &present)!=1)
        {
            printf("Ligne %i, %i fois\n", compteur_ligne, *present);
        }
        compteur_ligne ++;
    }
    
    close(file);
    return(0);
    
}