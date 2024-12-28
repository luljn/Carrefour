#ifndef DEF_UTILS
#define DEF_UTILS

#include "carrefour.h"
#include "file.h"
#include "serveur.h"
#include "vehicule.h"



void title(void);
void genererCarrefours(Carrefour* carrefours[]);
void genererVehiculesPrioritaires(File* file, int nombre);
void genererVehiculesNonPrioritaires(File* file, int nombre);
void deplacerVehicule(Vehicule* vehicule, File* origine, File* arrivee); // Déplacement d'un véhicule d'une file à une autre.
void simulationSystemeDeCirculation(Serveur* serveur, Carrefour* carrefours[4]);



#endif