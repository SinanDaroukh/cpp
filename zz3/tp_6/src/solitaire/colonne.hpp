// Gardien //---------------------------------------------------------------------------------------
#ifndef _COLONNE_HPP_
#define _COLONNE_HPP_

#include <vector>
#include "main.hpp"



class Colonne {

    private:
        std::vector<Carte *> colonne;
    public:
        bool estVide() { return colonne.empty(); }
        int getTaille() { return colonne.size(); }
        Carte * getSommet() { return colonne.back(); }
        Carte * getCarte(int pos) { return colonne.at(pos); }
        void ajouter(Main & main) { for (auto &it: main) ajouter(it); }
        void ajouter(Carte * carte) { colonne.push_back(carte); }
        void retirer(int pos, Main & main) {
            
        } 
};


// Fin //-------------------------------------------------------------------------------------------
#endif