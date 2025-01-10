#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include "../includes/carrefour.h"
#include "../includes/file.h"
#include "../includes/message.h"
#include "../includes/serveur.h"
#include "../includes/utils.h"
#include "../includes/vehicule.h"



// Afficher le titre du programme à l'éxécution.
void title(void){ system("clear"); printf("\n\n\t\t\t\t\t\t**** Système de gestion de la circulation ****\n\n\n"); }

// Choisir le type de simulation.
char menu(){

    char choix;
    printf("\t\t\t\t\t\t\t1 - Circulation normale\n\n\n");
    printf("\t\t\t\t\t\t\t2 - Heure de pointe\n\n\n");
    printf("\t\t\t\t\t\t\t3 - Accidents\n\n\n");
    printf("\t\t\t\t\t\t\t4 - Travaux\n\n\n");
    printf("\t\t\t\t\t\t\t5 - Quitter\n\n\n");
    printf("\t\t\t\t\t\tVotre choix : ");
    scanf("%c", &choix);

    return choix;
}

// Afficher les données de la simulation.
void affichageDonneesSimulation(Serveur* serveur, Carrefour* carrefours[4]){

    title();
    afficherCaractéristiquesServeur(serveur);
    for(int i = 0; i<=3; i++){

        afficherCaracteristiquesCarrefour(carrefours[i]);
    }
}

// Générer les 4 carrefours.
void genererCarrefours(Carrefour *carrefours[]){

    for (int i = 0; i<4; i++){

        carrefours[i] = malloc(sizeof(Carrefour));

        if (carrefours[i] == NULL){

            perror("erreur d'allocation dynamique avec malloc");
            exit(EXIT_FAILURE);
        }
    }
    
    for(int i = 0; i<=3; i++){

        *carrefours[i] = initialiserCarrefour(i+1, 0, 10);
    }
}

// Générer des véhicules prioritaires.
void genererVehiculesPrioritaires(File* file, int nombre){

    for(int i = 0; i<nombre; i++){

        Vehicule* vehicule = malloc(sizeof(Vehicule));
        if(i%2 == 0 && i%3 != 0)
            *vehicule = initialiserVehicule(compteurVehicule, "ambulance", 1, 40.0, "Carrefour 1");
        else if(i%3 == 0 && i%2 != 0)
            *vehicule = initialiserVehicule(compteurVehicule, "camion de pompiers", 1, 50.0, "Carrefour 1");
        else if(i%2 == 0 && i%3 == 0)
            *vehicule = initialiserVehicule(compteurVehicule, "police", 1, 35.0, "Carrefour 1");
        else
            *vehicule = initialiserVehicule(compteurVehicule, "voiture du maire", 1, 30.0, "Carrefour 1");
        ajouter(file, vehicule);
    }
}

// Générer des véhicules non prioritaires.
void genererVehiculesNonPrioritaires(File* file, int nombre){

    for(int i = 0; i<nombre; i++){

        Vehicule* vehicule = malloc(sizeof(Vehicule));
        if(i%2 == 0 && i%3 != 0)
            *vehicule = initialiserVehicule(compteurVehicule, "voiture", 0, 30.0, "Carrefour 1");
        else if(i%3 == 0 && i%2 != 0)
            *vehicule = initialiserVehicule(compteurVehicule, "camion", 0, 30.0, "Carrefour 1");
        else if(i%2 == 0 && i%3 == 0)
            *vehicule = initialiserVehicule(compteurVehicule, "moto", 0, 30.0, "Carrefour 1");
        else
            *vehicule = initialiserVehicule(compteurVehicule, "voiture", 0, 30.0, "Carrefour 1");
        ajouter(file, vehicule);
    }
}

// Envoyer une requête au serveur.
void envoyerRequete(int num, Message requete, Vehicule* vehicule){

    int i;
    strcpy(requete.message, "requête : quelle disponibilité ?");
    i = msgsnd(num, &requete, strlen(requete.message), IPC_NOWAIT);
    if(i != 0){ system("clear"); fprintf(stderr, "requête non envoyé !\n\n"); }
    else{ 
        system("clear"); 
        // fprintf(stderr, "Le véhicule d'id %d et de type %s a envoyé -> %s\n\n", vehicule->id, vehicule->type, requete.message); 
        printf("Le véhicule d'id '%d' de type '%s' et de priorité '%d' , a envoyé -> %s\n\n", vehicule->id, vehicule->type, vehicule->estPrioritaire, requete.message);
    }

    // return i;
}

// Recevoir les requêtes des véhicules.
void recevoirRequete(int num, Message requete){

    if(msgrcv(num, &requete, sizeof(requete.message), 1, 0) == -1){
        perror("msgrcv");
        exit(1);
    }
    else{ printf("Serveur central -> requête reçu !\n\n"); }
}

// Envoyer une réponse aux véhicules ayant envoyés une requête.
int envoyerReponse(int num, Message reponse, Vehicule* vehicule, Carrefour* carrefours[4]){

    int carrefour_id;
    strcpy(reponse.message, "");
    for(int i = 0; i<=3; i++){

        if (longueurFile(carrefours[i]->file) < 10){

            if(i == 0)
                strcpy(reponse.message, "Disponibilité : carrefour 1");
            if(i == 1)
                strcpy(reponse.message, "Disponibilité : carrefour 2");
            if(i == 2)
                strcpy(reponse.message, "Disponibilité : carrefour 3");
            if(i == 3)
                strcpy(reponse.message, "Disponibilité : carrefour 4");
            carrefour_id = i;
            break;
        }
    }

    reponse.type = 2;
    int j;
    j = msgsnd(num, &reponse, strlen(reponse.message), IPC_NOWAIT);
    if(j != 0){ system("clear"); fprintf(stderr, "reponse non envoyé !\n\n"); }
    else{; 
        printf("Le Serveur a envoyé la réponse -> %s , au véhicule d'id '%d' de type '%s' et de priorité '%d'.\n\n", reponse.message, vehicule->id, vehicule->type, vehicule->estPrioritaire);
    }

    return carrefour_id;
}

// Recevoir la réponse du serveur.
void recevoirReponse(int num, Message reponse){

    if(msgrcv(num, &reponse, sizeof(reponse.message), 2, 0) == -1){
        perror("msgrcv");
        exit(1);
    }
    else{ printf("Véhicule -> réponse reçu : %s !\n\n", reponse.message); }
}

// Déplacer un véhicule d'une file à une autre (de la file 'origine' vers la file 'arrivee').
void deplacerVehicule(Vehicule* vehicule, File* origine, File* arrivee){

    // Vehicule* vehicule = malloc(sizeof(Vehicule));
    if(origine->premier != NULL && longueurFile(arrivee) < 10){
        
        dupliquerVehicule(origine->premier, vehicule);
        if(vehicule->estPrioritaire == 0)
            ajouter(arrivee, vehicule);
        else if(vehicule->estPrioritaire == 1)
            ajouterDebut(arrivee, vehicule);
        supprimer(origine);
    }

    else if(longueurFile(arrivee) == 10){

        
    }
}

// Fonction de simulation du système de circulation pour le 1er scénario.
void simulationSystemeDeCirculation1(Serveur* serveur, Carrefour* carrefours[4]){

    key_t cle = 1;
    int flag, num, i;
    long t = 1;
    flag = IPC_CREAT | IPC_EXCL | 0666;
    Message message; 
    message.type = t;
    // strcpy(message.message, "requête : quelle disponibilité ?");

    /* Initialisation de la file message */
    if((num = msgget(cle, flag)) == -1){

        fprintf(stderr, "Création de la file de message impossible !\n\n");
        exit(1);
    }

    system("clear");
    printf("\n\n\t\t\t\tFile de message crée avec l'identificateur %d.\n\n", num);
    sleep(2);

    typeDeCirculation("../logs/carrefour1.txt", 1);
    typeDeCirculation("../logs/carrefour2.txt", 1);
    typeDeCirculation("../logs/carrefour3.txt", 1);
    typeDeCirculation("../logs/carrefour4.txt", 1);

    affichageDonneesSimulation(serveur, carrefours);
    sleep(1);

    while(1){

        affichageDonneesSimulation(serveur, carrefours);

        // if(longueurFile(serveur->file_p) == 0 && longueurFile(serveur->file_np) == 0){
        if(carrefours[0]->compteur == 0 && carrefours[1]->compteur == 0 && carrefours[2]->compteur == 0 
            && carrefours[3]->compteur == 0 && longueurFile(serveur->file_p) == 0 && longueurFile(serveur->file_np) == 0){
            
            msgctl(num, IPC_RMID, 0);
            break;
        }

        /* Evoie de la requête au serveur */
        envoyerRequete(num, message, serveur->file_p->premier);
        sleep(2);
        /* Réception de la requête du véhicule */
        recevoirRequete(num, message);
        sleep(2);
        /* Envoie de la réponse au véhicule */
        i = envoyerReponse(num, message, serveur->file_p->premier, carrefours);
        sleep(2);
        /* Réception de la réponse du serveur */
        recevoirReponse(num, message);
        sleep(2);
        Vehicule* vehicule1 = malloc(sizeof(Vehicule));
        deplacerVehicule(vehicule1, serveur->file_p, carrefours[i]->file);
        enregistrerDonnees("../logs/carrefour1.txt", vehicule1, "entree");
        affichageDonneesSimulation(serveur, carrefours);
        sleep(1);
        enregistrerDonnees("../logs/carrefour1.txt", vehicule1, "sortie");
        supprimer(carrefours[i]->file);
        strcpy(message.message, "");

        /* Evoie de la requête au serveur */
        envoyerRequete(num, message, serveur->file_np->premier);
        sleep(2);
        /* Réception de la requête du véhicule */
        recevoirRequete(num, message);
        sleep(2);
        /* Envoie de la réponse au véhicule */
        i = envoyerReponse(num, message, serveur->file_np->premier, carrefours);
        sleep(2);
        /* Réception de la réponse du serveur */
        recevoirReponse(num, message);
        sleep(2);
        Vehicule* vehicule2 = malloc(sizeof(Vehicule));
        deplacerVehicule(vehicule2, serveur->file_np, carrefours[1]->file);
        enregistrerDonnees("../logs/carrefour2.txt", vehicule2, "entree");
        affichageDonneesSimulation(serveur, carrefours);
        sleep(1);
        enregistrerDonnees("../logs/carrefour2.txt", vehicule2, "sortie");
        supprimer(carrefours[1]->file);

        // Vehicule* vehicule3 = malloc(sizeof(Vehicule));
        // deplacerVehicule(vehicule1, serveur->file_p, carrefours[2]->file);
        // enregistrerDonnees("../logs/carrefour3.txt", vehicule3, "entree");
        // affichageDonneesSimulation(serveur, carrefours);
        // sleep(1);
        // enregistrerDonnees("../logs/carrefour3.txt", vehicule3, "sortie");
        // supprimer(carrefours[2]->file);
        

        // Vehicule* vehicule4 = malloc(sizeof(Vehicule));
        // deplacerVehicule(vehicule2, serveur->file_np, carrefours[3]->file);
        // enregistrerDonnees("../logs/carrefour4.txt", vehicule4, "entree");
        // affichageDonneesSimulation(serveur, carrefours);
        // sleep(1);
        // enregistrerDonnees("../logs/carrefour4.txt", vehicule4, "sortie");
        // supprimer(carrefours[3]->file);
        

        sleep(1);
    }
}

/* Fonction de simulation du système de circulation pour le 2ème scénario. */
void simulationSystemeDeCirculation2(Serveur* serveur, Carrefour* carrefours[4]){

    key_t cle = 1;
    int flag, num, i;
    long t = 1;
    flag = IPC_CREAT | IPC_EXCL | 0666;
    Message message; 
    message.type = t;

    /* Initialisation de la file message */
    if((num = msgget(cle, flag)) == -1){

        fprintf(stderr, "Création de la file de message impossible !\n\n");
        exit(1);
    }

    system("clear");
    printf("\n\n\t\t\t\tFile de message crée avec l'identificateur %d.\n\n", num);
    sleep(2);

    typeDeCirculation("../logs/carrefour1.txt", 2);
    typeDeCirculation("../logs/carrefour2.txt", 2);
    typeDeCirculation("../logs/carrefour3.txt", 2);
    typeDeCirculation("../logs/carrefour4.txt", 2);

    affichageDonneesSimulation(serveur, carrefours);
    sleep(1);

    while(1){

        affichageDonneesSimulation(serveur, carrefours);

        if(carrefours[0]->compteur == 0 && carrefours[1]->compteur == 0 && carrefours[2]->compteur == 0 
            && carrefours[3]->compteur == 0 && longueurFile(serveur->file_p) == 0 && longueurFile(serveur->file_np) == 0){
        // if(longueurFile(carrefours[4]->file) == 10){
            
            msgctl(num, IPC_RMID, 0);
            break;
        }

        // while(longueurFile(carrefours[0]->file) != 10 || longueurFile(carrefours[1]->file) != 10
        //         || longueurFile(carrefours[2]->file) != 10 || longueurFile(carrefours[3]->file) != 10){
        while(longueurFile(serveur->file_np) != 0 || longueurFile(serveur->file_p) != 0){

            /* Evoie de la requête au serveur */
            envoyerRequete(num, message, serveur->file_np->premier);
            sleep(2);
            /* Réception de la requête du véhicule */
            recevoirRequete(num, message);
            sleep(2);
            /* Envoie de la réponse au véhicule */
            i = envoyerReponse(num, message, serveur->file_np->premier, carrefours);
            sleep(2);
            /* Réception de la réponse du serveur */
            recevoirReponse(num, message);
            sleep(2);
            Vehicule* vehicule1 = malloc(sizeof(Vehicule));
            deplacerVehicule(vehicule1, serveur->file_np, carrefours[i]->file);

            switch(i){
            
                case 0 :
                    enregistrerDonnees("../logs/carrefour1.txt", vehicule1, "entree");
                    break;
                case 1 :
                    enregistrerDonnees("../logs/carrefour2.txt", vehicule1, "entree");
                    break;
                case 2 :
                    enregistrerDonnees("../logs/carrefour3.txt", vehicule1, "entree");
                    break;
                case 3 :
                    enregistrerDonnees("../logs/carrefour4.txt", vehicule1, "entree");
                    break;
                
                default :
                    break;
            }
            
            affichageDonneesSimulation(serveur, carrefours);
            sleep(1);
        }

        for(int k = 0; k<=3; k++){

            switch(k){
            
                case 0 :
                    enregistrerDonnees("../logs/carrefour1.txt", carrefours[k]->file->premier, "sortie");
                    supprimer(carrefours[k]->file);
                    affichageDonneesSimulation(serveur, carrefours);
                    sleep(1);
                    break;
                
                case 1 :
                    enregistrerDonnees("../logs/carrefour2.txt", carrefours[k]->file->premier, "sortie");
                    supprimer(carrefours[k]->file);
                    affichageDonneesSimulation(serveur, carrefours);
                    sleep(1);
                    break;
                
                case 2 :
                    enregistrerDonnees("../logs/carrefour3.txt", carrefours[k]->file->premier, "sortie");
                    supprimer(carrefours[k]->file);
                    affichageDonneesSimulation(serveur, carrefours);
                    sleep(1);
                    break;
                
                case 3 :
                    enregistrerDonnees("../logs/carrefour4.txt", carrefours[k]->file->premier, "sortie");
                    supprimer(carrefours[k]->file);
                    affichageDonneesSimulation(serveur, carrefours);
                    sleep(1);
                    break;
                
                default :
                    break;
            }
        }
    }

    affichageDonneesSimulation(serveur, carrefours);
    sleep(1);
}

/* Fonction de simulation du système de circulation pour le 3ème scénario. */
void simulationSystemeDeCirculation3(Serveur* serveur, Carrefour* carrefours[4]){

    key_t cle = 1;
    int flag, num, i;
    long t = 1;
    flag = IPC_CREAT | IPC_EXCL | 0666;
    Message message; 
    message.type = t;

    /* Initialisation de la file message */
    if((num = msgget(cle, flag)) == -1){

        fprintf(stderr, "Création de la file de message impossible !\n\n");
        exit(1);
    }

    system("clear");
    printf("\n\n\t\t\t\tFile de message crée avec l'identificateur %d.\n\n", num);
    sleep(2);

    system("clear");
    printf("\n\n\t\t\t\tCarrefours 2 et 4 fermés pour cause d'accidents.\n\n");
    sleep(2);

    typeDeCirculation("../logs/carrefour1.txt", 3);
    typeDeCirculation("../logs/carrefour2.txt", 3);
    typeDeCirculation("../logs/carrefour3.txt", 3);
    typeDeCirculation("../logs/carrefour4.txt", 3);

    affichageDonneesSimulation(serveur, carrefours);
    sleep(1);

    while(1){

        affichageDonneesSimulation(serveur, carrefours);

        if(carrefours[0]->compteur == 0 && carrefours[1]->compteur == 0 && carrefours[2]->compteur == 0 
            && carrefours[3]->compteur == 0 && longueurFile(serveur->file_p) == 0 && longueurFile(serveur->file_np) == 0){
            
            msgctl(num, IPC_RMID, 0);
            break;
        }
    }
}

/* Fonction de simulation du système de circulation pour le 4ème scénario. */
void simulationSystemeDeCirculation4(Serveur* serveur, Carrefour* carrefours[4]){

    key_t cle = 1;
    int flag, num, i;
    long t = 1;
    flag = IPC_CREAT | IPC_EXCL | 0666;
    Message message; 
    message.type = t;

    /* Initialisation de la file message */
    if((num = msgget(cle, flag)) == -1){

        fprintf(stderr, "Création de la file de message impossible !\n\n");
        exit(1);
    }

    system("clear");
    printf("\n\n\t\t\t\tFile de message crée avec l'identificateur %d.\n\n", num);
    sleep(2);

    system("clear");
    printf("\n\n\t\t\t\tCarrefours 2, 3 et 4 fermés pour cause de travaux.\n\n");
    sleep(2);

    typeDeCirculation("../logs/carrefour1.txt", 4);
    typeDeCirculation("../logs/carrefour2.txt", 4);
    typeDeCirculation("../logs/carrefour3.txt", 4);
    typeDeCirculation("../logs/carrefour4.txt", 4);

    affichageDonneesSimulation(serveur, carrefours);
    sleep(1);

    while(1){

        affichageDonneesSimulation(serveur, carrefours);

        if(carrefours[0]->compteur == 0 && carrefours[1]->compteur == 0 && carrefours[2]->compteur == 0 
            && carrefours[3]->compteur == 0 && longueurFile(serveur->file_p) == 0 && longueurFile(serveur->file_np) == 0){
            
            msgctl(num, IPC_RMID, 0);
            break;
        }

        /* Evoie de la requête au serveur */
        envoyerRequete(num, message, serveur->file_p->premier);
        sleep(2);
        /* Réception de la requête du véhicule */
        recevoirRequete(num, message);
        sleep(2);
        /* Envoie de la réponse au véhicule */
        i = envoyerReponse(num, message, serveur->file_p->premier, carrefours);
        sleep(2);
        /* Réception de la réponse du serveur */
        recevoirReponse(num, message);
        sleep(2);
        Vehicule* vehicule1 = malloc(sizeof(Vehicule));
        deplacerVehicule(vehicule1, serveur->file_p, carrefours[i]->file);
        switch(i){
            
            case 0 :
                enregistrerDonnees("../logs/carrefour1.txt", vehicule1, "entree");
                break;
            case 1 :
                enregistrerDonnees("../logs/carrefour2.txt", vehicule1, "entree");
                break;
            case 2 :
                enregistrerDonnees("../logs/carrefour3.txt", vehicule1, "entree");
                break;
            case 3 :
                enregistrerDonnees("../logs/carrefour4.txt", vehicule1, "entree");
                break;
            default :
                break;
        }
        affichageDonneesSimulation(serveur, carrefours);
        sleep(1);
        switch(i){
            
            case 0 :
                enregistrerDonnees("../logs/carrefour1.txt", vehicule1, "sortie");
                break;
            case 1 :
                enregistrerDonnees("../logs/carrefour2.txt", vehicule1, "sortie");
                break;
            case 2 :
                enregistrerDonnees("../logs/carrefour3.txt", vehicule1, "sortie");
                break;
            case 3 :
                enregistrerDonnees("../logs/carrefour4.txt", vehicule1, "sortie");
                break;
            default :
                break;
        }
        supprimer(carrefours[i]->file);
        strcpy(message.message, "");

        /* Evoie de la requête au serveur */
        envoyerRequete(num, message, serveur->file_np->premier);
        sleep(2);
        /* Réception de la requête du véhicule */
        recevoirRequete(num, message);
        sleep(2);
        /* Envoie de la réponse au véhicule */
        i = envoyerReponse(num, message, serveur->file_np->premier, carrefours);
        sleep(2);
        /* Réception de la réponse du serveur */
        recevoirReponse(num, message);
        sleep(2);
        Vehicule* vehicule2 = malloc(sizeof(Vehicule));
        deplacerVehicule(vehicule2, serveur->file_np, carrefours[i]->file);
        switch(i){
            
            case 0 :
                enregistrerDonnees("../logs/carrefour1.txt", vehicule1, "entree");
                break;
            case 1 :
                enregistrerDonnees("../logs/carrefour2.txt", vehicule1, "entree");
                break;
            case 2 :
                enregistrerDonnees("../logs/carrefour3.txt", vehicule1, "entree");
                break;
            case 3 :
                enregistrerDonnees("../logs/carrefour4.txt", vehicule1, "entree");
                break;
            default :
                break;
        }
        affichageDonneesSimulation(serveur, carrefours);
        sleep(1);
        switch(i){
            
            case 0 :
                enregistrerDonnees("../logs/carrefour1.txt", vehicule1, "sortie");
                break;
            case 1 :
                enregistrerDonnees("../logs/carrefour2.txt", vehicule1, "sortie");
                break;
            case 2 :
                enregistrerDonnees("../logs/carrefour3.txt", vehicule1, "sortie");
                break;
            case 3 :
                enregistrerDonnees("../logs/carrefour4.txt", vehicule1, "sortie");
                break;
            default :
                break;
            }
        supprimer(carrefours[i]->file);
    }
}