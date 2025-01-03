#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "includes/carrefour.h"
#include "includes/file.h"
#include "includes/main.h"
#include "includes/serveur.h"
#include "includes/utils.h"
#include "includes/vehicule.h"

extern int main(void);



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

    /* Gestion des types de simulation */
    gestionDesSimulations(choix, serveur, carrefours);

    /* Libération de la mémoire dynamique. */
    libererMemoireDynamique(serveur, carrefours);

    return 0;
}