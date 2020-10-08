#include "polaire.hpp"

#include <cstdio>
#include <cartesien.hpp>
#include <cmath>

Polaire::Polaire() : _th(0.0), _r(0.0) {}

Polaire::Polaire(double x, double y) : _th(x), _r(y) {}

Polaire::~Polaire() {}

Polaire::Polaire(Cartesien c) : _th(atan2(c.getY(), c.getX()) * 180 / M_PI),
                                _r(hypot(c.getY(), c.getX())) {}

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
    a.setX(_r * cos(_th * M_PI / 180));
    a.setY(_r * sin(_th * M_PI / 180));
}

void Polaire::convertir(Polaire &a) const
{
    a.setDistance(this->getDistance());
    a.setAngle(this->getAngle());
}

void Polaire::afficher(std::stringstream &flux) const
{
    flux << "(a=" << getAngle() << ";d=" << getDistance() << ")";
}
