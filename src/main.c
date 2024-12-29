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

    /* Initialisation des composants */
    Serveur *serveur = malloc(sizeof(Serveur));          // Serveur central.
    Carrefour *carrefours[4];                            // Tableau de pointeur sur carrefour.
    char choix;

    *serveur = initialiserServeur();
    genererCarrefours(carrefours);

    title();
    choix = menu();

    switch(choix){

        case '1' :
            genererVehiculesPrioritaires(serveur->file_p, 10);
            genererVehiculesNonPrioritaires(serveur->file_np, 10);
            simulationSystemeDeCirculation(serveur, carrefours);
            sleep(1);
            main();
            break;
        
        case '5' :
            system("clear");
            exit(EXIT_SUCCESS);
            break;
        
        default :
            system("clear");
            main();
            break;
    }

    /* Libération de la mémoire dynamique. */
    for(int i = 0; i<=3; i++){

        free(carrefours[i]->file);
    }

    for(int i = 0; i<=3; i++){

        free(carrefours[i]);
    }

    viderFile(serveur->file_p);
    viderFile(serveur->file_np);

    free(serveur->file_p);
    free(serveur->file_np);
    free(serveur);

    return 0;
}