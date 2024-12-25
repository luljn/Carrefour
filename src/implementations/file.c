#include <stdio.h>
#include <stdlib.h>
#include "../includes/file.h"
#include "../includes/vehicule.h"



File* initialiserFile(){ // À l'initialisation la file est vide.

    File *file = malloc(sizeof(*file));
    // Vehicule *vehicule = malloc(sizeof(*vehicule));

    // if(file == NULL || vehicule == NULL){
    if(file == NULL){

        exit(EXIT_FAILURE);
    }

    // *vehicule = initialiserVehicule(compteurVehicule, "voiture", 30.0, "Theater");
    // vehicule->suivant = NULL;
    file->premier = NULL;

    return file;
}

// Ajout d'un nouvel élément à la fin de la liste.
void ajouter(File* file, Vehicule *vehicule){

    /* Création du nouvel élément */
    Vehicule *nouveau = malloc(sizeof(*nouveau));
    
    if(file == NULL || nouveau == NULL){

        exit(EXIT_FAILURE);
    }

    nouveau = vehicule;
    nouveau->suivant = NULL;

    if(file->premier == NULL){

        file->premier = nouveau;
    }
    
    else if(file->premier != NULL){

        Vehicule *actuel = file->premier;

        if(actuel->suivant == NULL){

            actuel->suivant = nouveau;
        }

        else{

            File *nouvelle;
            nouvelle = initialiserFile();
            nouvelle->premier = actuel->suivant;
            ajouter(nouvelle, nouveau);
        }
    }
}

// Suppression du 1er élément de la liste.
void supprimer(File* file){
    
    if(file == NULL){

        exit(EXIT_FAILURE);
    }

    if(file->premier != NULL){

        Vehicule *aSupprimer = file->premier;
        file->premier = file->premier->suivant;
        free(aSupprimer);
    }
}

// Affichage de tous les éléments de la liste (du 1er au dernier).
void afficherFile(File* file){

    if (file == NULL){

        exit(EXIT_FAILURE);
    }

    Vehicule *actuel = file->premier;

    if(actuel == NULL){

        printf("La file est vide !\n");
    }

    while(actuel != NULL){

        afficherCaracteristiquesVehicule(actuel);
        actuel = actuel->suivant;
    }

    printf("NULL\n\n");
}

// Retourne le nombre d'éléments de la liste.
int longueurFile(File* file){

    if(file->premier == NULL){

        return 0;
    }

    else{

        File* nouvelle;
        nouvelle = initialiserFile();
        nouvelle->premier = file->premier->suivant;
        return 1 + longueurFile(nouvelle);
    }
}