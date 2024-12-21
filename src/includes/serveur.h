#ifndef DEF_SERVEUR
#define DEF_SERVEUR

#include "file.h"



typedef struct Serveur Serveur;
struct Serveur 
{
    File* file_p;   // File des véhicules prioritaires.
    File* file_np;  // File des véhicules non prioritaires.
};



#endif