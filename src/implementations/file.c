#include <stdio.h>
#include <stdlib.h>
#include "../includes/file.h"
#include "../includes/vehicule.h"



// Initialiser une nouvelle file vide.
File* initialiserFile(){

    File *file = malloc(sizeof(*file));
    if(file == NULL){

        exit(EXIT_FAILURE);
    }

    file->premier = NULL;

    return file;
}

// Ajouter un nouvel élément à la fin d'une file.
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

// Ajouter un nouvel élément au début d'une file.
void ajouterDebut(File* file, Vehicule *vehicule){

    /* Création du nouvel élément */
    Vehicule *nouveau = malloc(sizeof(*nouveau));
    
    if(file == NULL || nouveau == NULL){

        exit(EXIT_FAILURE);
    }

    nouveau = vehicule;

    /* Insertion de l'élément au début de la file */
    nouveau->suivant = file->premier;
    file->premier = nouveau;
}

// Supprimer le 1er élément d'une file.
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

// Afficher tous les éléments d'une file (du 1er au dernier).
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

    printf("\n\n");
}

// Compter le nombre d'éléments d'une file.
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

// Vider entièrement une file.
void viderFile(File* file){

    if (file == NULL){

        exit(EXIT_FAILURE);
    }

    Vehicule *actuel = file->premier;

    while(actuel != NULL){

        supprimer(file);
        actuel = actuel->suivant;
    }
}