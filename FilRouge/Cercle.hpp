#ifndef _CERCLE_
#define _CERCLE_

#include <iostream>
#include <string>

using namespace std;

class Cercle {

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

        Cercle(int x, int y, int w, int h);
        Cercle(int x1, int y1, int rayon);
        string toString();
        void afficher();
};

#endif