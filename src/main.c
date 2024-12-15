#include <stdio.h>
#include <stdlib.h>
#include "includes/carrefour.h"
#include "includes/vehicule.h"
#include "includes/utils.h"



int main(void){

    system("clear");
    printf("\n\n\t\t\t**** Système de gestion de carrefour ****\n\n\n");

    Carrefour *carrefours[4]; // Tableau de pointeur sur carrefour.
    Vehicule vehicules[100]; // Tableu de pointeur sur véhicule.

    Vehicule *vehicule1 = malloc(sizeof(Vehicule));

    genererCarrefours(carrefours);
    genererVehicules(vehicules);

    printf("\n");
    for(int i = 0; i<=3; i++){

        afficherCaracteristiquesCarrefour(carrefours[i]);
    }
    
    printf("\n");
    initialiserVehicule(vehicule1, 1, "voiture", 30.0, "Carrefour 1");
    afficherCaracteristiquesVehicule(vehicule1);

    for(int i = 0; i<=3; i++){

        free(carrefours[i]);
    }
    free(vehicule1);

    printf("\n\n\n");

    return 0;
}