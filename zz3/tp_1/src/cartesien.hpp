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
    ~Cartesien();
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    void convertir(Polaire &p) const override;
    void convertir(Cartesien &c) const override;
    std::stringstream &afficher(std::stringstream &) const override;
};
