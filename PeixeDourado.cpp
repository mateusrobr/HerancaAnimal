#include "PeixeDourado.h"


PeixeDourado::PeixeDourado()
    :expectativaDeVida(13),habitat("agua"), numBarbatana(4),AnimalDomesticado(){
        setNumPatas();
}

PeixeDourado::PeixeDourado(const PeixeDourado & copia)
    :AnimalDomesticado(copia)
{
    this->expectativaDeVida = copia.expectativaDeVida;
    this->habitat = copia.habitat;
    this->numBarbatana = copia.numBarbatana;
    setNumPatas();
}

PeixeDourado::PeixeDourado(const string& especie, int idade, int saciedade, int numPatas, int nivelFelicidade, int expectativaDeVida, int numBarbatana)
    :AnimalDomesticado(especie,idade,saciedade, 0 , nivelFelicidade)
{
    this->expectativaDeVida = expectativaDeVida;
    this->habitat = "agua";
    this->numBarbatana = numBarbatana;
    setNumPatas();
}

PeixeDourado::~PeixeDourado(){

}

void PeixeDourado::alimentar(){
    int valorNutritivo;
    
    cout << "Descreva o alimento que voce vai oferecer: \n";
    cout << "Valor nutritivo: ";
    cin >> valorNutritivo;
    if((this->getSaciedade() + valorNutritivo) > 50 || valorNutritivo < 0){
        return;
    }
    setSaciedade(getSaciedade() + valorNutritivo);
}

void PeixeDourado::interagir(Animal& animal){
    cout << "O peixe encontra outro animal..\n";
    if(typeid(animal).name() == typeid(Lobo).name()){
        cout << "O peixe e o lobo nao conseguem interagir um com o outro...\n";
        nadar();
    }
    else if(typeid(animal).name() == typeid(Cachorro).name() || typeid(animal).name()){
        cout << "O peixe e o Cachorro nao conseguem interagir um com o outro...\n";
        nadar();
    }
    else if(typeid(animal).name() == typeid(Presa).name()){
        cout << "O peixe e " << animal.getEspecie() << " nao conseguem interagir um com o outro...\n";
        nadar();
    }
    else if(typeid(animal).name() == typeid(PeixeDourado).name()){
        cout << "Os peixes conseguem interagir um com o outro!\n";
        nadar();
    }
}

void PeixeDourado::funcaoSocial(){
    cout << "Funcao social do peixe eh ser bonito\n";
    setNivFelicidade(getNivelFelicidade() + 1);
}


void PeixeDourado::nadar(){
    cout << "brl brl brl!\n";
    diminuirSaciedade();
    aumentarNivFelicidade();
}

ostream& operator<<(ostream& out, const PeixeDourado & peixeDourado){
    //out << static_cast<AnimalDomesticado> (peixeDourado);
    peixeDourado.printAnimalDomestico();
    out << "Expectativa de Vida: " << peixeDourado.expectativaDeVida << "\n";
    out << "Habitat: " << peixeDourado.habitat << "\n";
    out << "Numero de Barbatanas: " << peixeDourado.numBarbatana << "\n";
    return out;

}
PeixeDourado & PeixeDourado::operator=(const PeixeDourado & ladoDireito){
    this->setEspecie(ladoDireito.getEspecie());
    this->setIdade(ladoDireito.getIdade());
    this->setNumPatas(ladoDireito.getNumPatas());
    this->setSaciedade(ladoDireito.getSaciedade());

    this->setNivFelicidade(ladoDireito.getNivelFelicidade());
    this->expectativaDeVida = ladoDireito.expectativaDeVida;
    this->habitat = ladoDireito.habitat;
    this->numBarbatana = ladoDireito.numBarbatana;

    return *this;
}
bool PeixeDourado::operator==(const PeixeDourado & ladoDireito){
    /*if((static_cast<AnimalDomesticado > (*this) == static_cast<AnimalDomesticado> (ladoDireito)) == false){
        return false;
    }*/
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
    if(this->getNivelFelicidade() != ladoDireito.getNivelFelicidade()){
        return false;
    }

    if(this->expectativaDeVida != ladoDireito.expectativaDeVida){
        return false;
    }
    if(this->habitat != ladoDireito.habitat){
        return false;
    }
    if(this->numBarbatana != ladoDireito.numBarbatana){
        return false;
    }
    return true;
}
bool PeixeDourado::operator!=(const PeixeDourado & ladoDireito){
    return !(*this == ladoDireito);
}
PeixeDourado & PeixeDourado::operator!(){
    this->expectativaDeVida -= 1;

    return *this;
}