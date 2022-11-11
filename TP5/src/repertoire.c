#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

void lire_dossier(char *chemin);
void lire_dossier_recursif(char *chemin, int counter);
void lire_dossier_iteratif(char *chemin, int counter);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Pas assez d'arguments");
        return (0);
    }

    //lire_dossier(argv[1]); // exercice 5.1

    //lire_dossier_recursif(argv[1], 0); // exercice 5.2
    lire_dossier_iteratif(argv[1], 0); // exercice 5.2

}

/*------------------------------------------------------------------*/
/* Cette fonction lit le contenu d'un dossier et affiche le nom des fichiers 
 * entrée:
 *      char *chemin : chemin menant au dossier
*/
void lire_dossier(char *chemin)
{
   
    DIR *dir = opendir(chemin); // on ouvre le dossier dont le chemin est spécifié en 1er argument dans le terminal.

    if (dir==NULL) // echec ouverture du dossier
    {
       // printf("NICE ! \n");
        printf(" Erreur ouverture du fichier \n ");// on n'a pas réussit à ouvrir le dossier
    }

    struct dirent * ent;// la structure qui permet de récupérer l'entrée des fichiers dans le dossier ouvert

    while(1)
    {
        ent = readdir(dir);

        if(ent==NULL){break;} // si on a déjà lu tt les noms de fichiers dans le dossier on sort du while
        
        printf(" %s \n", ent->d_name); // on affiche le nom du fichier
    }

    closedir(dir);// on ferme le dossier 

}

/* Cette fonction lit le contenu d'un dossier et affiche le nom des fichiers en récursif
 * entrée:
 *      char *chemin : chemin menant au dossier
*/
void lire_dossier_recursif(char *chemin, int counter)
{
  
    DIR *dirp = opendir(chemin); // on ouvre le dossier dont le chemin est spécifié en 1er argument dans le terminal.
   
    if (dirp==NULL)
    {
        printf("Erreur ouverture du fichier\n ");
        return;
    
    }

    struct dirent * ent;// la structure qui permet de récupérer l'entrée des fichiers dans le dossier ouvert

    while(1)
    {
        ent = readdir(dirp);

        if(ent==NULL)// si on a déjà lu tt les noms de fichiers dans le dossier on sort du while
        {
            //printf("plus rien dans le dossier ! \n " );
            break;
        } 
  

        if(ent->d_type==DT_DIR)// si il s'agit d'un sous-dossier on lit ce qu'il y a à l'interrieur
        {
            //printf("%s c'est un sous dossier\n", ent->d_name);
            if ( (strcmp(ent->d_name,".") !=0) && (strcmp(ent->d_name,"..") !=0) )
            {   
                printf("Dossier : %s \n ", ent->d_name); // on affiche le nom des fichiers du dossier
                
                // composition de la route pour lire le sous-dossier
                char route[256]="";
                strcat(route, chemin);
                strcat(route, "/");
                strcat(route , ent->d_name);
                //printf(" Route : %s \n",route);
                lire_dossier_recursif(route, 1+counter); // récursivité
            }
               
        }
        else // c'est un simple fichier on affiche son nom
        {
            printf("%s \n", ent->d_name);
        }

        
    }

    closedir(dirp);// on ferme le dossier 

}

void lire_dossier_iteratif(char *chemin, int counter)
{
    //printf("nivau %d \n", counter);

    DIR *dirp = opendir(chemin); // on ouvre le dossier dont le chemin est spécifié en 1er argument dans le terminal.
 
    if (dirp==NULL)
    {
        printf("Erreur ouverture du fichier\n ");
        return;
    }

    struct dirent * ent;// la structure qui permet de récupérer l'entrée des fichiers dans le dossier ouvert

    while(1)
    {
        ent = readdir(dirp);

        if(ent==NULL)// si on a déjà lu tt les noms de fichiers dans le dossier on sort du while
        {
            //printf("plus rien dans le dossier ! \n " );
            break;
        } 
        

        if(ent->d_type==DT_DIR)// si il s'agit d'un dossier
        {
            //printf("%s c'est un sous dossier\n", ent->d_name);
            if ( (strcmp(ent->d_name,".") !=0) && (strcmp(ent->d_name,"..") !=0) )
            {   
                printf("Dossier : %s \n ", ent->d_name); // on affiche le nom des fichiers du dossier
                char route[256]="";
                strcat(route, chemin);
                strcat(route, "/");
                strcat(route , ent->d_name);
                
                lire_dossier(route);// on ouvre le dossier
            
            }
               
        }
        else 
        {
            printf("%s \n", ent->d_name);
        }

        
    }

    closedir(dirp);// on ferme le dossier 

}
