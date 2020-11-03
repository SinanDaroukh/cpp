#pragma once

template <int N>
class Factorielle
{
    public:
    static const unsigned long valeur = N * Factorielle<N - 1>::valeur;
};

template <>
class Factorielle<0>
{
    public:
    static const unsigned long valeur = 1;
};
