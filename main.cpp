#include <iostream>

#include "Animal.h"
#include "Animal.cpp"

#include "AnimalDomesticado.h"
#include "AnimalDomesticado.cpp"

#include "Cachorro.h"
#include "Cachorro.cpp"

int main(){
    AnimalDomesticado animal("Teste", 1, 30, 4, 20);
    AnimalDomesticado animalCopia;
    cout << animal;
    !animal;
    cout << animal;
    
    //cout << animalCopia;
    //animalCopia = animal;
}