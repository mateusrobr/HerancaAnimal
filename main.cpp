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

#include <vector>
using std::vector;

int main(){
    /*vector<Animal*> vetorAnimais (1);

    vetorAnimais[0] = new Terrier;
    //vetorAnimais[1] = new Terrier;

    Terrier *cachorro = dynamic_cast<Terrier*>(vetorAnimais[0]);

    cout << *cachorro;
    cachorro->funcaoSocial();
    cout << *cachorro;


    for(int i = 0 ;  i < vetorAnimais.size() ; i++){
        delete vetorAnimais[i];
    }
    delete cachorro;*/

    Terrier collie1;
    Terrier collie2("Caninus", 3, 30, 4, 10, 18, 2, "teste");

    cout << "Collie1\n";
    cout<< collie1;
    cout << "Collie2\n";
    cout << collie2;

    cout << "operator==\n";
    cout << (collie1 == collie2) << " ";
    cout << (collie1 != collie2) << "\n";
    cout << "teste operator=\n";
    collie1 = collie2;
    cout << collie1;
    cout << (collie1 == collie2) << " ";
    cout << (collie1 != collie2) << "\n";

    !collie1;
    cout << collie1;

    
    
    
    //cout << animalCopia;
    //animalCopia = animal;
}