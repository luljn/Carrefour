#ifndef DEF_FILE
#define DEF_FILE

#include "vehicule.h"



typedef struct File File;
struct File
{
    Vehicule *premier;   // Pointeur sur le premier élément de la file.
};

File* initialiserFile();
void ajouter(File* file, Vehicule *vehicule);
void supprimer(File* file);
void afficherFile(File* file);
int longueurFile(File* file);
void viderFile(File* file);



#endif