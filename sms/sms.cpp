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

Reseau * Telephone::getReseau() const {
    return _res;
}

void Telephone::setReseau(Reseau * r) {
    _res = r;
}

bool Telephone::operator<(const Telephone & tel) const {
    return (_num < tel.getNumero());
}

/* Classe Réseau */

void Reseau::ajouter(std::string tel){
    Telephone x(tel);
    x.setReseau(this);
    telephones.push_back(x);
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
    try {
    _res->trouveTel(u).messages.push_back(new SMS(_num,u,v));
    }
    catch( MauvaisNumero e){
        std::cout << "Téléphone destinataire non sur le réseau - Error"  << std::endl;
    }
}

std::string Image::afficher(){
    return "[[image]]";
}

std::string Son::afficher(){
    return "[[son]]";
}

std::string Video::afficher(){
    return "[[video]]";
}

MMS::MMS(std::string str, std::string stat, std::string srr) :
    Message(str,stat,srr)
{

}

void MMS::joindre(Media * med){
    media.push_back(med);
}

void MMS::setTexte(std::string str){
    texte = str;
}

std::string MMS::afficher(){
    std::stringstream ss;
    ss << texte;
    for (auto i : media )
        ss << i->afficher(); 
    return ss.str();
}