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
        Cachorro(const string&, int, int, int, int, int);
        Cachorro(const Cachorro&);
        ~Cachorro();

        void latir();

        void printCachorro();
    private:
        int expectativaDeVida;


    };


#endif