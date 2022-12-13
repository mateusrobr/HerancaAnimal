#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::ostream;
class Animal
{
    friend ostream& operator<<(ostream &, const Animal & );
    public:
        Animal();
        Animal(const Animal&);
        Animal(const string&, int, int, int = 4);
        
        string getEspecie();
        int getIdade();
        int getNumPatas();
        int getSaciedade() const;
        string getEspecie()const;
        int getIdade() const;
        int getNumPatas() const;
        void setEspecie(const string&);
        void setIdade(int);

        void printAnimal();
        void printAnimal() const;

        virtual void alimentar() = 0;

        void diminuirSaciedade();

        void setNumPatas(int = 0);

        void setSaciedade(int);

//      Operadores

        Animal & operator=(const Animal&);
        bool operator==(const Animal&);
        bool operator!=(const Animal&);
        Animal & operator!();
        
        ~Animal();
    private:

        string especie;
        
        int idade;

        int numPatas;

        int saciedade;

        bool isAlive;
        
};


#endif