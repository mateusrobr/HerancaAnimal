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
        Animal(/* args */);
        Animal(const Animal&);
        Animal(const string&, int, int, int = 4);
        
        string getEspecie();
        int getIdade();
        int getNumPatas();
        int getSaciedade() const;

        void printAnimal();
        void printAnimal() const;

        void alimentar(int = 1);

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
        
};


#endif