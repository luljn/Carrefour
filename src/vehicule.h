#ifndef DEF_VEHICULE
#define DEF_VEHICULE


typedef struct Vehicule Vehicule;
struct Vehicule
{
    int id;                   // Identifiant du véhicule.
    char type[100];          // Type du véhicule. (voiture, ambulance, etc...)
    float vitesse;          // Vitesse du véhicule en km/h.
    char destination[100]; // Destination du véhicule.
};

void initialiserVehicule(Vehicule* vehicule, int id, char type[100], float vitesse, char destination[100]);
void afficherCaracteristiques(Vehicule* vehicule);



#endif