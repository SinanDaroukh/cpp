//#include <iostream>
#include "Point.hpp"

Point ORIGINE;

int Point::getX() {
    return x;
}
        
int Point::getY() {
    return y;
}

void Point::setX(int nx){
    x = nx;
}

void Point::setY(int ny){
    y = ny;
}

Point::Point(){
    x = 0;
    y = 0;

}

Point::Point(int nx, int ny) : 
    x(nx),
    y(ny)
{

}



//  NE PAS OUBLIER de définir ORIGINE