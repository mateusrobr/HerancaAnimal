#include "Presa.h"

Presa::Presa()
    :AnimalSelvagem()
{

}

Presa::Presa(const string& especie, int idade, int saciedade, int numPatas, int nivelStress, int vida, int velocidade, int nivAtaque)
    :AnimalSelvagem(especie,idade,saciedade,numPatas,nivelStress, vida, velocidade, nivAtaque)
{

}

Presa::Presa(const Presa& copia)
    :AnimalSelvagem(copia)
{

}

Presa::~Presa(){

}

void Presa::alimentar(){
    if(!isAlive()){
        return;
    }
    //srand(time(NULL));
    cout << "O animal esta pastando..\n";
    setSaciedade(getSaciedade() + rand() % 10);
}

ostream& operator<<(ostream& out, const Presa & presa){
    presa.printAnimalSelvagem();
    return out;
}

bool Presa::operator==(const Presa& ladoDireito){
    if(this->getEspecie() != ladoDireito.getEspecie()){
        return false;
    }
    if(this->getIdade() != ladoDireito.getIdade()){
        return false;
    }
    if(this->getNumPatas() != ladoDireito.getNumPatas()){
        return false;
    }
    if(this->getSaciedade() != ladoDireito.getSaciedade()){
        return false;
    }
    if(this->getNivelStress() != ladoDireito.getNivelStress()){
        return false;
    }
    if(this->getVida() != ladoDireito.getVida()){
        return false;
    }
    if(this->getVelocidade() != ladoDireito.getVelocidade()){
        return false;
    }
    if(this->getNivAtaque() != ladoDireito.getNivAtaque()){
        return false;
    }
    return true;
}

bool Presa::operator!=(const Presa& ladoDireito){
    return !(*this == ladoDireito);
}