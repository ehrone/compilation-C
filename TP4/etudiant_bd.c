#include "fichier.h"
#include <stdio.h>
#include "etudiant2.h"

void main()
{
    data eleves[5]; //on crée un tableau de 5 eleves avec toute les infos
    creat_eleves(eleves, 2);
    //disp_eleves(eleves, 2);
    save_eleve(eleves, "eleves.txt", 5);
    
    lire_fichier("eleves.txt");

}