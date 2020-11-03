#pragma once

#include <factorielle.hpp>
#include <puissance.hpp>

template <int N>
class Cosinus{
    public:
    static double valeur(double x) {
        return Cosinus<N-1>::valeur(x) + Puissance<N>::valeur(-1) * Puissance<2*N>::valeur(x) / Factorielle<2*N>::valeur;
    };
};

template <>
class Cosinus<0>{
    public:
    static double valeur(double){
        return 1.0;
    }
};

template <int N>
class Sinus{
    public:
    static double valeur(double x) {
        return Sinus<N-1>::valeur(x) + Puissance<N>::valeur(-1) * Puissance<2*N+1>::valeur(x) / Factorielle<2*N+1>::valeur;
    }
};

template <>
class Sinus<0>{
    public:
    static double valeur(double x){
        return x;
    }
};