#include <stdio.h>
#include <stdlib.h>


int * crea_tab(void);
void chercher( int *tableau, int terme);
char * crea_tab_phrases();
//void cherche_phrase(char *tab, int taille_max_phrase, int nb_phrases, char *phrase);
char compte( char *p);

//On définie la taille de notre futur tableau selon notre convenance, ici 100

int main(void)
{
    //int *tableau = crea_tab(5);

    /*for(int i=0; i< taille; i++) // verification génération du tableau
    {
        printf("[%d]", *(tableau+i) );
    }*/
    
    //chercher(tableau, 77);
    char * tableau_c = crea_tab_phrases();
    char phrase[256] = "Phrase 1";
    int run = 1;
    int len_recherche = compte(phrase);
    //cherche_phrase(tableau_c, compte(phrase), 10, phrase);


    char phrases[10][256]={
                            {"Phrase 1"},
                            {"Phrase 2"},
                            {"Phrase 3"},
                            {"Phrase 4"},
                            {"Phrase 5"},
                            {"Phrase 6"},
                            {"Phrase 7"},
                            {"Phrase 8"},
                            {"Phrase 9"},
                            {"Phrase 10"}

                                        };

    for(int i=0; i< 10; i++)
    {
        int counter =0;

        if (tableau_c[i][len_recherche] == '\0' ) // si les 2 chaines se finissent au même indice on testes termes à termes ça vaut le coup de tester le reste
        {
            for(int a=0; a< len_recherche; a++)
            {
                if(tableau_c[i][a] == phrase[a])
                {
                    counter +=1;
                }
            }
        }
        if (counter == len_recherche)
        {
            printf("La phrase est dans le tableau");
        }
    }



}


int * crea_tab(void)
{
    
    static int numbers[5];// On crée un tableau de la taille définie tout à l'heure

    
    for (int i=0; i< 5; i++ )// On remplie ce tableau de valeurs aléatoire entre 0 et 100
    {
        numbers[i] = rand()%100;// numbers[i] = *(numbers+i)
    }
    
    return numbers;// On retourne le tableau de 100 caractères
}

void chercher( int *tableau, int terme)
{
    for (int i=0; i< 5; i++)
    {
        if(*(tableau+i)== terme)
        {
            printf("\n Entier présent \n");
        }
    }
    printf("\n Entier absent \n");
}


char* crea_tab_phrases()
{
    //printf("Vous devez entrer 10 pharases")
    // On crée un tableau de la taille définie tout à l'heure
    static char phrases[10][256]={
                                            {"Phrase 1"},
                                            {"Phrase 2"},
                                            {"Phrase 3"},
                                            {"Phrase 4"},
                                            {"Phrase 5"},
                                            {"Phrase 6"},
                                            {"Phrase 7"},
                                            {"Phrase 8"},
                                            {"Phrase 9"},
                                            {"Phrase 10"}

                                        };

    return phrases;
}

/*
void cherche_phrase(char *tab, int taille_max_phrase, int nb_phrases, char *phrase)
{
   
    int counter = 0;
    int taille_recherche = compte(phrase);// taille de la str à chercher

    for (int i=0; i< nb_phrases; i++)
    {
        printf("Phrase %i tableau\n", i);
        for(int a=0; a< taille_recherche; a++)
        {
            printf("Tab : %s, phrase : %s \n", (tab+i*256+a), (phrase+a) );
            if( (tab+i*256+a) == (phrase+a) )// on compare chaque caractere 
            {
                counter += 1;
                printf("caractere %i sont les memes", a);
            }
        }

    }

    // on vérifit que tt les caracteres sont bien identiques
    if(counter == taille_recherche)
    { 
        printf("\nLa phrase est bien comprise dans le tableau \n");
    }
    else
    { 
        printf("\nLa phrase n'est pas dans le tableau \n");
    }

}*/


char compte( char *p)
{
    int counter = 0;
    int tour = 0;

    while(tour == 0)
    {
        if (*p=='\0')// par convention  on a un \n à la fin d'une chaine de caractère
        {
            counter ++; // on incrémente la taille du tableau
            p +=1; // on incrémente notre pointeur
            //printf("contenu pointeur %p\n", p);
        }
        else 
        {
            tour = 2;// on sort du while
        }
    }
    printf("taille %i\n", counter);
}
