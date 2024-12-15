#include <stdio.h>
#include <stdlib.h>
#include "includes/carrefour.h"
#include "includes/vehicule.h"



int main(void){

    system("clear");
    printf("\n\n\t\t\t**** Systeme de gestion de carrefour ****\n\n\n");

    Carrefour *carrefour1 = malloc(sizeof(Carrefour)); 
    Vehicule *vehicule1 = malloc(sizeof(Vehicule));

    initialiserCarrefour(carrefour1, 1, 0, 10);
    afficherCaracteristiquesCarrefour(carrefour1);
    printf("\n");
    initialiserVehicule(vehicule1, 1, "voiture", 30.0, "Carrefour 1");
    afficherCaracteristiquesVehicule(vehicule1);

    free(carrefour1);
    free(vehicule1);

    printf("\n\n\n");

    return 0;
}