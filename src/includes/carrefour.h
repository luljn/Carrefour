#ifndef DEF_CARREFOUR
#define DEF_CARREFOUR

#include "file.h"



typedef struct Carrefour Carrefour;
struct Carrefour
{
    int id;                   // Identifiant du carrefour.
    int compteur;             // Nombre de véhicules.
    int max;                  // Nombre maximum de véhicules pouvant être accueilli.
    File* file;               // File des véhicules actuellement présents à un Carrefour.
};

Carrefour initialiserCarrefour(int id, int compteur, int max);
void afficherCaracteristiquesCarrefour(Carrefour* carrefour);
void enregistrerDonnees(char cheminFichier[50]);



#endif