#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "../includes/file.h"
#include "../includes/serveur.h"



Serveur initialiserServeur(){

    Serveur *serveur = malloc(sizeof(Serveur));
    serveur->file_np = initialiserFile();
    serveur->file_p = initialiserFile();
    // supprimer(serveur->file_np);
    // supprimer(serveur->file_p);

    return *serveur;
}

void serveurEnvoyerDonnees(){

}

void serveurRecevoirDonnees(){

}