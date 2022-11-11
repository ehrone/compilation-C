/*
 * SPDX-FileCopyrightText: 2021 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

/*
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd)
{

    char data[1024];
    // la réinitialisation de l'ensemble des données
    memset(data, 0, sizeof(data));

    // Demandez à l'utilisateur d'entrer un message
    char message[1024];
    printf("Votre message (max 1000 caracteres): ");
    fgets(message, sizeof(message), stdin);
    strcpy(data, "message: ");
    strcat(data, message);

    int write_status = write(socketfd, data, strlen(data));
    if (write_status < 0)
    {
        perror("erreur ecriture");
        exit(EXIT_FAILURE);
    }

    // la réinitialisation de l'ensemble des données
    memset(data, 0, sizeof(data));

    // lire les données de la socket
    int read_status = read(socketfd, data, sizeof(data));
    if (read_status < 0)
    {
        perror("erreur lecture");
        return -1;
    }

    printf("Message recu: %s\n", data);

    return 0;
}

int envoie_operateur_numero(int socketfd)
{
    char data[1024];
    // la réinitialisation de l'ensemble des données
    memset(data, 0, sizeof(data));

    // Demandez à l'utilisateur d'entrer un calcul
    char calcule[1024];
    printf("Votre calcule (opérateur nombre1 nombre2): ");
    fgets(calcule, sizeof(calcule), stdin);
    strcpy(data, "calcule: ");
    strcat(data, calcule);

    int write_status = write(socketfd, data, strlen(data));
    if (write_status < 0)
    {
        perror("erreur ecriture");
        exit(EXIT_FAILURE);
    }

    // la réinitialisation de l'ensemble des données
    memset(data, 0, sizeof(data));

    // lire les données de la socket
    int read_status = read(socketfd, data, sizeof(data));
    if (read_status < 0)
    {
        perror("erreur lecture");
        return -1;
    }

    printf("Calcule recu: %s\n", data);

    return 0;
}


int calcul_moyenne_eleve(int socketfd)
{
    int nombre = 1;
    int nbrnote = 1;
    int notes[10];
    int resultat[10];

    char sauv1;
    char sauv2;
    char sauv3;
    char sauv4;

    char data[1024];
    // la réinitialisation de l'ensemble des données
    memset(data, 0, sizeof(data));

    while (nombre<6)
    {
        while (note<6)
        {
            char dir[1000] = "%d/note%d.txt", nombre, nbrnote;
            strcat(dir,fichier);
            FILE* file = fopen (dir, "r");
            fscanf(file,"%d",&notes[nbrnote]);
            nbrnote++;
        }

        // + Note1 Note2
        strcpy(data, "+ %d %d", notes[1], notes[2]);
        envoie_operateur_numero(socketfd);
        sauv1 = data;
        memset(data, 0, sizeof(data));


        // + Note3 Note4
        strcpy(data, "+ %d %d", notes[3], notes[4]);
        envoie_operateur_numero(socketfd);
        sauv2 = data;
        memset(data, 0, sizeof(data));


        // + Note5 (Note1 + Note2)
        strcpy(data, "+ %d %d", notes[5], sauv1);
        envoie_operateur_numero(socketfd);
        sauv3 = data;
        memset(data, 0, sizeof(data));


        // + (Note3 Note4) (Note5 (Note1 Note2))  =>  + Somme
        strcpy(data, "+ %d %d", sauv2, sauv3);
        envoie_operateur_numero(socketfd);
        sauv4 = data;
        memset(data, 0, sizeof(data));


        // / Somme 5
        strcpy(data, "/ %d 5", sauv4);
        envoie_operateur_numero(socketfd);
        memset(data, 0, sizeof(data));

        resultat[nombre] = data;

        nombre++;
        nbrnote = 0;
    }

    printf("Voici la moyenne de l'élève 1 : %c", resultat[1]);
    printf("Voici la moyenne de l'élève 2 : %c", resultat[2]);
    printf("Voici la moyenne de l'élève 3 : %c", resultat[3]);
    printf("Voici la moyenne de l'élève 4 : %c", resultat[4]);
    printf("Voici la moyenne de l'élève 5 : %c", resultat[5]);

}



int main()
{
    int socketfd;
    int choix
    struct sockaddr_in server_addr;

    /*
    * Creation d'une socket
    */
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // détails du serveur (adresse et port)
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // demande de connection au serveur
    int connect_status = connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connect_status < 0)
    {
        perror("connection serveur");
        exit(EXIT_FAILURE);
    }

    // appeler la fonction pour envoyer un message au serveur

    printf("Souhaitez vous envoyer un message?\nTapez 1\n");
    printf("Souhaitez vous effectuer une opération?\nTapez 2\n");
    printf("Souhaitez vous calculer la moyenne de la classe?\nTapez 3\n");
    scanf("%d", choix);

    // TP 5.4
    if(choix == 1)
    {
        envoie_recois_message(socketfd);
    }

    // TP 5.5
    if(choix == 2)
    {
        envoie_operateur_numero(socketfd);
    }

    // TP 5.6
    if(choix == 3)
    {
        calcul_moyenne_eleve(socketfd);
    }

    close(socketfd);
}