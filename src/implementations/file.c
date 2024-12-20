#include <stdio.h>
#include <stdlib.h>
#include "../includes/file.h"
#include "../includes/vehicule.h"



File* initialisation(){

    File *file = malloc(sizeof(*file));
    Vehicule *vehicule = malloc(sizeof(*vehicule));

    if (file == NULL || vehicule == NULL)
    {
        exit(EXIT_FAILURE);
    }

    vehicule->id = 0;
    vehicule->suivant = NULL;
    file->premier = vehicule;

    return file;
}

void ajouter(File* file, Vehicule vehicule){

}

void supprimer(File* file){
    
}