#include "Forme.hpp"

unsigned int Forme::nbFormes = 0;

Forme::Forme() : _id(nbFormes++), _couleurs(COULEURS::BLEU), _w(0), _h(0)
{
    
}

Forme::Forme(Point p, COULEURS couleur) : _id(nbFormes ++),  _p(p), _couleurs(couleur), _w(0), _h(0)
{

}

Forme::Forme(Point p, COULEURS couleur, unsigned int nw, unsigned int nh) : 
_id(nbFormes++), 
_p(p), 
_couleurs(couleur), 
_w(nw), 
_h(nh)
{

}

int Forme::getW(){
    return _w;
}

int Forme::getH(){
    return _h;
}

Point& Forme::getPoint(){
    return _p;
}

COULEURS Forme::getCouleur(){
    return _couleurs;
}

void Forme::setX(int nx){
    _p.setX(nx);
}

void Forme::setY(int ny){
    _p.setY(ny);
}

void Forme::setCouleur(COULEURS ncouleur){
    _couleurs = ncouleur;
}

int Forme::getId(){
    return _id;
}

int Forme::prochainId(){
    return nbFormes;
}


// ===

void Forme::setPoint(int nx, int ny){
    _p.setX(nx);
    _p.setY(ny);
}

void Forme::setW(unsigned int nw){
    _w = nw;
}

void Forme::setH(unsigned int nh){
    _h = nh;
}
