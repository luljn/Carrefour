#include <stdio.h>
#include <stdlib.h>
#include "../includes/carrefour.h"
#include "../includes/file.h"



Carrefour initialiserCarrefour(int id, int compteur, int max){

    Carrefour *carrefour = malloc(sizeof(Carrefour));
    carrefour->id = id;
    carrefour->compteur = compteur;
    carrefour->max = max;
    carrefour->file = initialiserFile();

    return *carrefour;
}

void afficherCaracteristiquesCarrefour(Carrefour* carrefour){

    printf("Carrefour->Id : %d\n", carrefour->id);
    printf("Carrefour->Nombre actuels de vehicules accueillis : %d\n", carrefour->compteur);
    printf("Carrefour->Nombre max de vehicules : %d\n\n", carrefour->max);
}