#include "nuage.hpp"

Nuage::Nuage() : _size(0) {}

Nuage::~Nuage() {}

unsigned int Nuage::size()
{
    return _size;
}

void Nuage::ajouter(Polaire &a)
{
    points.push_back(&a);
    this->_size += 1;
}

void Nuage::ajouter(Cartesien &a)
{
    points.push_back(&a);
    this->_size += 1;
}

Nuage::const_iterator Nuage::begin() const
{
    return points.cbegin();
}

Nuage::const_iterator Nuage::end() const
{
    return points.cend();
}

Cartesien barycentre(Nuage &a)
{
    double x_sum, y_sum;
    Cartesien b;
    for (auto it = a.begin(); it < a.end(); it++)
    {
        (*it)->convertir(b);
        x_sum += b.getX();
        y_sum += b.getY();
    }
    b.setX(x_sum / a.size());
    b.setY(y_sum / a.size());
    return b;
}

Cartesien BarycentreCartesien::operator()(Nuage &a)
{
    return barycentre(a);
}

Polaire BarycentrePolaire::operator()(Nuage &a)
{
    Polaire p;
    barycentre(a).convertir(p);
    return p;
}