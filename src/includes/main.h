#ifndef DEF_MAIN
#define DEF_MAIN

#include <stdlib.h>
#include <unistd.h>
#include "carrefour.h"
#include "file.h"
#include "serveur.h"
#include "utils.h"

extern int main(void);



/* Fonction de simulation d'une circulation normale, sans emboutteillage etc... */
void circulationNormale(Serveur* serveur, Carrefour* carrefours[4]){

    genererVehiculesPrioritaires(serveur->file_p, 10);
    genererVehiculesNonPrioritaires(serveur->file_np, 10);
    simulationSystemeDeCirculation1(serveur, carrefours);
    sleep(1);
    main();
}

/* Fonction de simulation de circulation pendant des heures de pointes */
void heureDePointe(Serveur* serveur, Carrefour* carrefours[4]){

    genererVehiculesNonPrioritaires(serveur->file_np, 40);
    simulationSystemeDeCirculation2(serveur, carrefours);
    sleep(1);
    main();
}

/* Fonction de simulation de circulation pendant des accidents */
void accidents(Serveur* serveur, Carrefour* carrefours[4]){

    system("clear");
    genererVehiculesPrioritaires(serveur->file_p, 10);
    genererVehiculesNonPrioritaires(serveur->file_np, 10);
    simulationSystemeDeCirculation3(serveur, carrefours);
    sleep(1);
    main();
}

/* Fonction de simulation de circulation pendant des travaux */
void travaux(Serveur* serveur, Carrefour* carrefours[4]){

    system("clear");
    genererVehiculesPrioritaires(serveur->file_p, 5);
    genererVehiculesNonPrioritaires(serveur->file_np, 5);
    simulationSystemeDeCirculation4(serveur, carrefours);
    sleep(1);
    main();
}

/* Libérer la mémoire dynamique allouée */
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

/* Gestionnaire des types de simulation du programme */
void gestionDesSimulations(int choix, Serveur* serveur, Carrefour* carrefours[4]){

    switch(choix){

        case '1' :
            circulationNormale(serveur, carrefours);
            break;
        
        case '2' :
            heureDePointe(serveur, carrefours);
            break;
        
        case '3' :
            accidents(serveur, carrefours);
            break;
        
        case '4' :
            travaux(serveur, carrefours);
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