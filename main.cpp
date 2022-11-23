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
    Animal* animal;
    Animal* animalComparacao;
    AnimalDomesticado* animalDomesticado;
    AnimalDomesticado* animalDomesticadoOperator;
    AnimalSelvagem* animalSelvagem;
    AnimalSelvagem* animalSelvagemOperator;
    Cachorro* cachorro;
    PeixeDourado* peixeDourado;
    PeixeDourado* peixeDouradoCopia;

    cout << "Instanciando animal\n;";
    animal = new Animal("Macaco Narigudo", 1, 40, 4);
    cout << *animal;
    cout << "\n";
    cout << "Comparando animais\n";
    animalComparacao = new Animal;
    cout << "true ou false: " << (*animal == *animalComparacao) <<"\n";
    cout << "\n";
    
    cout << "Instanciando Animal Domesticado\n";
    animalDomesticado = new AnimalDomesticado("Cavalo", 10, 50, 4, 20);
    cout << *animalDomesticado;
    cout << "\n";
    cout << "operator= em animalDomesticado: \n";
    animalDomesticadoOperator = new AnimalDomesticado;
    *animalDomesticado = *animalDomesticadoOperator;
    cout << "Depois de usar o operador:\n";
    cout << *animalDomesticado;
    cout << "\n";


    cout << "Instanciando AnimalSelvagem\n";
    animalSelvagem = new AnimalSelvagem("Lobo",3, 25, 4, 30);
    cout << *animalSelvagem;
    cout << "\n";
    cout << "Usando operator!= emtre Objetos animalSelvagem diferentes\n";
    animalSelvagemOperator = new AnimalSelvagem;
    cout << "True ou false: " << (*animalSelvagem != *animalSelvagemOperator);
    cout << "\n";

    cout << "Instanciando Cachorro\n";
    cachorro = new Cachorro("Cachorro", 4, 20,4, 43, 18, 2);
    cout << *cachorro;
    cout << "\n";
    cout << "Usando Operator! em objeto Cachorro, diminui a expectativa de vida\n";
    !*cachorro;
    cout << *cachorro;
    cout << "\n";

    cout << "Instanciando Peixe Dourado\n";
    peixeDourado = new PeixeDourado("Neon",5,26,0,47,2,5);
    cout << *peixeDourado;
    cout << "\n";
    cout << "Construtor de Copia de Peixe Dourado\n";
    peixeDouradoCopia = new PeixeDourado(*peixeDourado);
    cout << "printado o objeto que copiou\n";
    cout << *peixeDouradoCopia;

    delete animal;
    delete animalComparacao;
    delete animalDomesticado;
    delete animalDomesticadoOperator;
    delete animalSelvagem;
    delete animalSelvagemOperator;
    delete cachorro;
    delete peixeDourado;
    delete peixeDouradoCopia;


    
    
    //cout << animalCopia;
    //animalCopia = animal;
}