#include <stdio.h>
#include <stdlib.h>
#include "includes/vehicule.h"



int main(void){

    system("clear");
    printf("\n\n\t\t\t**** Systeme de gestion de carrefour ****\n\n\n");
    Vehicule *vehicule1 = malloc(sizeof(Vehicule));
    initialiserVehicule(vehicule1, 1, "voiture", 30.0, "Carrefour 1");
    afficherCaracteristiques(vehicule1);
    free(vehicule1);
    printf("\n\n\n");

    return 0;
}