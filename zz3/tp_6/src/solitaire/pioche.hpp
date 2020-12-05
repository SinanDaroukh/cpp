#pragma once

#include <vector>
#include "carte.hpp"

class Pioche {
    private:
        std::vector<Carte *> cartes;

    public:
        bool rienRetourne() { return cartes.empty(); }
        bool toutRetourne() {}
        bool estVide() { return cartes.empty(); }

        Carte * getProchaine() { }

};