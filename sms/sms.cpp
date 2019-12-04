#include "sms.hpp"

int Message::cle = 0;

/* Classe Telephone */

Telephone::Telephone(std::string numero) :
    _num(numero)
{ 
}

std::string Telephone::getNumero() const{
    return _num;
}

void Telephone::setNumero(std::string numero){
    _num = numero;
}

unsigned int Telephone::getReseau() const {
    return _res;
}

bool Telephone::operator<(const Telephone & tel) const {
    return (_num < tel.getNumero());
}

/* Classe Réseau */

void Reseau::ajouter(std::string tel){
    telephones.push_back(Telephone(tel));
    telephones.sort();
}

std::string Reseau::lister(){
    std::string z = "";
    for (auto i : telephones)
        z = z + i.getNumero() + "\n";
    return z;
}

bool CompareTel::operator()(const Telephone & lhs, const Telephone & rhs) const {
    return ( lhs.getNumero() < rhs.getNumero());
}

Telephone& Reseau::trouveTel(std::string tel) {
    
    for (auto it = telephones.begin(); it != telephones.end(); it++ ){
        if ( tel == (*it).getNumero() ){
           return *it;
        }
    }
    throw MauvaisNumero();
}

Message::Message(std::string e, std::string d, std::string dd) :
    id(Message::cle), expediteur(e), destinataire(d), date(dd)
{

    Message::cle += 1;
}

SMS::SMS(std::string e, std::string d, std::string dd) : 
    Message(e, d, dd)
{

}

void SMS::setTexte(std::string t){
    texte = t;
}

std::string SMS::getTexte(){
    return texte;
}

std::string SMS::afficher(){
    return texte;
}

int Message::getCle(){
    return cle;
}

int Message::getId(){
    return id;
}

int Telephone::getNbMessages() const {
    return messages.size();
}

void Telephone:: textoter(std::string u, std::string v){
    messages.push_back(new SMS(_num,u,v));
}
