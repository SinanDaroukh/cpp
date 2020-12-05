#pragma once

#include "carte.hpp"
#include <vector>

class Dock {
    private:
        std::vector<Carte *> cartes;
    
    public:
        bool estVide() { return cartes.empty(); };
        Carte * getSommet() { return cartes.back(); };
        void ajouter(Carte * carte){ cartes.push_back(carte); };
        Carte * retirer() {
            Carte * value = getSommet(); 
            cartes.pop_back();
            return value;
        };
};