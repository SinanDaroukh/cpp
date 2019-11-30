#include "marvel.hpp"

/*
Classe Personne
*/

std::string tab [3] = {"HOMME","FEMME","INDETERMINE"};

Personne Personne::INCONNU("Inconnu", "Inconnu", Personne::INDETERMINE);

Personne::Personne(std::string prenom, std::string nom) : 
    _prenom(prenom),
    _nom(nom),
    _genre(Personne::INDETERMINE)
{
    
}
Personne::Personne(std::string prenom, std::string nom, Genre genre) : 
    _prenom(prenom),
    _nom(nom),
    _genre(genre)
{

}

std::string Personne::getPrenom() const{
    return _prenom;
}

std::string Personne::getNom() const{
    return _nom;
}

Personne::Genre Personne::getGenre() const{
    return _genre;
}

void Personne::afficher(std::ostream & ss) const{
    ss << getPrenom() << " " << getNom() << " [" << tab[getGenre()] << "]";
}

bool Personne::operator ==(const Personne &b) const{
    return ( _prenom == b._prenom && _nom == b._nom && _genre == b._genre );
}

std::ostream & operator <<(std::ostream & os, Personne p){
        p.afficher(os);
        return os;
}

/*
Classe Super
*/

Super::Super(std::string prenom_heros, Personne p) :
    _nheros(prenom_heros),
    _personne(p)
{

}

std::string Super::getNom() const{
    return _nheros;
}

bool Super::estAnonyme() const{
    return _anon;
}

void Super::enregistrer() {
    _anon = false;
}

Personne Super::getIdentite() const {

    if ( estAnonyme()){
        throw AnonymeException();
    }
    else {
        return _personne;
    }
}

void Super::setIdentite(Personne p){
    _personne = p;
    _anon = true;
}

void Super::ajouter(Capacite * cap){
    capacites.push_back(cap);
}

int Super::getNiveau(){
    int max = 0;
    for(Capacite * n : capacites) {
        max += n->getNumber();
    }
    return max;
}

void Super::setNom(std::string nom){
    _nheros = nom;
}

/* Classe AnonymeException */

const char * AnonymeException::what() const noexcept {
    return "identite anonyme";
}

/* Classe Materiel */

Materiel::Materiel(std::string armor, int number) :
    Capacite(armor,number)
{
    
}

void Materiel::actionner(std::ostream & log){
    log << getString() << " [" << getNumber() << "] en action";
}

void Materiel::utiliser(std::ostream & log){
    actionner(log);
}

Materiel * Materiel::clone() const {
    return new Materiel(_string, _number);
}

/* Classe Physique */

Physique::Physique(std::string armor, int number) :
    Capacite(armor,number)
{
    
}

void Physique::exercer(std::ostream & log){
    log << getString() << " [" << getNumber() << "]";
}

void Physique::utiliser(std::ostream & log){
    exercer(log);
}

Physique * Physique::clone() const {
    return new Physique(_string, _number);
}

/* Classe Psychique */

Psychique::Psychique(std::string armor, int number) :
 Capacite(armor,number)
{
    
}

void Psychique::penser(std::ostream & log){
    log << getString() << " [" << getNumber() << "]";
}

void Psychique::utiliser(std::ostream & log){
    penser(log);
}

Psychique * Psychique::clone() const {
    return new Psychique(_string, _number);
}

/* Classe Capacite */

Capacite::Capacite(std::string nom, int number) : 
    _string(nom), _number(number)
 {

 }

std::string Capacite::getNom(){
    return getString();
}

std::string Capacite::getString() {
    return _string;
}

int Capacite::getNumber(){
    return _number;
}

/* Classe Equipe */

Equipe::Equipe(std::string nomEquipe) : _nomEquipe(nomEquipe)
{

}

int Equipe::getNombre(){
    return membres.size();
}

void Equipe::ajouter(Super * super){
    membres.push_back(super);
}

int Equipe::getNiveau() {
    int max = 0;
    for (auto i : membres)
        max += i->getNiveau();
    return max;
}
