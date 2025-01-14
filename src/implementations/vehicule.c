#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/serveur.h"
#include "../includes/vehicule.h"



int compteurVehicule = 0;

// Initialiser un nouveau véhicule.
Vehicule initialiserVehicule(int id, char type[100], int estPrioritaire, float vitesse, char destination[100]){

    Vehicule *vehicule = malloc(sizeof(Vehicule));
    vehicule->id = id;
    strcpy(vehicule->type, type);
    vehicule->estPrioritaire = estPrioritaire;
    vehicule->vitesse = vitesse;
    strcpy(vehicule->destination, destination);
    compteurVehicule++;

    return *vehicule;
}

// Afficher les caractéristiques d'un véhicule.
void afficherCaracteristiquesVehicule(Vehicule* vehicule){

    printf("Véhicule->Id : %d\n", vehicule->id);
    printf("Véhicule->Type : %s\n", vehicule->type);
    if(vehicule->estPrioritaire != 0){
        printf("Véhicule->priorité : prioritaire\n");
    }
    else{
        printf("Véhicule->priorité : non prioritaire\n");
    }
    printf("Véhicule->Vitesse : %f km/h\n", vehicule->vitesse);
    printf("Véhicule->Destination : %s\n\n", vehicule->destination);
}

// Dupliquer un véhicule (fonctionne sur le même principe qu'un constructeur par recopie).
void dupliquerVehicule(Vehicule* vehicule1, Vehicule* vehicule2){

    vehicule2->id = vehicule1->id;
    strcpy(vehicule2->type, vehicule1->type);
    vehicule2->estPrioritaire = vehicule1->estPrioritaire;
    vehicule2->vitesse = vehicule1->vitesse;
    strcpy(vehicule2->destination, vehicule1->destination);
}