#ifndef DEF_CARREFOUR
#define DEF_CARREFOUR



typedef struct Carrefour Carrefour;
struct Carrefour
{
    int id;                   // Identifiant du carrefour.
    int compteur;             // Nombre de véhicules.
    int max;                  // Nombre maximum de véhicules pouvant être accueilli.
};

void initialiserCarrefour(Carrefour* carrefour, int id, int compteur, int max);
void afficherCaracteristiquesCarrefour(Carrefour* carrefour);



#endif