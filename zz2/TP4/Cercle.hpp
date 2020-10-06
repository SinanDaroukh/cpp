#ifndef __CPP4__CERCLE_HPP__
#define __CPP4__CERCLE_HPP__

#include "Forme.hpp"

#include <iostream>
#include <string>

using namespace std;

class Cercle : public Forme
{
    private:
        unsigned int _rayon;

    public:

        unsigned int getHauteur();
        unsigned int getLargeur();
        unsigned int getRayon();

        void setRayon(unsigned int nR);

        Cercle();
        Cercle(int x1, int y1, int rayon);

        string toString();
        void afficher();

};

#endif
