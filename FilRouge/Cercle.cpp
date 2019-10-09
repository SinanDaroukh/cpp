// Fichier Cercle.cpp

#include "Cercle.hpp"

int Cercle::getX() {
    return x;
}
        
int Cercle::getY() {
    return y;
}

int Cercle::getW(){
    return w;
}

int Cercle::getH(){
    return h;
}

int Cercle::getOrdre(){
    return no;
}

void Cercle::setX(int nx){
    x = nx;
}

void Cercle::setY(int ny){
    y = ny;
}

void Cercle::setW(int nw){
    w = nw;
}

void Cercle::setH(int nh){
    h = nh;
}

void Cercle::setOrdre(int no){
    ordre = no;
}

Cercle::Cercle(int nx, int ny, int nw, int nh) : x(nx), y(ny), w(nw), h(nh) {
    
}

Cercle::Cercle(int x1, int y1, int rayon) : x(x1) , y(y1) , w(rayon*2), h(rayon*2) {

}

string Cercle::toString(){
    return "CERCLE " + to_string(x) + " " + to_string(y) + " " + to_string(w) + " " + to_string(h);
}

void Cercle::afficher(){
        cout << Cercle::toString() << endl;
}