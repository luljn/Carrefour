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
void simulationSystemeDeCirculation(Serveur* serveur, Carrefour* carrefours[4]);



#endif