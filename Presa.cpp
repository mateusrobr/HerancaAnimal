#include "Presa.h"

Presa::Presa()
    :AnimalSelvagem()
{

}

Presa::Presa(const string& especie, int idade, int saciedade, int numPatas, int nivelStress, int vida, int velocidade, int nivAtaque, const string& mecanismoDeDefesa)
    :AnimalSelvagem(especie,idade,saciedade,numPatas,nivelStress, vida, velocidade, nivAtaque)
{
    this->mecanismoDeDefesa = mecanismoDeDefesa;
}

Presa::Presa(const Presa& copia)
    :AnimalSelvagem(copia)
{
    this->mecanismoDeDefesa = copia.mecanismoDeDefesa;
}

Presa::~Presa(){

}

void Presa::alimentar(){
    if(!isAlive()){
        return;
    }
    cout << "O animal esta pastando..\n";
    setSaciedade(getSaciedade() + rand() % 10);
}

ostream& operator<<(ostream& out, const Presa & presa){
    presa.printAnimalSelvagem();
    cout << "Mecanismo de defesa: " << presa.mecanismoDeDefesa;
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
    if(this->mecanismoDeDefesa != ladoDireito.mecanismoDeDefesa){
        return false;
    }
    return true;
}

bool Presa::operator!=(const Presa& ladoDireito){
    return !(*this == ladoDireito);
}

Presa& Presa::operator=(const Presa& ladoDireito){
    this->setEspecie(ladoDireito.getEspecie());
    this->setIdade(ladoDireito.getIdade());
    this->setNumPatas(ladoDireito.getNumPatas());
    this->setSaciedade(ladoDireito.getSaciedade());

    this->setNivelStress(ladoDireito.getNivelStress());
    this->setVida(ladoDireito.getVida());
    this->setVelocidade(ladoDireito.getVelocidade());
    this->setNivAtaque(ladoDireito.getNivAtaque());
    this->mecanismoDeDefesa = ladoDireito.mecanismoDeDefesa;
    return *this;
}

Presa& Presa::operator!(){
    cout << "Voce tropecou!\n";
    setVida(getVida() - 1);
    return *this;
}