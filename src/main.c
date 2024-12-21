#include <stdio.h>
#include <stdlib.h>
#include "includes/carrefour.h"
#include "includes/file.h"
#include "includes/serveur.h"
#include "includes/utils.h"
#include "includes/vehicule.h"



int main(void){

    title();

    Carrefour *carrefours[4];  // Tableau de pointeur sur carrefour.
    Vehicule *vehicules[10]; // Tableau de pointeur sur véhicule.

    File *file;
    file = initialiserFile();

    genererCarrefours(carrefours);
    genererVehicules(vehicules);

    for(int i = 0; i<=3; i++){

        afficherCaracteristiquesCarrefour(carrefours[i]);
    }

    for(int i = 0; i<=3; i++){

        afficherFile(carrefours[i]->file);
    }

    // for(int i = 0; i<=9; i++){

    //     afficherCaracteristiquesVehicule(vehicules[i]);
    // }

    for(int i = 0; i<=9; i++){

        ajouter(file, vehicules[i]);
    }

    afficherFile(file);

    // Libération de la mémoire dynamique.
    for(int i = 0; i<=3; i++){

        free(carrefours[i]);
    }

    for(int i = 0; i<=9; i++){

        free(vehicules[i]);
    }

    printf("\n\n\n");

    return 0;
}