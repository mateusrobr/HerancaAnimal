#ifndef ANIMALSELVAGEM_H
#define ANIMALSELVAGEM_H

#include "Animal.h"
class AnimalSelvagem : public Animal 
{

    public:
        AnimalSelvagem(/* args */);
        ~AnimalSelvagem();
    private:
        int nivelStress;

};
#endif