#pragma once

#include "point.hpp"

class Cartesien : public Point
{
private:
    double _x;
    double _y;

public:
    Cartesien();
    Cartesien(double x, double y);
    Cartesien(Polaire);
    ~Cartesien();
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    void convertir(Polaire &) const override;
    void convertir(Cartesien &) const override;
    void afficher(std::stringstream &) const override;
};
