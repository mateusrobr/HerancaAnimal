#include <iostream>

#include "Animal.h"
#include "Animal.cpp"

#include "AnimalDomesticado.h"
#include "AnimalDomesticado.cpp"

#include "AnimalSelvagem.h"
#include "AnimalSelvagem.cpp"

#include "Cachorro.h"
#include "Cachorro.cpp"

#include "PeixeDourado.h"
#include "PeixeDourado.cpp"

#include "Bordercollie.h"
#include "Bordercollie.cpp"

#include "Terrier.h"
#include "Terrier.cpp"

#include "Lobo.h"
#include "Lobo.cpp"

#include "Presa.h"
#include "Presa.cpp"

#include <vector>
using std::vector;

int main(){
    srand(time(0));
    
    Lobo lobo("Lobo", 1, 20, 4, 20, 20, 100, 40);
    Lobo lobo2;

    lobo.cacar();
    lobo.cacar();
    lobo.cacar();
    lobo.cacar();
    lobo.printToca();
    cout << "Outra toca\n";
    lobo2.printToca();

    lobo2 = lobo;

    lobo.printToca();
    cout << "outra toca\n";
    lobo2.printToca();



    
    //cout << animalCopia;
    //animalCopia = animal;
}