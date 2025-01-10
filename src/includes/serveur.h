#ifndef DEF_SERVEUR
#define DEF_SERVEUR

#include "file.h"



typedef struct Serveur Serveur;
struct Serveur 
{
    File* file_p;   // File d'attente des véhicules prioritaires.
    File* file_np;  // File d'attente des véhicules non prioritaires.
};

Serveur initialiserServeur();
void afficherCaractéristiquesServeur(Serveur* serveur);



#endif