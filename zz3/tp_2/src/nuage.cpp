#include "nuage.hpp"

#include <iostream>
#include <list>

template <typename T>
void Nuage<T>::ajouter(T point)
{
    _points.push_back(point);
}

template <typename T>
unsigned int Nuage<T>::size() const
{
    return _points.size();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const
{
    return _points.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const
{
    return _points.end();
}

template <typename T>
T barycentre_v1(Nuage<T> &a)
{
    double x_sum, y_sum;
    Cartesien b = Cartesien();

    if (a.size() > 0)
    {
        for (auto it = a.begin(); it < a.end(); it++)
        {
            (*it).convertir(b);
            x_sum += b.getX();
            y_sum += b.getY();
        }
        b.setX(x_sum / a.size());
        b.setY(y_sum / a.size());
    }
    return b;
}

template <typename T, template <typename> class V>
T barycentre_v2(V<T> &a)
{
    double x_sum, y_sum;
    Cartesien b = Cartesien();

    if (a.size() > 0)
    {
        for (auto it = a.begin(); it < a.end(); it++)
        {
            (*it).convertir(b);
            x_sum += b.getX();
            y_sum += b.getY();
        }
        b.setX(x_sum / a.size());
        b.setY(y_sum / a.size());
    }
    return b;
}

template <typename T, template <typename, typename = std::allocator<T>> class V>
T barycentre_v2(V<T> &a)
{
    double x_sum, y_sum;
    Cartesien b = Cartesien();

    if (a.size() > 0)
    {
        for (auto it = a.begin(); it < a.end(); it++)
        {
            (*it).convertir(b);
            x_sum += b.getX();
            y_sum += b.getY();
        }
        b.setX(x_sum / a.size());
        b.setY(y_sum / a.size());
    }
    return b;
}

// template <>
// Polaire barycentre_v1(Nuage<Polaire> &a)
// {
//     double ang_sum = 0, dis_sum = 0;
//     Polaire b;
//     if (a.size() > 0)
//     {
//         for (auto it = a.begin(); it < a.end(); it++)
//         {
//             ang_sum += it->getAngle();
//             dis_sum += it->getDistance();
//         }
//         b.setAngle(ang_sum / a.size());
//         b.setDistance(dis_sum / a.size());
//     }
//     return b;
// }

template class Nuage<Cartesien>;
template class Nuage<Polaire>;

template Cartesien barycentre_v1(Nuage<Cartesien> &);
template Polaire barycentre_v1(Nuage<Polaire> &);

template Cartesien barycentre_v2<Cartesien, Nuage>(Nuage<Cartesien>&);
template Cartesien barycentre_v2<Cartesien, std::vector>(std::vector<Cartesien, std::allocator<Cartesien> >&);
template Polaire barycentre_v2<Polaire, std::vector>(std::vector<Polaire, std::allocator<Polaire> >&);