#include "Cachorro.h"

Cachorro::Cachorro()
    :expectativaDeVida(13),habitat("terra"), quantidadeOrelhas(2),AnimalDomesticado(){

    }


Cachorro::Cachorro(const string& especie, int idade, int saciedade, int numPatas, int nivelFelicidade, int expectativaDeVida, int quantidadeOrelhas)
    :AnimalDomesticado(especie,idade,saciedade, numPatas , nivelFelicidade)
{
    this->expectativaDeVida = expectativaDeVida;
    this->habitat = "terra";
    this->quantidadeOrelhas = quantidadeOrelhas;
}

Cachorro::Cachorro(const Cachorro& copia)
    :AnimalDomesticado(copia)
{
    this->expectativaDeVida = copia.expectativaDeVida;
    this->habitat = copia.habitat;
    this->quantidadeOrelhas = copia.quantidadeOrelhas;
}
Cachorro::~Cachorro(){

}

void Cachorro::latir(){
    cout << "woof woof!\n";
    aumentarNivFelicidade();
}

void Cachorro::correr(){
    cout << "arf arf arf!\n";
    diminuirSaciedade();
}

void Cachorro::printCachorro(){
    cout << "Especie: " << getEspecie() << "\n";
    cout << "Idade: " << getIdade() << "\n";
    cout << "Numero de Patas: " << getNumPatas() << "\n";
    cout << "Nivel de saciedade atual: " << getSaciedade() << "\n";
    cout << "Nivel de Nivel de felicidade: " << getNivelFelicidade() << "\n";
}

std::ostream& operator<<(std::ostream& out, const Cachorro& cachorro){
    out << static_cast<AnimalDomesticado>(cachorro);
    out << "Expectativa de Vida: " << cachorro.expectativaDeVida << "\n";
    out << "Habitat: " << cachorro.habitat << "\n";
    out << "Quantidade de Orelhas: " << cachorro.quantidadeOrelhas << "\n";
    return out;
}

Cachorro& Cachorro::operator=(const Cachorro & ladoDireito){
    *static_cast<AnimalDomesticado *>(this) = static_cast<AnimalDomesticado>( ladoDireito);
    this->expectativaDeVida = ladoDireito.expectativaDeVida;
    this->habitat = ladoDireito.habitat;
    this->quantidadeOrelhas = ladoDireito.quantidadeOrelhas;

    return *this;
}

bool Cachorro::operator==(const Cachorro & ladoDireito){
    if((static_cast<AnimalDomesticado > (*this) == static_cast<AnimalDomesticado> (ladoDireito)) == false){
        return false;
    }
    if(this->expectativaDeVida != ladoDireito.expectativaDeVida){
        return false;
    }
    if(this->habitat != ladoDireito.habitat){
        return false;
    }
    if(this->quantidadeOrelhas != ladoDireito.quantidadeOrelhas){
        return false;
    }
    return true;
}

bool Cachorro::operator!=(const Cachorro& ladoDireito){
    return !(*this == ladoDireito);
}

Cachorro& Cachorro::operator!(){
    this->expectativaDeVida -= 1;

    return *this;
}