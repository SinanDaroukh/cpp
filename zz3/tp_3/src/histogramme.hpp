#pragma once

//#include <vector>
#include <set>
#include <map>
#include "classe.hpp"
#include <iostream>
#include "echantillon.hpp"

template <typename Comp = std::less<Classe>>
class Histogramme
{
private:
    double _lowerBound;
    double _upperBound;
    double _size;
    //std::vector<Classe> _classes;
    std::set<Classe, Comp> _classes;
    std::multimap<Classe, Valeur, Comp> _values;

public:
    using classes_t = std::set<Classe, Comp>;
    using valeurs_t = std::multimap<Classe, Valeur, Comp>;
    using it_valeurs_t = typename valeurs_t::iterator;

    Histogramme(double, double, double);
    template <typename C>
    Histogramme(Histogramme<C> &);
    classes_t &getClasses();
    valeurs_t &getValeurs();
    std::pair<it_valeurs_t, it_valeurs_t> &getValeurs(Classe);
    void ajouter(Echantillon);
};

template <typename Comp>
Histogramme<Comp>::Histogramme(double lowerBound, double upperBound, double size)
    : _lowerBound(lowerBound), _upperBound(upperBound), _size(size)
{
    double step = (_upperBound - _lowerBound) / _size;
    for (double i = _lowerBound; i <= _upperBound - step; i += step)
    {
        //_classes.push_back(Classe(i, i + step));
        _classes.insert(Classe(i, i + step));
    }
}

template <typename Comp>
template <typename C>
Histogramme<Comp>::Histogramme(Histogramme<C> &histo)
{
    for (auto &it : histo.getClasses())
        _classes.insert(it);

    for (auto &it : histo.getValeurs())
        _values.insert(it);
}

template <typename Comp>
typename Histogramme<Comp>::classes_t &Histogramme<Comp>::getClasses()
{
    return _classes;
}

template <typename Comp>
typename Histogramme<Comp>::valeurs_t &Histogramme<Comp>::getValeurs()
{
    return _values;
}

template <typename Comp>
std::pair<typename Histogramme<Comp>::it_valeurs_t, typename Histogramme<Comp>::it_valeurs_t> &Histogramme<Comp>::getValeurs(Classe a)
{
        return _values.find(a);
}

template <typename Comp>
void Histogramme<Comp>::ajouter(Echantillon e)
{
    for (auto &it : _classes)
    {
        for (unsigned int j = 0; j < e.getTaille(); j++)
            if (e.getValeur(j).getNombre() < it.getBorneSup() && e.getValeur(j).getNombre() >= it.getBorneInf())
            {
                Classe michel = it;
                michel.ajouter();
                _classes.erase(it);
                _classes.insert(michel);

                _values.insert(std::pair<Classe, Valeur>(michel, e.getValeur(j)));

                //it.ajouter();
            }
    }
}
