#ifndef __CPP4__FORME_HPP__
#define __CPP4__FORME_HPP__

#include "Point.hpp"

// enum COULEURS { BLANC, NOIR, BLEU, BLOUGE, ROUGE, JAUNE};
enum class COULEURS { BLANC, NOIR, BLEU, BLOUGE, ROUGE, JAUNE, VERT};

class Forme { 

    static unsigned int nbFormes;

    private:
        unsigned int _id;
        Point _p;
        COULEURS _couleurs;
        unsigned int _w;
        unsigned int _h;

    public:
        Forme();
        Forme(Point p, COULEURS couleur);
        Forme(Point p, COULEURS couleur, unsigned int nw, unsigned int nh);

        int getH();
        int getW();
        Point& getPoint();
        COULEURS getCouleur();

        void setX(int nx);
        void setY(int ny);
        void setCouleur(COULEURS ncouleur);
        
        int getId();
        static int prochainId();

        void setH(unsigned int nh);
        void setW(unsigned int nw);
        void setPoint(int nx, int ny);
};

#endif