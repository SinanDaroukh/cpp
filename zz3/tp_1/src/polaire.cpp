#include "polaire.hpp"

#include <cstdio>
#include <cartesien.hpp>
#include <cmath>

Polaire::Polaire() : _th(0.0), _r(0.0) {}
Polaire::Polaire(double x, double y) : _th(x), _r(y) {}
Polaire::~Polaire() {}
double Polaire::getAngle() const
{
    return _th;
}

double Polaire::getDistance() const
{
    return _r;
}

void Polaire::setAngle(double a)
{
    _th = a;
}

void Polaire::setDistance(double d)
{
    _r = d;
}

void Polaire::convertir(Cartesien &a) const
{
    a.setX(_r * cos(_th * 3.14 / 180));
    a.setY(_r * sin(_th * 3.14 / 180));
}

std::stringstream &Polaire::afficher(std::stringstream &flux) const
{
    flux << "(a=" << getAngle() << ";d=" << getDistance() << ")";
}
