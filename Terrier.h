#ifndef TERRIER_H
#define TERRIER_H

#include "Cachorro.h"

class Terrier : public Cachorro
{
    friend ostream& operator<<(ostream&, const Terrier&);
    public:
        Terrier();
        Terrier(const string&, int, int, int, int, int, int, const string&);
        Terrier(const Terrier&);

        virtual void funcaoSocial();

        void cacar();

        bool operator==(const Terrier&);
        bool operator!=(const Terrier&);
        Terrier& operator=(const Terrier&);

        ~Terrier();
    private:

        string RACA;


};

#endif