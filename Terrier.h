#ifndef TERRIER_H
#define TERRIER_H

#include "Cachorro.h"

class Terrier : public Cachorro
{
    friend ostream& operator<<(ostream&, const Terrier&);
    public:
        Terrier();
        Terrier(const Terrier&);

        virtual void funcaoSocial();

        void cacar();

        ~Terrier();
    private:

        string RACA;


};

#endif