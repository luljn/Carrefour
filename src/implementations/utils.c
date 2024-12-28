#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../includes/carrefour.h"
#include "../includes/file.h"
#include "../includes/serveur.h"
#include "../includes/utils.h"
#include "../includes/vehicule.h"



// Afficher le titre du programme à l'éxécution.
void title(void){ system("clear"); printf("\n\n\t\t\t\t\t\t\t**** Système de gestion de carrefour ****\n\n\n"); }

// Afficher les données de la simulation.
void affichageDonneesSimulation(Serveur* serveur, Carrefour* carrefours[4]){

    title();
    afficherCaractéristiquesServeur(serveur);
    for(int i = 0; i<=3; i++){

        afficherCaracteristiquesCarrefour(carrefours[i]);
    }
}

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

// Déplacer un véhicule d'une file à une autre (de la file 'origine' vers la file 'arrivee').
void deplacerVehicule(Vehicule* vehicule, File* origine, File* arrivee){

    // Vehicule* vehicule = malloc(sizeof(Vehicule));
    if(origine->premier != NULL){
        dupliquerVehicule(origine->premier, vehicule);
        ajouter(arrivee, vehicule);
        supprimer(origine);
    }
}

// Fonction de simulation du système de circulation.
void simulationSystemeDeCirculation(Serveur* serveur, Carrefour* carrefours[4]){

    while(1){

        affichageDonneesSimulation(serveur, carrefours);

        Vehicule* vehicule1 = malloc(sizeof(Vehicule));
        deplacerVehicule(vehicule1, serveur->file_p, carrefours[0]->file);
        affichageDonneesSimulation(serveur, carrefours);
        sleep(1);
        supprimer(carrefours[0]->file);
        

        Vehicule* vehicule2 = malloc(sizeof(Vehicule));
        deplacerVehicule(vehicule2, serveur->file_np, carrefours[1]->file);
        affichageDonneesSimulation(serveur, carrefours);
        sleep(1);
        supprimer(carrefours[1]->file);

        Vehicule* vehicule3 = malloc(sizeof(Vehicule));
        deplacerVehicule(vehicule1, serveur->file_p, carrefours[2]->file);
        affichageDonneesSimulation(serveur, carrefours);
        sleep(1);
        supprimer(carrefours[2]->file);
        

        Vehicule* vehicule4 = malloc(sizeof(Vehicule));
        deplacerVehicule(vehicule2, serveur->file_np, carrefours[3]->file);
        affichageDonneesSimulation(serveur, carrefours);
        sleep(1);
        supprimer(carrefours[3]->file);
        

        sleep(1);
        // if(longueurFile(serveur->file_p) == 0 && longueurFile(serveur->file_np) == 0){
        if(carrefours[0]->compteur == 0 && carrefours[1]->compteur == 0 && carrefours[2]->compteur == 0 
            && carrefours[3]->compteur == 0 && longueurFile(serveur->file_p) == 0 && longueurFile(serveur->file_np) == 0){

            break;
        }
    }
}