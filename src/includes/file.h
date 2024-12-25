#ifndef DEF_FILE
#define DEF_FILE

#include "vehicule.h"



typedef struct File File;
struct File
{
    Vehicule *premier;
};

File* initialiserFile();
void ajouter(File* file, Vehicule *vehicule);
void supprimer(File* file);
void afficherFile(File* file);
int longueurFile(File* file);



#endif