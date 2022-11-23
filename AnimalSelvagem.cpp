#include "AnimalSelvagem.h"

AnimalSelvagem::AnimalSelvagem()
    :nivelStress(20), Animal()
{

}

AnimalSelvagem::AnimalSelvagem(const AnimalSelvagem& copia)
    :Animal(copia)
{
    this->nivelStress = copia.nivelStress;
}

AnimalSelvagem::AnimalSelvagem(const string& especie, int idade, int saciedade, int numPatas, int nivelStress)
    :Animal(especie,idade,saciedade, numPatas)
{
    this->nivelStress = nivelStress;
}

AnimalSelvagem::~AnimalSelvagem(){

}

void AnimalSelvagem::fugirDePredadores(){
    cout << "O animal se sentiu ameacado e fugiu\n";
    if(this->nivelStress > 5){
        this->nivelStress -= 5;
        diminuirSaciedade();
        return;
    }

}

ostream& operator<<(ostream& out, const AnimalSelvagem& animalSelvagem){
    out << static_cast<Animal> (animalSelvagem);
    out << "Nilve de Stress: " << animalSelvagem.nivelStress << "\n";

    return out;
}

AnimalSelvagem& AnimalSelvagem::operator=(const AnimalSelvagem& ladoDireito){
    *static_cast<Animal *>(this) = static_cast<Animal>( ladoDireito);
    this->nivelStress = ladoDireito.nivelStress;
    return *this;
}

bool AnimalSelvagem::operator==(const AnimalSelvagem& ladoDireito){
    if((static_cast<Animal > (*this) == static_cast<Animal> (ladoDireito)) == false){
        return false;
    }
    if(this->nivelStress != ladoDireito.nivelStress){
        return false;
    }
    return true;
}
bool AnimalSelvagem::operator!=(const AnimalSelvagem& ladoDireito){
    return !(*this == ladoDireito);
}
AnimalSelvagem& AnimalSelvagem::operator!(){
    this->nivelStress += 5;
    return *this;
}