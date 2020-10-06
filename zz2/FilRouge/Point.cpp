// Fichier Point.cpp

#include "Point.hpp"

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

Point::Point(int nx, int ny) : 
    x(nx),
    y(ny)
{

}