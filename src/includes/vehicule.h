#ifndef DEF_VEHICULE
#define DEF_VEHICULE



extern int compteurVehicule;  // Compteur du nombre total de véhicules créés (utilisé pour avoir un id unique pour chaque véhicule).

typedef struct Vehicule Vehicule;
struct Vehicule
{
    int id;                   // Identifiant du véhicule.
    char type[100];          // Type du véhicule. (voiture, ambulance, etc...)
    float vitesse;          // Vitesse du véhicule en km/h.
    char destination[100]; // Destination du véhicule.
    Vehicule *suivant;    // Le véhicule suivant (pour la structure des files d'attente).
};

Vehicule initialiserVehicule(int id, char type[100], float vitesse, char destination[100]);
void afficherCaracteristiquesVehicule(Vehicule* vehicule);



#endif