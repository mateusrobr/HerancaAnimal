#ifndef ANIMALSELVAGEM_H
#define ANIMALSELVAGEM_H

#include "Animal.h"

class AnimalSelvagem : public Animal 
{
    friend ostream& operator<<(ostream&, const AnimalSelvagem&);
    public:
        AnimalSelvagem(/* args */);
        AnimalSelvagem(const AnimalSelvagem &);
        AnimalSelvagem(const string& , int , int , int , int , int, int, int);
        ~AnimalSelvagem();

        //virtual void alimentar(int = 1) = 0;
        
        
        //virtual void fugirDePredadores() = 0;
        //virtual void cacar() = 0;
        //virtual void entrarEmCombate(/*Lobo &*/) = 0;

        void printAnimalSelvagem();
        void printAnimalSelvagem() const;
        void aumentoVelocidade();
        void aumentoNivAtaque();

        void setVida(int);
        int getVida();
        int getVida()const;
        int getVelocidade();
        int getVelocidade()const; 
        int getNivAtaque();
        int getNivAtaque() const;
        int getNivelStress();
        int getNivelStress() const;

        void setNivelStress(int);
        void setVelocidade(int);
        void setNivAtaque(int);

        bool isAlive();

        AnimalSelvagem& operator=(const AnimalSelvagem&);
        bool operator==(const AnimalSelvagem&);
        bool operator!=(const AnimalSelvagem&);
        AnimalSelvagem& operator!();
    private:
        int nivelStress;
        int vida;
        int velocidade;
        int nivAtaque;


};
#endif