#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/carrefour.h"
#include "../includes/file.h"
#include "../includes/serveur.h"
#include "../includes/utils.h"
#include "../includes/vehicule.h"



// Afficher le titre du programme à l'éxécution.
void title(void){ system("clear"); printf("\n\n\t\t\t\t\t\t\t\t\t**** Système de gestion de carrefour ****\n\n\n"); }

// Générer les 4 carrefours.
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

// Générer des véhicules prioritaires.
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

// Générer des véhicules non prioritaires.
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

// Fonction de simulation du système de circulation.
void simulationSystemeDeCirculation(Serveur* serveur, Carrefour* carrefours[4]){

    while(1){

        title();
        afficherCaractéristiquesServeur(serveur);
        for(int i = 0; i<=3; i++){

            afficherCaracteristiquesCarrefour(carrefours[i]);
        }

        Vehicule* vehicule1 = malloc(sizeof(Vehicule));
        if(carrefours[0]->file->premier != NULL){
            dupliquerVehicule(carrefours[0]->file->premier, vehicule1);
        }
        ajouter(carrefours[1]->file, vehicule1);
        supprimer(carrefours[0]->file);

        Vehicule* vehicule2 = malloc(sizeof(Vehicule));
        if(carrefours[3]->file->premier != NULL){
            dupliquerVehicule(carrefours[3]->file->premier, vehicule1);
        }
        ajouter(carrefours[2]->file, vehicule2);
        supprimer(carrefours[3]->file);

        sleep(1);
        if(carrefours[0]->compteur == 0 && carrefours[3]->compteur == 0){

            break;
        }
    }
}