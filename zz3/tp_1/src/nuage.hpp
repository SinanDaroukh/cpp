#pragma once

#include "cartesien.hpp"
#include "polaire.hpp"

#include <vector>

class Nuage
{
private:
    std::vector<Point *> points;
    unsigned int _size;

public:
    // typedef std::vector<Point *>::const_iterator const_iterator;
    using const_iterator = std::vector<Point *>::const_iterator;
    Nuage();
    ~Nuage();
    unsigned int size();
    void ajouter(Cartesien &);
    void ajouter(Polaire &);
    const_iterator begin() const;
    const_iterator end() const;
};

Cartesien barycentre(Nuage&);

class BarycentreCartesien
{
public:
    Cartesien operator()(Nuage&);
};

class BarycentrePolaire
{
public:
    Polaire operator()(Nuage&);
};