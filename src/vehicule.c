#include <stdio.h>
#include <string.h>
#include "vehicule.h"



void afficherCaracteristiques(Vehicule* vehicule){

    printf("Véhicule->Id : %d\n", vehicule->id);
    printf("Véhicule->Type : %s\n", vehicule->type);
    printf("Véhicule->Vitesse : %f km/h\n", vehicule->vitesse);
    printf("Véhicule->Destination : %s\n", vehicule->destination);
}

void initialiserVehicule(Vehicule* vehicule, int id, char type[100], float vitesse, char destination[100]){

    vehicule->id = id;
    strcpy(vehicule->type, type);
    vehicule->vitesse = vitesse;
    strcpy(vehicule->destination, destination);
}