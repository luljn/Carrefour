#include <stdio.h>
#include <stdlib.h>
#include "../includes/file.h"
#include "../includes/serveur.h"



// Initialiser le serveur central.
Serveur initialiserServeur(){

    Serveur *serveur = malloc(sizeof(Serveur));
    serveur->file_np = initialiserFile();
    serveur->file_p = initialiserFile();
    // supprimer(serveur->file_np);
    // supprimer(serveur->file_p);

    return *serveur;
}

// Afficher les caractéristiques du serveur central.
void afficherCaractéristiquesServeur(Serveur* serveur){

    printf("\t\t\t\t\tServeur->Nombre actuels de vehicules prioritaires en attente : %d\n", longueurFile(serveur->file_p));
    printf("\t\t\t\t\tServeur->Nombre actuels de vehicules non prioritaires en attente : %d\n\n", longueurFile(serveur->file_np));
}

void serveurEnvoyerDonnees(){

}

void serveurRecevoirDonnees(){

}