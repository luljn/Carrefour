#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes/carrefour.h"
#include "includes/file.h"
#include "includes/serveur.h"
#include "includes/utils.h"
#include "includes/vehicule.h"



// Fonction principale.
int main(void){

    Serveur *serveur = malloc(sizeof(Serveur));          // Serveur central.
    Carrefour *carrefours[4];                            // Tableau de pointeur sur carrefour.

    *serveur = initialiserServeur();
    genererCarrefours(carrefours);
    genererVehiculesPrioritaires(carrefours[0]->file, 10);
    genererVehiculesNonPrioritaires(carrefours[3]->file, 10);

    while(1){

        title();
        simulationSystemeDeCirculation(carrefours);

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

    // for(int i = 0; i<=3; i++){

    //     printf("File des véhicules présents au Carrefour %d.\n", i+1);
    //     afficherFile(carrefours[i]->file);
    // }

    // printf("***File des véhicules prioritaires en attente***\n");
    // afficherFile(serveur->file_p);
    // printf("Longueur de la file des véhicules prioritaires en attente : %d.\n\n\n", longueurFile(serveur->file_p));

    // printf("***File des véhicules non prioritaires en attente***\n");
    // afficherFile(serveur->file_np);
    // printf("Longueur de la file des véhicules non prioritaires en attente : %d.\n\n\n", longueurFile(serveur->file_np));

    // Libération de la mémoire dynamique.
    for(int i = 0; i<=3; i++){

        free(carrefours[i]);
    }

    for(int i = 0; i<=3; i++){

        free(carrefours[i]->file);
    }

    viderFile(serveur->file_p);
    viderFile(serveur->file_np);

    free(serveur);

    printf("\n\n\n");

    return 0;
}