#ifndef marvel__hpp
#define marvel__hpp

#include <string>
#include <sstream>
#include <exception>
#include <vector>

class AnonymeException : public std::exception
{
public:
	AnonymeException() : std::exception() {}
	~AnonymeException() {}
	const char * what() const noexcept {return "identite anonyme";}
};

class Personne
{
public:
	enum Genre {HOMME, FEMME, INDETERMINE};
	static Personne INCONNU;

	Personne(std::string, std::string, Genre genre = HOMME);
	void afficher(std::stringstream&);

private:
	std::string _prenom;
	std::string _nom;
	Genre _genre;

public: 
	std::string getPrenom() const {return _prenom;};
	std::string getNom() const {return _nom;};
	Genre getGenre() const {return _genre;};
};

bool operator==(Personne, Personne);
std::stringstream& operator<<(std::stringstream&, Personne&);

class Capacite
{
public:
	enum TYPE {MATERIEL, PHYSIQUE, PSYCHIQUE};
	Capacite(std::string, int);
	virtual ~Capacite(){};
	virtual void utiliser(std::stringstream&);
	virtual Capacite* clone() const = 0;

protected:
	std::string _nom;
	int _niveau;
public:
	int getNiveau() {return _niveau;};
	std::string getNom() {return _nom;};
};

class Materiel: public Capacite
{
public:
	Materiel(std::string, int);
	virtual ~Materiel(){};
	virtual void utiliser(std::stringstream&);
	void actionner(std::stringstream& ss){utiliser(ss);};
	virtual Materiel* clone() const;
};

class Physique: public Capacite
{
public:
	Physique(std::string, int);
	virtual ~Physique(){};
	void exercer(std::stringstream& ss){utiliser(ss);};
	virtual Physique* clone() const;
};

class Psychique: public Capacite
{
public:
	Psychique(std::string, int);
	virtual ~Psychique(){};
	void penser(std::stringstream& ss){utiliser(ss);};
	virtual Psychique* clone() const;
};


class Super
{
public:
	Super(std::string, Personne, bool anonyme = true);
	Super(Super const &);
	~Super();
	void setIdentite(Personne);
	void ajouter(Capacite*);
	void setNom(std::string);
private:
	std::string _nickname;
	Personne _identity;
	bool _anonyme;
	std::vector<Capacite*> _capa;
public:
	std::string getNom() const {return _nickname;};
	int getNiveau() const;
	bool estAnonyme() const {return _anonyme;};
	void enregistrer() { _anonyme = false;};
	Personne getIdentite() const {if (estAnonyme()) throw AnonymeException{}; return _identity;};

};

class Equipe:public std::vector<Super*>
{
public:
	Equipe(std::string);
	~Equipe();
private:
	std::string _nom;
	int _nombre;
public:
	int getNombre() const {return _nombre;};
	void ajouter(Super*s) {push_back(s); _nombre++;};
	int getNiveau() const;
};

#endif
