#ifndef _RECTANGLE_
#define _RECTANGLE_

#include <iostream>
#include <string>

using namespace std;

class Rectangle {

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

        Rectangle(int x, int y, int w, int h);

        string toString();
        void afficher();
    

};

#endif
