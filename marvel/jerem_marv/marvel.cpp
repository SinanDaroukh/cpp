#include "marvel.hpp"

Personne Personne::INCONNU = Personne("Inconnu", "Inconnu", INDETERMINE);

Personne::Personne(std::string prenom, std::string nom, Genre genre):
	_prenom(prenom), _nom(nom), _genre(genre)
{
}

void Personne::afficher(std::stringstream& oss)
{
	oss << _prenom << ' ' << _nom;
	if (_genre == HOMME)
		oss << " [HOMME]";
	else if (_genre == FEMME)
		oss << " [FEMME]";
	else
		oss << " [INDETERMINE]";
}

bool operator==(Personne a, Personne b)
{
	return a.getNom() == b.getNom() && a.getPrenom() == b.getPrenom() && a.getGenre() == b.getGenre();
}

std::stringstream& operator<<(std::stringstream& os, Personne& P)
{
	P.afficher(os);
	return os;
}

Super::Super(std::string nickname, Personne identity, bool anonyme):
	_nickname(nickname), _identity(identity), _anonyme(anonyme)
{}

void Super::setIdentite(Personne p)
{
	_identity = p;
	_anonyme = true;
}

Capacite::Capacite(std::string nom, int niveau):
	_nom(nom), _niveau(niveau)
{

}

Materiel::Materiel(std::string nom, int niveau):Capacite(nom, niveau){}
Physique::Physique(std::string nom, int niveau):Capacite(nom, niveau){}
Psychique::Psychique(std::string nom, int niveau):Capacite(nom, niveau){}

void Capacite::utiliser(std::stringstream& ss)
{
	ss << _nom << " [" << _niveau << ']';
}

void Materiel::utiliser(std::stringstream& ss)
{
	Capacite::utiliser(ss);
	ss << " en action";
}

Materiel* Materiel::clone() const
{
	return new Materiel(_nom, _niveau);
}

Psychique* Psychique::clone() const
{
	return new Psychique(_nom, _niveau);
}

Physique* Physique::clone() const
{
	return new Physique(_nom, _niveau);
}


void Super::setNom(std::string nom)
{
	_nickname = nom;
}

void Super::ajouter(Capacite* capa)
{
	_capa.push_back(capa);
}

int Super::getNiveau() const
{
	int s = 0;
	for (auto&& c : _capa)
		s += c->getNiveau();
	return s;
}

Equipe::Equipe(std::string nom):_nom(nom),_nombre(0)
{
	
}

int Equipe::getNiveau() const
{
	int s = 0;
	for (auto&& i : *this)
		s += i->getNiveau();
	return s;
}

Super::~Super()
{
	for (auto &&i : _capa)
		delete i;
	
}

Super::Super(Super const & s):
	_nickname(s._nickname), _identity(s._identity)
{
	for (auto &&i : s._capa)
		ajouter(i->clone());
}

Equipe::~Equipe()
{
	for (auto &&i : *this)
	{
		delete i;
	}
	
}