#include <stdio.h>
#include <stdlib.h>
#include "../includes/utils.h"



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

void genererVehicules(Vehicule *vehicules[]){

    for (int i = 0; i<4; i++){

        vehicules[i] = malloc(sizeof(Vehicule));

        if (vehicules[i] == NULL){

            perror("erreur d'allocation dynamique avec malloc");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i<=3; i++){

        *vehicules[i] = initialiserVehicule(i+1, "voiture", 30.0, "Carrefour 1");
    }
}