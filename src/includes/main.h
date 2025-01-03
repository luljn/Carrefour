#ifndef DEF_MAIN
#define DEF_MAIN

#include <stdlib.h>
#include <unistd.h>
#include "carrefour.h"
#include "file.h"
#include "serveur.h"
#include "utils.h"

extern int main(void);



void circulationNormale(Serveur* serveur, Carrefour* carrefours[4]){

    genererVehiculesPrioritaires(serveur->file_p, 10);
    genererVehiculesNonPrioritaires(serveur->file_np, 10);
    simulationSystemeDeCirculation1(serveur, carrefours);
    sleep(1);
    main();
}

void heureDePointe(Serveur* serveur, Carrefour* carrefours[4]){

    genererVehiculesNonPrioritaires(serveur->file_np, 50);
    simulationSystemeDeCirculation2(serveur, carrefours);
    sleep(1);
    main();
}

void libererMemoireDynamique(Serveur* serveur, Carrefour* carrefours[4]){

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
}

void gestionDesSimulations(int choix, Serveur* serveur, Carrefour* carrefours[4]){

    switch(choix){

        case '1' :
            circulationNormale(serveur, carrefours);
            break;
        
        case '2' :
            heureDePointe(serveur, carrefours);
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
}



#endif