#include <stdio.h>
#include <stdlib.h>
#include "../includes/utils.h"



void genererCarrefours(Carrefour *carrefours[]){

    for (int i = 0; i < 4; i++){

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

void genererVehicules(Vehicule *vehicules[]){

    printf("\nJe suis censé générer des véhicules\n");
}