#include <iostream>

/*
int main(int, char **){
    int  a = 3;
    int  b = a;
    int& c = a;

    std::cout << a << " " << b << " " << c << std::endl;
    b = 4;
    std::cout << a << " " << b << " " << c << std::endl;
    c = 5;
    std::cout << a << " " << b << " " << c << std::endl;
    a = 6;
    std::cout << a << " " << b << " " << c << std::endl;
}
*/


void swap_ref(int x ,int y){
    int& z = x;
    int temp = z;
    z = y;
    y = temp;
}

void swap_ptr(int x, int y){
    int * p = &x;
    int temp = *p;
    x = y;
    
}

int main(int, char **){

}