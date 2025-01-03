#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

    carrefour->compteur = longueurFile(carrefour->file);
    printf("\t\t\t\tCarrefour->Id : %d\n", carrefour->id);
    printf("\t\t\t\tCarrefour->Nombre actuels de vehicules accueillis : %d\n", carrefour->compteur);
    printf("\t\t\t\tCarrefour->Nombre max de vehicules : %d\n\n", carrefour->max);
}

// Enregistrer les données de circulation d'un carrefour.
void enregistrerDonnees(char cheminFichier[23], Vehicule* vehicule, char movement[7]){

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

        perror("Erreur d'ouverture du fichier\n\n");
    }
}

// Enregistrer le type de circulation pour les logs.
void typeDeCirculation(char cheminFichier[23], int typeDeCirculation){

    FILE *fichier = fopen(cheminFichier, "a");
    time_t maintenant;
    struct tm *heure_locale;

    maintenant = time(NULL);
    heure_locale = localtime(&maintenant);

    if(fichier != NULL){

        switch(typeDeCirculation){

            case 1 :
                fprintf(fichier, "\t\t\t\t\t\t\t*** Circulation Normale *** du  %02d/%02d/%d à %dh:%dmin:%dsec\n\n", heure_locale->tm_mday, heure_locale->tm_mon + 1, heure_locale->tm_year + 1900, heure_locale->tm_hour, heure_locale->tm_min, heure_locale->tm_sec);
                fclose(fichier);
                break;
            
            case 2 :
                fprintf(fichier, "\t\t\t\t\t\t\t*** Heure De Pointe *** du  %02d/%02d/%d à %dh:%dmin:%dsec\n\n", heure_locale->tm_mday, heure_locale->tm_mon + 1, heure_locale->tm_year + 1900, heure_locale->tm_hour, heure_locale->tm_min, heure_locale->tm_sec);
                fclose(fichier);
                break;
            
            case 3 :
                fprintf(fichier, "\t\t\t\t\t\t\t*** Accidents *** du  %02d/%02d/%d à %dh:%dmin:%dsec\n\n", heure_locale->tm_mday, heure_locale->tm_mon + 1, heure_locale->tm_year + 1900, heure_locale->tm_hour, heure_locale->tm_min, heure_locale->tm_sec);
                fclose(fichier);
                break;
            
            case 4 :
                fprintf(fichier, "\t\t\t\t\t\t\t*** Travaux *** du  %02d/%02d/%d à %dh:%dmin:%dsec\n\n", heure_locale->tm_mday, heure_locale->tm_mon + 1, heure_locale->tm_year + 1900, heure_locale->tm_hour, heure_locale->tm_min, heure_locale->tm_sec);
                fclose(fichier);
                break;

            default :
                break;
        }
        
    }

    else{

        perror("Erreur d'ouverture du fichier\n\n");
    }
}