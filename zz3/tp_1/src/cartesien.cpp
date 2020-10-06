#include "cartesien.hpp"

#include <cstdio>
#include <cmath>
#include <polaire.hpp>

Cartesien::Cartesien() : _x(0), _y(0) {}

Cartesien::Cartesien(double x, double y) : _x(x), _y(y) {}

Cartesien::~Cartesien() {}

double Cartesien::getX() const
{
    return _x;
}

double Cartesien::getY() const
{
    return _y;
}

void Cartesien::setX(double x)
{
    _x = x;
}

void Cartesien::setY(double y)
{
    _y = y;
}

void Cartesien::convertir(Polaire & a) const
{
    a.setDistance(hypot(_y, _x));
    a.setAngle(atan2(_y, _x) * 180 / 3.14);
}

std::stringstream &Cartesien::afficher(std::stringstream &flux) const
{
    flux << "(x=" << getX() << ";y=" << getY() << ")";
}

