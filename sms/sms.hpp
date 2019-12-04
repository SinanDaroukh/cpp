#ifndef __SMS
#define __SMS

#include <iostream>
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

class Telephone {

    private:
        std::string _num = "";
        unsigned int _res = 0;
        std::vector<Message *> messages;

    public:
        Telephone(){};
        Telephone(std::string numero);
        ~Telephone(){};
        std::string getNumero() const;
        void setNumero(std::string numero);
        unsigned int getReseau() const;
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

#endif