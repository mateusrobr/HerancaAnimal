#ifndef PRESA_H
#define PRESA_H

#include "AnimalSelvagem.h"

class Presa : public AnimalSelvagem
{
    friend ostream& operator<<(ostream&, const Presa&);
    public:
        Presa();
        Presa(const string& , int , int , int , int , int, int, int, const string&);
        Presa(const Presa&);
        ~Presa();

        bool operator==(const Presa&);
        bool operator!=(const Presa&);
        Presa& operator=(const Presa&);
        Presa& operator!();

        virtual void alimentar();
    private:
        string mecanismoDeDefesa;

};
#endif