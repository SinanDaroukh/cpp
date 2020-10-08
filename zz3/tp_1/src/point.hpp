#pragma once

#include <sstream>
#include <ostream>

class Cartesien;
class Polaire;
class Point
{

public:
    Point();
    ~Point();
    virtual void convertir(Cartesien &) const = 0;
    virtual void convertir(Polaire &) const = 0;
    virtual void afficher(std::stringstream &) const = 0;
};

void operator<<(std::stringstream &a, const Point &b);
