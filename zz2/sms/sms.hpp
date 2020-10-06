#ifndef __SMS
#define __SMS

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <exception>
#include <stdexcept>

class Message {
    static int cle;

    protected:
        const int id;
        std::string expediteur;
        std::string destinataire;
        std::string date;

    public:
        Message(std::string e, std::string d, std::string dd);
        virtual ~Message(){};
        virtual std::string afficher() = 0;
        static int getCle();
        int getId();
};

class SMS : public Message {
    private:
        std::string texte;
        
    public:
        SMS(std::string e, std::string d, std::string dd);
        ~SMS(){};
        void setTexte(std::string t);
        std::string getTexte();
        std::string afficher();
};

class Reseau;
class Telephone {

    private:
        std::string _num = "";
        Reseau * _res = nullptr;
        std::vector<Message *> messages;

    public:
        Telephone(){};
        Telephone(std::string numero);
        ~Telephone(){};
        std::string getNumero() const;
        void setNumero(std::string numero);
        Reseau * getReseau() const;
        void setReseau(Reseau * r);
        int getNbMessages() const;
        void textoter(std::string u, std::string v);
        bool operator<(const Telephone & tel) const;

};

struct CompareTel {
    bool operator()( const Telephone & lhs, const Telephone & rhs ) const;
};

class Reseau {
    private:
        std::list<Telephone> telephones;

    public:
        Reseau(){};
        ~Reseau(){};
        void ajouter(std::string tel);
        Telephone& trouveTel(std::string tel);
        std::string lister();
};

class MauvaisNumero : public std::invalid_argument {
    public:
        MauvaisNumero() : invalid_argument("mauvais numero") {};     
};

class Media {
    public:
        virtual ~Media(){};
        virtual std::string afficher() = 0;

};

class Image : public Media {
    public:
        ~Image(){};
        std::string afficher();
};

class Son : public Media {
        ~Son(){};
        std::string afficher();

};
class Video : public Media {
        ~Video(){};
        std::string afficher();

};

class MMS : public Message {
    private:
        std::list<Media *> media;
        std::string texte;

    public:
        MMS(std::string str, std::string stat, std::string srr);
        void joindre(Media * med);
        void setTexte(std::string str);
        std::string afficher();

};

#endif