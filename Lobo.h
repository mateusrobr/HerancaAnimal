#ifndef LOBO_H
#define LOBO_H

#include "AnimalSelvagem.h"

class Lobo : public AnimalSelvagem
{
    friend ostream& operator<<(ostream&, const Lobo&);
    public:
        Lobo();
        Lobo(const Lobo&);

        ~Lobo();
    private:

};

#endif