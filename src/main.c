#include <stdio.h>
#include <stdlib.h>
#include "includes/carrefour.h"
#include "includes/file.h"
#include "includes/serveur.h"
#include "includes/utils.h"
#include "includes/vehicule.h"



// Fonction principale.
int main(void){

    title();

    Serveur *serveur = malloc(sizeof(Serveur));          // Serveur central.
    Carrefour *carrefours[4];                            // Tableau de pointeur sur carrefour.
    File *file;

    *serveur = initialiserServeur();
    file = initialiserFile();
    genererCarrefours(carrefours);
    genererVehiculesPrioritaires(file, 10);

    for(int i = 0; i<=3; i++){

        afficherCaracteristiquesCarrefour(carrefours[i]);
    }

    for(int i = 0; i<=3; i++){

        afficherFile(carrefours[i]->file);
    }

    afficherFile(file);
    int longueur = longueurFile(file);
    printf("\nLongueur de la file : %d\n\n", longueur);
    // afficherFile(file);
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

    printf("\n\n\n");
    viderFile(file);

    return 0;
}