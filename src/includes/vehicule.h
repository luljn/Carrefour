#ifndef DEF_VEHICULE
#define DEF_VEHICULE

// #include "serveur.h"



extern int compteurVehicule;  // Compteur du nombre total de véhicules créés (utilisé pour avoir un id unique pour chaque véhicule).

typedef struct Vehicule Vehicule;
struct Vehicule
{
    int id;                    // Identifiant du véhicule.
    char type[100];           // Type du véhicule. (voiture, ambulance, etc...)
    int estPrioritaire;      // Priorité : 0 -> non prioritaire, 1 -> prioritaire.
    float vitesse;          // Vitesse du véhicule en km/h.
    char destination[100]; // Destination du véhicule.
    Vehicule *suivant;    // Le véhicule suivant (pour la structure des files d'attente).
};

Vehicule initialiserVehicule(int id, char type[100], int estPrioritaire, float vitesse, char destination[100]);
void afficherCaracteristiquesVehicule(Vehicule* vehicule);
void dupliquerVehicule(Vehicule* vehicule1, Vehicule* vehicule2);  // vehicule1 : véhicule à dupliquer.
// void vehiculeEnvoyerDonnees(Serveur* serveur);  // Pour envoyer des données au serveur central.
// void vehiculeRecevoirDonnees(Serveur* serveur); // Pour recevoir des données du serveur central.



#endif