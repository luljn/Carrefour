#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/carrefour.h"
#include "../includes/file.h"
#include "../includes/vehicule.h"



// Initialiser un nouveau carrefour.
Carrefour initialiserCarrefour(int id, int compteur, int max){

    Carrefour *carrefour = malloc(sizeof(Carrefour));
    carrefour->id = id;
    carrefour->compteur = compteur;
    carrefour->max = max;
    carrefour->file = initialiserFile();

    return *carrefour;
}

// Afficher les caractéristiques d'un carrefour.
void afficherCaracteristiquesCarrefour(Carrefour* carrefour){

    printf("Carrefour->Id : %d\n", carrefour->id);
    printf("Carrefour->Nombre actuels de vehicules accueillis : %d\n", carrefour->compteur);
    printf("Carrefour->Nombre max de vehicules : %d\n\n", carrefour->max);
}

// Enregistrer les données de circulation d'un carrefour.
void enregistrerDonnees(char cheminFichier[50], Vehicule* vehicule, char movement[7]){

    FILE *fichier = fopen(cheminFichier, "a");

    if(fichier != NULL){

        if(strcmp(movement, "entree") == 0){

            fprintf(fichier, "Le véhicule d'id '%d' et de type '%s' est entré dans le carrefour.\n\n", vehicule->id, vehicule->type);
            fclose(fichier);
        }
        
        else if(strcmp(movement, "sortie") == 0){
            
            fprintf(fichier, "Le véhicule d'id '%d' et de type '%s' est sorti du carrefour.\n\n", vehicule->id, vehicule->type);
            fclose(fichier);
        }
    } 
    
    else{

        perror("Erreur d'ouverture du fichier");
    }
}