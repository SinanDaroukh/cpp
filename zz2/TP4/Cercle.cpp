// Fichier Cercle.cpp

#include "Cercle.hpp"

Cercle::Cercle() : Forme()
{

}

Cercle::Cercle(int x1, int y1, int rayon) : 
Forme( Point(x1,y1), COULEURS::VERT, rayon*2, rayon*2 ) , 
_rayon(rayon) 
{

}

unsigned int Cercle::getHauteur() {
    return getH();
}
        
unsigned int Cercle::getLargeur() {
    return getW();
}

unsigned int Cercle::getRayon(){
    return getH() / 2;
}

void Cercle::setRayon(unsigned int nR){
    _rayon = nR;
    setW(nR * 2);
    setH(nR * 2);
}


string Cercle::toString(){
    return "CERCLE " + to_string(getPoint().getX()) + " " + to_string(getPoint().getY()) + " " + to_string(getW()) + " " + to_string(getH()) + " " + to_string(getRayon());
}


void Cercle::afficher(){
        cout << Cercle::toString() << endl;
}