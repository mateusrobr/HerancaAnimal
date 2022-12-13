#ifndef PEIXEDOURADO_H
#define PEIXEDOURADO_H

#include "AnimalDomesticado.h"

#include "Lobo.h"
#include "Cachorro.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;

class PeixeDourado : public AnimalDomesticado
{
    
    friend ostream& operator<<(ostream&, const PeixeDourado &);
    public:
        PeixeDourado(/* args */);
        PeixeDourado(const PeixeDourado &);
        PeixeDourado(const string&, int, int, int, int, int, int);
        ~PeixeDourado();

        void nadar();

        virtual void alimentar();
        virtual void interagir(Animal&);
        virtual void funcaoSocial();

        PeixeDourado & operator=(const PeixeDourado &);
        bool operator==(const PeixeDourado &);
        bool operator!=(const PeixeDourado &);
        PeixeDourado & operator!();
    private:
        string habitat;
        int expectativaDeVida;
        int numBarbatana;
};

#endif