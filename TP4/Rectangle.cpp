// Fichier Rectangle.cpp

#include "Rectangle.hpp"

int Rectangle::getX() {
    return x;
}
        
int Rectangle::getY() {
    return y;
}

int Rectangle::getW(){
    return w;
}

int Rectangle::getH(){
    return h;
}

int Rectangle::getOrdre(){
    return ordre;
}

void Rectangle::setX(int nx){
    x = nx;
}

void Rectangle::setY(int ny){
    y = ny;
}

void Rectangle::setW(int nw){
    w = nw;
}

void Rectangle::setH(int nh){
    h = nh;
}

void Rectangle::setOrdre(int no){
    ordre = no;
}

Rectangle::Rectangle(int nx, int ny, int nw, int nh) : x(nx), y(ny), w(nw), h(nh) {
}

string Rectangle::toString(){
    return "Rectangle " + to_string(x) + " " + to_string(y) + " " + to_string(w) + " " + to_string(h);
}

void Rectangle::afficher(){
        cout << Rectangle::toString() << endl;
}