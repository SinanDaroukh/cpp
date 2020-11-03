#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class Echantillon
{
private:
    std::vector<Valeur> _values;

public:
    Echantillon();
    Echantillon(double);
    unsigned int getTaille() const;
    void ajouter(double);
    Valeur getMinimum() const;
    Valeur getMaximum() const;
    Valeur getValeur(unsigned int);
};

Echantillon::Echantillon() {}

Echantillon::Echantillon(double x){
    this->ajouter(x);
}

unsigned int Echantillon::getTaille() const
{
    return _values.size();
}

void Echantillon::ajouter(double v)
{
    Valeur a = Valeur(v);
    _values.push_back(a);
}

Valeur Echantillon::getMinimum() const
{
    if ( this->getTaille() == 0u ) { throw std::domain_error("Empty Echantillon"); }
    return *std::min_element(_values.begin(), _values.end());
}

Valeur Echantillon::getMaximum() const 
{
    if ( this->getTaille() == 0u ) { throw std::domain_error("Empty Echantillon"); }
    return *std::max_element(_values.begin(), _values.end());

    // Valeur max = _values[0];
    // for (auto &i : _values)
    // {
    //     max = std::max(max.getNombre(), i.getNombre());
    // }
    // return max;
}

Valeur Echantillon::getValeur(unsigned int i){
    if (i >= this->getTaille()) { throw std::out_of_range("Index out of range"); }
    return _values[i];
}