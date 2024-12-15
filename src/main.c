#include <stdio.h>
#include <stdlib.h>
#include "includes/carrefour.h"
#include "includes/vehicule.h"
#include "includes/utils.h"



int main(void){

    system("clear");
    printf("\n\n\t\t\t**** Système de gestion de carrefour ****\n\n\n");

    Carrefour carrefours[4] = {0};
    Vehicule vehicules[100] = {0};

    Carrefour *carrefour1 = malloc(sizeof(Carrefour)); 
    Vehicule *vehicule1 = malloc(sizeof(Vehicule));

    genererCarrefours(carrefours);
    genererVehicules(vehicules);

    printf("\n");
    *carrefour1 = initialiserCarrefour(1, 0, 10);
    afficherCaracteristiquesCarrefour(carrefour1);
    
    printf("\n");
    initialiserVehicule(vehicule1, 1, "voiture", 30.0, "Carrefour 1");
    afficherCaracteristiquesVehicule(vehicule1);

    free(carrefour1);
    free(vehicule1);

    printf("\n\n\n");

    return 0;
}