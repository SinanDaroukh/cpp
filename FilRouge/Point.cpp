// Fichier Point.cpp

#include "Point.hpp"

int Cercle::getX() {
    return x;
}
        
int Cercle::getY() {
    return y;
}

void Cercle::setX(int nx){
    x = nx;
}

void Cercle::setY(int ny){
    y = ny;
}

Point::Point(int nx, int ny) : 
    x(nx),
    y(ny)
{

}