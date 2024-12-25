#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/vehicule.h"



int compteurVehicule = 0;

Vehicule initialiserVehicule(int id, char type[100], float vitesse, char destination[100]){

    Vehicule *vehicule = malloc(sizeof(Vehicule));
    vehicule->id = id;
    strcpy(vehicule->type, type);
    vehicule->vitesse = vitesse;
    strcpy(vehicule->destination, destination);
    compteurVehicule++;

    return *vehicule;
}

void afficherCaracteristiquesVehicule(Vehicule* vehicule){

    printf("Véhicule->Id : %d\n", vehicule->id);
    printf("Véhicule->Type : %s\n", vehicule->type);
    printf("Véhicule->Vitesse : %f km/h\n", vehicule->vitesse);
    printf("Véhicule->Destination : %s\n\n", vehicule->destination);
}

void vehiculeEnvoyerDonnees(Serveur* serveur){

}

void vehiculeRecevoirDonnees(Serveur* serveur){

}