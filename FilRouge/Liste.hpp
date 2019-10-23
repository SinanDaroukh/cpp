#ifndef _LISTE_
#define _LISTE_

const int taille_tab = 10;

using namespace std;

class Liste {

    public:
        Cercle cercles[taille_tab];
        Rectangle rectangles[taille_tab];
        int nb_c;
        int nb_r;
        int compteur;
    
        Liste();
        int getCompteur();
        string toString();
};

#endif