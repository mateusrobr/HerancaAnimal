#ifndef CACHORRO_H
#define CACHORRO_H

#include "AnimalDomesticado.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;

class Cachorro : public AnimalDomesticado
{
    friend ostream& operator<<(ostream&, const Cachorro&);
    public:
        
        
        Cachorro();
        Cachorro(const string&, int, int, int, int, int, int);
        Cachorro(const Cachorro&);
        ~Cachorro();

        void latir();
        void correr();

        void printCachorro();

        Cachorro & operator=(const Cachorro &);
        bool operator==(const Cachorro&);
        bool operator!=(const Cachorro&);
        Cachorro & operator!();
    private:
        int expectativaDeVida;
        string habitat;
        int quantidadeOrelhas;


    };


#endif