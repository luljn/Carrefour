#include <stdio.h>
#include <stdlib.h>
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