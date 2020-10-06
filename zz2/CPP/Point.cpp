// Fichier Point.cpp

#include <iostream>  // Inclusion d'un fichier standard
#include "Point.hpp" // Inclusion d'un fichier du répertoire courant

Point::Point(){
  cout << "Constructeur Par Défault" << endl;
}

Point::Point(int ox) : x(ox){
  cout << "Constructeur n°" << x << endl;
}

int Point::getCompteur() {
  return compteur;
}

int Point::getX() {
  return x;
}

void Point::setX(int val){
    x = val;
}


int Point::getY() {
  return y;
}

void Point::setY(int val){
    y = val;
}

void Point::deplacerVers(int x, int y){
    setX(x);
    setY(y);
}

void Point::deplacerDe(int delta_x, int delta_y){
    setY(y + delta_y);
    setX(x + delta_x);
}

void Point::afficher(){
    cout << "x : " << getX() << " y : " << getY() << endl;
}


int main(int, char**) {
    
  Point p;

  //p.setX(5);
  p.afficher();
  p.deplacerVers(12,12);
  p.afficher();
  p.deplacerDe(9,-33);
  p.afficher();

  Point p1;
  Point p2;
  Point p3;

  Point * p4 = new Point();

  return 0;
}