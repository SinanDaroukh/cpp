#pragma once

class Valeur
{
private:
    double _value;
    std::string _name;

public:
    Valeur();
    Valeur(const double &);
    Valeur(const double, std::string);
    double getNombre() const;
    double getNote() const;
    std::string getEtudiant() const;
    void setNombre(const double &);
    void setNote(const double &);
    void setEtudiant(const std::string &);
    bool operator<(const Valeur &) const;
};

Valeur::Valeur() : _value(0.0), _name("inconnu") {}

Valeur::Valeur(const double &v) : _value(v) {}

Valeur::Valeur(const double a, std::string n) : _value(a), _name(n) {}

double Valeur::getNombre() const
{
    return _value;
}

double Valeur::getNote() const{
    return _value;
}

std::string Valeur::getEtudiant() const
{
    return _name;
}

void Valeur::setNombre(const double &v)
{
    _value = v;
}

void Valeur::setNote(const double &n){
    _value = n;
}

void Valeur::setEtudiant(const std::string &s){
    _name = s;
}

bool Valeur::operator<(const Valeur &b) const
{
    return _value < b._value;
}
