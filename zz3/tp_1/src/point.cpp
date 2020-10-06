#include "point.hpp"

Point::Point()
{
}

Point::~Point()
{
}


void operator<<(std::stringstream &a, const Point &b) 
{
    b.afficher(a);
}