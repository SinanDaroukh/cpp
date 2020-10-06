#ifndef __CPP4__POINT_HPP__
#define __CPP4__POINT_HPP__

#include <iostream>
#include <string>

using namespace std;

class Point {

    private:
        int x;
        int y;
    
    public:
        int getX();
        int getY();
        void setX(int nx);
        void setY(int ny);

        Point();
        Point(int x, int y);
};

// declaration d'un point ORIGINE
// il ne faudra pas oublier de l'instancier quelque part

extern Point ORIGINE;

#endif