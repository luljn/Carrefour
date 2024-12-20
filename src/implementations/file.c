#include <stdio.h>
#include <stdlib.h>
#include "../includes/file.h"
#include "../includes/vehicule.h"



File* initialisation(){

    File *file = malloc(sizeof(*file));
    Vehicule *vehicule = malloc(sizeof(*vehicule));

    if (file == NULL || vehicule == NULL){

        exit(EXIT_FAILURE);
    }

    vehicule->id = 0;
    vehicule->suivant = NULL;
    file->premier = vehicule;

    return file;
}

void ajouter(File* file, Vehicule *vehicule){

    /* Création du nouvel élément */
    Vehicule *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL){

        exit(EXIT_FAILURE);
    }

    nouveau = vehicule;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = file->premier;
    file->premier = nouveau;
}

void supprimer(File* file){
    
    if (file == NULL){

        exit(EXIT_FAILURE);
    }

    if (file->premier != NULL){

        Vehicule *aSupprimer = file->premier;
        file->premier = file->premier->suivant;
        free(aSupprimer);
    }
}