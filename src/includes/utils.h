#ifndef DEF_UTILS
#define DEF_UTILS

#include "carrefour.h"
#include "file.h"
#include "message.h"
#include "serveur.h"
#include "vehicule.h"



void title(void);
char menu();
void affichageDonneesSimulation(Serveur* serveur, Carrefour* carrefours[4]);
void genererCarrefours(Carrefour* carrefours[]);
void genererVehiculesPrioritaires(File* file, int nombre);
void genererVehiculesNonPrioritaires(File* file, int nombre);
void envoyerRequete(int num, Message message, Vehicule* vehicule);                 // Les véhicules envoient des requêtes pour connaîtrel'état du traffic.
void recevoirRequete(int num, Message requete);                                // Le serveur reçoit les requêtes des véhicules.
int envoyerReponse(int num, Message reponse, Vehicule* vehicule, Carrefour* carrefours[4]);              // Le serveur envoie des réponses aux véhicules pour les informer de l'état du traffic.
void recevoirReponse(int num, Message reponse);                                                         // Les véhicules reçoivent les réponses du serveur.
void deplacerVehicule(Vehicule* vehicule, File* origine, File* arrivee);          // Déplacement d'un véhicule d'une file à une autre.
void simulationSystemeDeCirculation(Serveur* serveur, Carrefour* carrefours[4]);



#endif