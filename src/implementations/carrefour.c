#include <stdio.h>
#include "../includes/carrefour.h"



void initialiserCarrefour(Carrefour* carrefour, int id, int compteur, int max){

    carrefour->id = id;
    carrefour->compteur = compteur;
    carrefour->max = max;
}

void afficherCaracteristiquesCarrefour(Carrefour* carrefour){

    printf("Carrefour->Id : %d\n", carrefour->id);
    printf("Carrefour->Nombre actuels de vehicules accueillis : %d\n", carrefour->compteur);
    printf("Carrefour->Nombre max de vehicules : %d\n", carrefour->max);
}