#ifndef __CPP4__RECTANGLE_HPP__
#define __CPP4__RECTANGLE_HPP__

#include "Forme.hpp"

#include <iostream>
#include <string>

using namespace std;

class Rectangle  {
    private:
        int x;
        int y;
        int w;
        int h;
        int ordre;
    
    public:

        int getX();
        int getY();
        int getW();
        int getH();
        int getOrdre();

        void setX(int nx);
        void setY(int ny);
        void setW(int nw);
        void setH(int nh);
        void setOrdre(int no);

        Rectangle(int x, int y, int w, int h);

        string toString();
        void afficher();

};

#endif