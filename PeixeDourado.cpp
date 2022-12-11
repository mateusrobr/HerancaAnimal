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

void PeixeDourado::nadar(){
    cout << "brl brl brl!\n";
    diminuirSaciedade();
}

ostream& operator<<(ostream& out, const PeixeDourado & peixeDourado){
    //out << static_cast<AnimalDomesticado> (peixeDourado);
    out << "Expectativa de Vida: " << peixeDourado.expectativaDeVida << "\n";
    out << "Habitat: " << peixeDourado.habitat << "\n";
    out << "Numero de Barbatanas: " << peixeDourado.numBarbatana << "\n";
    return out;

}
PeixeDourado & PeixeDourado::operator=(const PeixeDourado & ladoDireito){
   // *static_cast<AnimalDomesticado *>(this) = static_cast<AnimalDomesticado>( ladoDireito);
    this->expectativaDeVida = ladoDireito.expectativaDeVida;
    this->habitat = ladoDireito.habitat;
    this->numBarbatana = ladoDireito.numBarbatana;

    return *this;
}
bool PeixeDourado::operator==(const PeixeDourado & ladoDireito){
    /*if((static_cast<AnimalDomesticado > (*this) == static_cast<AnimalDomesticado> (ladoDireito)) == false){
        return false;
    }*/
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