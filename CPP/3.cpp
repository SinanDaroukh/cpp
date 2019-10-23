#include <iostream>

void fonction1(int a) {
  std::cout << &a << std::endl;
}

void fonction2(int& a) {
  std::cout << &a << std::endl;
}

int main(int, char **) {
  int age = 41;

  std::cout << &age << std::endl;
  fonction1(age);
  fonction2(age);

  return 0;
}