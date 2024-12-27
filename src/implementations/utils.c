#include <stdio.h>
#include <stdlib.h>
#include "../includes/file.h"
#include "../includes/utils.h"
#include "../includes/vehicule.h"



void title(void){ system("clear"); printf("\n\n\t\t\t**** Système de gestion de carrefour ****\n\n\n"); }

void genererCarrefours(Carrefour *carrefours[]){

    for (int i = 0; i<4; i++){

        carrefours[i] = malloc(sizeof(Carrefour));

        if (carrefours[i] == NULL){

            perror("erreur d'allocation dynamique avec malloc");
            exit(EXIT_FAILURE);
        }
    }
    
    for(int i = 0; i<=3; i++){

        *carrefours[i] = initialiserCarrefour(i+1, 0, 10);
    }
}

void genererVehiculesPrioritaires(File* file, int nombre){

    for(int i = 0; i<nombre; i++){

        Vehicule* vehicule = malloc(sizeof(Vehicule));
        if(i%2 == 0 && i%3 != 0)
            *vehicule = initialiserVehicule(compteurVehicule, "ambulance", 1, 40.0, "Carrefour 1");
        else if(i%3 == 0 && i%2 != 0)
            *vehicule = initialiserVehicule(compteurVehicule, "camion de pompiers", 1, 50.0, "Carrefour 1");
        else if(i%2 == 0 && i%3 == 0)
            *vehicule = initialiserVehicule(compteurVehicule, "police", 1, 35.0, "Carrefour 1");
        else
            *vehicule = initialiserVehicule(compteurVehicule, "voiture du maire", 1, 30.0, "Carrefour 1");
        ajouter(file, vehicule);
    }
}

void genererVehiculesNonPrioritaires(File* file, int nombre){

    for(int i = 0; i<nombre; i++){

        Vehicule* vehicule = malloc(sizeof(Vehicule));
        if(i%2 == 0 && i%3 != 0)
            *vehicule = initialiserVehicule(compteurVehicule, "voiture", 0, 30.0, "Carrefour 1");
        else if(i%3 == 0 && i%2 != 0)
            *vehicule = initialiserVehicule(compteurVehicule, "camion", 0, 30.0, "Carrefour 1");
        else if(i%2 == 0 && i%3 == 0)
            *vehicule = initialiserVehicule(compteurVehicule, "moto", 0, 30.0, "Carrefour 1");
        else
            *vehicule = initialiserVehicule(compteurVehicule, "voiture", 0, 30.0, "Carrefour 1");
        ajouter(file, vehicule);
    }
}