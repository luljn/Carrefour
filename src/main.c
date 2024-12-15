#include <stdio.h>
#include <stdlib.h>
#include "includes/carrefour.h"
#include "includes/vehicule.h"
#include "includes/utils.h"



int main(void){

    system("clear");
    printf("\n\n\t\t\t**** Système de gestion de carrefour ****\n\n\n");

    Carrefour *carrefours[4];  // Tableau de pointeur sur carrefour.
    Vehicule *vehicules[10]; // Tableau de pointeur sur véhicule.

    genererCarrefours(carrefours);
    genererVehicules(vehicules);

    for(int i = 0; i<=3; i++){

        afficherCaracteristiquesCarrefour(carrefours[i]);
    }

    for(int i = 0; i<=9; i++){

        afficherCaracteristiquesVehicule(vehicules[i]);
    }

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