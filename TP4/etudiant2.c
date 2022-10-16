#include "fichier.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "etudiant2.h"
#include <string.h>


char c;
/*----------------------------------------------------------------*/
void creat_eleves(data *p, int nb)
 {
    for (int i =0; i < nb; i++)// on crée 5 eleves
    {
        printf("Informations Eleve %i :\n ", (i+1));

        printf("Prénom %i :\n ", (i+1));        
        scanf("%s", (p+i)->prenom); 

        c = getchar();

        printf("Nom %i :\n ", (i+1));
        scanf("%s",  (p+i)->nom);

        c = getchar();

        printf("Adresse %i :\n ", (i+1));
        scanf("%s",  (p+i)->addresse);

        c = getchar();

        printf("Note en prog C %i :\n ", (i+1));
        scanf("%f", &((p+i)->prog_C)); 

      //  printf("%f\n", *((p+i)->prog_C));

        c = getchar();

        printf("Note en Système d'exploitation %i :\n ", (i+1));
        scanf("%f", &((p+i)->sys_exp)); 

        c = getchar();
    }
 }
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
 void disp_eleves(data *p, int nb)
 {

    for (int i =0; i < nb; i++)// on crée 5 eleves
    {
        printf(" Elève %i ", i+1);
        printf("Prenom eleve :  %s  \n ", (p+i)->prenom);
        
        printf("Nom eleve :  %s\n ", (p+i)->nom);

        printf("Adresse eleve : %s \n ", (p+i)->addresse);

        printf("Note prog_c eleve : %f\n ", (p+i)->prog_C);
     
        printf("Note sys_exp eleve  : %f\n ", (p+i)->sys_exp);
        
    }
 }
/*----------------------------------------------------------------*/

void save_eleve(data *tableau, char *chemin, int nb)
{
    int size;
    int file = open(chemin, O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR);
    
    for(int i=0; i< nb; i++)
    {
        char note_1= (char)(tableau+i)->prog_C ;
        char note_2= (char)(tableau+i)->sys_exp; 
        //itoa((tableau+i)->prog_C, note_1, 10);
        //itoa((tableau+i)->sys_exp, note_2, 10);

        write(file, &( (tableau+i)->nom), 20 );
        write(file, &( (tableau+i)->prenom), 20);
        write(file, &( (tableau+i)->addresse), 20);
        write(file, &note_1, 5);
        write(file, &note_2, 5);
       

    }
    close(file);

}

void lire_fichier(char *chemin)
{ 
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
