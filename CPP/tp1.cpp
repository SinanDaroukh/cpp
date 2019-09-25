#include <iostream>

/*

int main(int , char ** ){
    for(int i=0; i< 120; ++i){
        std::cout << "Bonjour les ZZ" << 2 << std::endl;
    }

    return 0;
}

*/

int main(int, char **) {

using namespace std;

  string prenom; // type spécial pour les chaînes de caractères
  int age;

  cout << "Quel est votre prénom ?" << endl;
  cin >> prenom;
  cout << "Quel est votre age ?" << endl;
  cin >> age ;
  cout << "Bonjour "<< prenom << endl;

  return 0;
}

