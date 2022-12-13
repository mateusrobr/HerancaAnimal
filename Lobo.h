#ifndef LOBO_H
#define LOBO_H

#include "AnimalSelvagem.h"
#include "Presa.h"

#include <vector>
using std::vector;

class Lobo : public AnimalSelvagem
{
    friend ostream& operator<<(ostream&, const Lobo&);
    public:
        Lobo();
        Lobo(const Lobo&);
        Lobo(const string& , int , int , int , int , int, int, int);

        virtual void alimentar();
        void cacar();
        void printToca();
        void levarParaToca(const Presa&);

        void uivar();

        bool operator==(const Lobo&);
        bool operator!=(const Lobo&);
        Lobo& operator=(const Lobo&);
        Lobo& operator!();

        ~Lobo();
    private:

        vector<Animal *> toca;
        vector<Animal *>::iterator tocaItr;

};

#endif