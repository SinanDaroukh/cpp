#ifndef _POINT_
#define _POINT_

using namespace std;

class Point {
   // par défaut, tout est privé dans une "class"

  int x, y;

  void setY(int val);
  void setX(int val);
  static int compteur;

 public:
  Point();
  Point(int x);

  int getX();
  int getY();

  static int getCompteur();

  void deplacerVers(int x, int y);
  void deplacerDe(int delta_x, int delta_y);
  void afficher();
  
};

#endif