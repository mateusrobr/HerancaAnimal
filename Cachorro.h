#ifndef CACHORRO_H
#define CACHORRO_H

#include "AnimalDomesticado.h"

#include "Lobo.h"
#include "Presa.h"
#include "PeixeDourado.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;

#include <random>
using std::rand;

#include <time.h>

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
        void farejar();

        virtual void interagir( Animal&);
        virtual void funcaoSocial();

        void ficarDeGuarda();

        void printCachorro();

        virtual void alimentar();

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