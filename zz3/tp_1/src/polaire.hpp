#pragma

#include "point.hpp"

class Polaire : public Point
{
private:
    double _th;
    double _r;

public:
    Polaire();
    Polaire(double x, double y);
    Polaire(Cartesien);
    ~Polaire();
    double getAngle() const;
    double getDistance() const;
    void setAngle(double a);
    void setDistance(double d);
    void convertir(Cartesien &a) const override;
    void convertir(Polaire &a) const override;
    void afficher(std::stringstream &) const override;
};
