#include "Animal.h"


Animal::Animal()
    :especie("especie generica"), idade(1), numPatas(4), saciedade(20){
        //this->saciedade = 20;
    }

Animal::Animal(const Animal & copia){

    this->especie = copia.especie;
    this->idade = copia.idade;
    this->numPatas = copia.numPatas;
    this->saciedade = copia.saciedade;

}

Animal::Animal(const string& especie, int idade, int saciedade, int numPatas)
{
    this->especie = especie;
    this->idade = idade;
    this->numPatas = numPatas;
    this->saciedade = saciedade;
}

Animal::~Animal(){
    
}
string Animal::getEspecie(){
    return especie;
}

int Animal::getIdade(){
    return idade;
}

int Animal::getNumPatas(){
    return numPatas;
}

int Animal::getSaciedade() const{
    return saciedade;
}
string Animal::getEspecie()const {
    return especie;
}

int Animal::getIdade()const {
    return idade;
}

int Animal::getNumPatas()const{
    return numPatas;
}

void Animal::setNumPatas(int numPatas){
    this->numPatas = numPatas;
}
/*void Animal::alimentar(int alimento){
    if((this->saciedade + alimento) > 50 || alimento < 0){
        return;
    }
    this->saciedade += alimento;
    
}*/

void Animal::diminuirSaciedade(){
    if(this->saciedade > 10){
        this->saciedade -= 10;
        return;
    }

}

void Animal::setSaciedade(int saciedade){
    this->saciedade = saciedade;
}

void Animal::setEspecie(const string& especie){
    this->especie = especie;
}

void Animal::setIdade(int idade){
    this->idade = idade;
}

void Animal::printAnimal(){
    cout << "Especie: " << this->especie << "\n";
    cout << "Idade: " << this->idade << "\n";
    cout << "Numero de Patas: " << this->numPatas << "\n";
    cout << "Nivel de saciedade atual: " << this->saciedade << "\n";
}
void Animal::printAnimal() const{
    cout << "Especie: " << this->especie << "\n";
    cout << "Idade: " << this->idade << "\n";
    cout << "Numero de Patas: " << this->numPatas << "\n";
    cout << "Nivel de saciedade atual: " << this->saciedade << "\n";
}


std::ostream& operator<<(std::ostream & out, const Animal & animal){
    out << "Operator << Animal\n";
    out << "Especie: " << animal.especie << "\n";
    out << "Idade: " << animal.idade << "\n";
    out << "Numero de Patas: " << animal.numPatas << "\n";
    out << "Nivel de saciedade atual: " << animal.saciedade << "\n";
    //animal.printAnimal();


    return out;
}

Animal & Animal::operator=(const Animal& ladoDireito){
    this->especie = ladoDireito.especie;
    this->idade = ladoDireito.idade;
    this->numPatas = ladoDireito.numPatas;
    this->saciedade = ladoDireito.saciedade;
    return *this;
}

bool Animal::operator==(const Animal& ladoDireito){
    if(this->especie != ladoDireito.especie){
        return false;
    }
    if(this->idade != ladoDireito.idade){
        return false;
    }
    if(this->numPatas != ladoDireito.numPatas){
        return false;
    }
    if(this->saciedade != ladoDireito.saciedade){
        return false;
    }

    return true;
    
}

bool Animal::operator!=(const Animal& ladoDireito){
    return !(*this == ladoDireito);
}

Animal & Animal::operator!(){
    this->saciedade -= 5;
    return *this;
}