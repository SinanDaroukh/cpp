#ifndef _POINT_
#define _POINT_

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
        void setX();
        void setY();

        Point(int x, int y);
};

#endif