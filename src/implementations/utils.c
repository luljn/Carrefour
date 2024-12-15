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

    for (int i = 0; i<10; i++){

        vehicules[i] = malloc(sizeof(Vehicule));

        if (vehicules[i] == NULL){

            perror("erreur d'allocation dynamique avec malloc");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i<=9; i++){

        if(i%2 == 0 && i%3 != 0)
            *vehicules[i] = initialiserVehicule(i+1, "ambulance", 40.0, "Carrefour 1");
        else if(i%3 == 0 && i%2 != 0)
            *vehicules[i] = initialiserVehicule(i+1, "camion de pompiers", 50.0, "Carrefour 1");
        else if(i%2 == 0 && i%3 == 0)
            *vehicules[i] = initialiserVehicule(i+1, "police", 35.0, "Carrefour 1");
        else
            *vehicules[i] = initialiserVehicule(i+1, "voiture", 30.0, "Carrefour 1");
    }
}