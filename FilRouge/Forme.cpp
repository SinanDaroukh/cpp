// Fichier Forme.cpp

#include "Forme.hpp"

Forme::Forme() :
{
    Point::Point();
    this.w = 0;
    this.h = 0;
    ++nbFormes;
}

/*
int From::getPoint() {
        
}*/


int Forme::getW(){
    return w;
}

int Forme::getH(){
    return h;
}

void Forme::setPoint(int nx, int ny){
    p.setX(nx);
    p.setY(ny);
}

void Forme::setW(int nw){
    w = nw;
}

void Forme::setH(int nh){
    h = nh;
}