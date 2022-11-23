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

int main(){
    AnimalSelvagem animal("Teste", 1, 30, 4, 20);
    
    animal.fugirDePredadores();
    animal.fugirDePredadores();
    animal.fugirDePredadores();
    animal.alimentar(5);
    cout << animal;
    
    
    //cout << animalCopia;
    //animalCopia = animal;
}