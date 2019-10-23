#include "Cercle.hpp"
#include "Rectangle.hpp"

int main(int, char **){

    Cercle * c = new Cercle(1,2,3,4);
    c->afficher();

    Rectangle * r = new Rectangle(5,7,8,9);
    r->afficher();

}