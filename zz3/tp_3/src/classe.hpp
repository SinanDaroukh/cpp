#pragma once

class Classe
{

private:
    double _lowerBound;
    double _upperBound;
    unsigned int _quantity;

public:
    Classe(double, double);
    double getBorneInf() const;
    double getBorneSup() const;
    unsigned int getQuantite() const;
    void setBorneInf(double);
    void setBorneSup(double);
    void setQuantite(unsigned int);
    void ajouter();
    bool operator<(const Classe &b) const;
    bool operator>(const Classe &b) const;
};

Classe::Classe(double a, double b)
{
    _lowerBound = a;
    _upperBound = b;
    _quantity = 0u;
}

double Classe::getBorneInf() const
{
    return _lowerBound;
}
double Classe::getBorneSup() const
{
    return _upperBound;
}
unsigned int Classe::getQuantite() const
{
    return _quantity;
}

void Classe::setBorneInf(double a)
{
    _lowerBound = a;
}
void Classe::setBorneSup(double a)
{
    _upperBound = a;
}
void Classe::setQuantite(unsigned int a)
{
    _quantity = a;
}

void Classe::ajouter()
{
    _quantity++;
}

bool Classe::operator<(const Classe &b) const
{
    return this->getBorneInf() < b.getBorneInf();
}

bool Classe::operator>(const Classe &b) const
{
    return this->getBorneInf() > b.getBorneInf();
}