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
    
    public:

        int getX();
        int getY();
        int getW();
        int getH();

        void setX(int nx);
        void setY(int ny);
        void setW(int nw);
        void setH(int nh);

        Cercle(int x, int y, int w, int h);
        Cercle(int x1, int y1, int rayon);
        string toString();
        void afficher();
};

#endif