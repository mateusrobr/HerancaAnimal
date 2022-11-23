#ifndef ANIMALSELVAGEM_H
#define ANIMALSELVAGEM_H

#include "Animal.h"
class AnimalSelvagem : public Animal 
{
    friend ostream& operator<<(ostream&, const AnimalSelvagem&);
    public:
        AnimalSelvagem(/* args */);
        AnimalSelvagem(const AnimalSelvagem &);
        AnimalSelvagem(const string& , int , int , int , int );
        ~AnimalSelvagem();

        void fugirDePredadores();

        AnimalSelvagem& operator=(const AnimalSelvagem&);
        bool operator==(const AnimalSelvagem&);
        bool operator!=(const AnimalSelvagem&);
        AnimalSelvagem& operator!();
    private:
        int nivelStress;

};
#endif