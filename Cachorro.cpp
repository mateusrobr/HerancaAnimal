#include "Cachorro.h"

Cachorro::Cachorro()
    :expectativaDeVida(13),AnimalDomesticado(){
        cout << "Construtor Cachorro\n";
    }


Cachorro::Cachorro(const string& especie, int idade, int saciedade, int numPatas, int nivelFelicidade, int expectativaDeVida)
    :AnimalDomesticado(especie,idade,saciedade, numPatas , nivelFelicidade)
{

}

Cachorro::Cachorro(const Cachorro& copia)
    :AnimalDomesticado(copia)
{

}
Cachorro::~Cachorro(){

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
    return out;
}