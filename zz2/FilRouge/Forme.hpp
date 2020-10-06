#ifndef _FORME_
#define _FORME_

#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;

class Forme {

    static int nbFormes;

    private:
        Point p;
        unsigned int w;
        unsigned int h;

    public:
        int getH();
        int getW();
        //int getPoint();

        void setH(int nh);
        void setW(int nw);
        void setPoint(int nx, int ny);

        Forme();




};

#endif