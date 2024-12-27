#include <stdio.h>
#include <stdlib.h>
#include "includes/carrefour.h"
#include "includes/file.h"
#include "includes/serveur.h"
#include "includes/utils.h"
#include "includes/vehicule.h"



int main(void){

    title();

    Serveur *serveur = malloc(sizeof(Serveur));          // Serveur central.
    Carrefour *carrefours[4];                            // Tableau de pointeur sur carrefour.
    // Vehicule *vehicules[10];                             // Tableau de pointeur sur véhicule.
    File *file;

    *serveur = initialiserServeur();
    file = initialiserFile();
    genererCarrefours(carrefours);
    // genererVehicules(vehicules);
    genererVehiculesNonPrioritaires(file, 1);

    for(int i = 0; i<=3; i++){

        afficherCaracteristiquesCarrefour(carrefours[i]);
    }

    for(int i = 0; i<=3; i++){

        afficherFile(carrefours[i]->file);
    }

    // for(int i = 0; i<=9; i++){

    //     afficherCaracteristiquesVehicule(vehicules[i]);
    // }

    // for(int i = 0; i<=9; i++){

    //     ajouter(file, vehicules[i]);
    // }

    // afficherFile(file);
    // int longueur = longueurFile(file);
    // printf("\nLongueur de la file : %d\n\n", longueur);
    afficherFile(file);
    afficherFile(serveur->file_np);
    afficherFile(serveur->file_p);

    // enregistrerDonnees("../logs/carrefour1.txt", file->premier, "entree");

    // enregistrerDonnees("../logs/carrefour1.txt", file->premier, "sortie");
    // supprimer(file);
    // afficherFile(file);
    // longueur = longueurFile(file);
    // printf("\nLongueur de la file : %d\n\n", longueur);

    // enregistrerDonnees("../logs/carrefour1.txt", file->premier, "entree");

    // enregistrerDonnees("../logs/carrefour1.txt", file->premier, "sortie");
    // supprimer(file);
    // afficherFile(file);
    // longueur = longueurFile(file);
    // printf("\nLongueur de la file : %d\n\n", longueur);

    // Libération de la mémoire dynamique.
    for(int i = 0; i<=3; i++){

        free(carrefours[i]);
    }

    // for(int i = 2; i<=9; i++){

    //     free(vehicules[i]);
    // }

    printf("\n\n\n");
    supprimer(file);

    return 0;
}