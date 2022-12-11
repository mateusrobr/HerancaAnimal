#ifndef ANIMALDOMESTICADO_H
#define ANIMALDOMESTICADO_H

#include "Animal.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;


class AnimalDomesticado : public Animal
{
    friend ostream& operator<<( ostream&, const AnimalDomesticado&);
    public:
        AnimalDomesticado();
        AnimalDomesticado(const AnimalDomesticado&);
        AnimalDomesticado(const string&, int, int, int,int);
        ~AnimalDomesticado();

        int getNivelFelicidade();
        int getNivelFelicidade()const;

        virtual void alimentar() = 0;
        
        virtual void interagir() = 0;
        virtual void funcaoSocial() = 0;

        void printAnimalDomestico();
        void printAnimalDomestico() const;

        void aumentarNivFelicidade();
        void diminuirNivFelicidade();

        void setNivFelicidade(int);

        AnimalDomesticado & operator=(const AnimalDomesticado&);
        bool operator==(const AnimalDomesticado&);
        bool operator!=(const AnimalDomesticado&);
        AnimalDomesticado & operator!();

    private:

        int nivelFelicidade;
        

    };


#endif