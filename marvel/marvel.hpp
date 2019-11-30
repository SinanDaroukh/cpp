#ifndef marvel__hpp
#define marvel__hpp

#include <sstream>
#include <string>
#include <vector>

extern std::string tab [3];

class Capacite {
    protected:
        std::string _string;
        int _number;

    public:
        Capacite(std::string nom, int number);
        virtual ~Capacite(){};
        virtual void utiliser(std::ostream & log) = 0;
        virtual Capacite * clone() const = 0;
        std::string getString();
        int getNumber();
        std::string getNom();
        
};

class Personne {

    public:
    enum Genre {
        HOMME,FEMME,INDETERMINE
    };
    static Personne INCONNU;

    private:
        std::string _prenom;
        std::string _nom;
        Genre _genre;
        
    public:
        Personne(std::string prenom, std::string nom);
        Personne(std::string prenom, std::string nom, Genre genre);
        std::string getPrenom() const;
        std::string getNom() const;
        Genre getGenre() const;
        void afficher(std::ostream & ss) const;
        bool operator ==(const Personne &b) const;

};

class Super {

    private:
        std::string _nheros;
        bool _anon = true;
        Personne _personne;
        std::vector<Capacite *> capacites; 

    public:
        Super(std::string prenom_heros, Personne p);
        std::string getNom() const;
        bool estAnonyme() const;
        void enregistrer();
        Personne getIdentite() const;
        void setIdentite(Personne p);
        void ajouter(Capacite * cap);
        int getNiveau();
        void setNom(std::string nom);

};

class AnonymeException : public std::exception {
    public:
        AnonymeException(){}
        //~AnonymeException();
        // exception& operator=( const exception& other ) noexcept;
        virtual const char* what() const noexcept;
};

class Materiel : public Capacite {
    public:
        Materiel(std::string armor, int number);
        ~Materiel(){};
        void utiliser(std::ostream & log);
        void actionner(std::ostream & log);
        Materiel * clone() const;

};

class Physique : public Capacite {
    public:
        Physique(std::string force, int number);
        ~Physique(){};
        void exercer(std::ostream & log);
        void utiliser(std::ostream & log);
        Physique * clone() const;
};

class Psychique : public Capacite {
    public:
        Psychique(std::string _telepathie, int number);
        ~Psychique(){};
        void penser(std::ostream & log);
        void utiliser(std::ostream & log);
        Psychique * clone() const;
};

class Equipe {
    private:
        std::string _nomEquipe;
        std::vector<Super *> membres;

    public:
        Equipe(std::string nomEquipe);
        int getNombre();
        void ajouter(Super * super);
        int getNiveau();

};

std::ostream & operator <<(std::ostream & os, Personne p);

#endif
