#include "AnimalSelvagem.h"

AnimalSelvagem::AnimalSelvagem()
    :nivelStress(20), vida(50), velocidade(40), nivAtaque(20),Animal()
{

}

AnimalSelvagem::AnimalSelvagem(const AnimalSelvagem& copia)
    :Animal(copia)
{
    this->nivelStress = copia.nivelStress;
    this->vida = copia.vida;
    this->velocidade = copia.velocidade;
    this->nivAtaque = copia.nivAtaque;
}

AnimalSelvagem::AnimalSelvagem(const string& especie, int idade, int saciedade, int numPatas, int nivelStress, int vida, int velocidade, int nivAtaque)
    :Animal(especie,idade,saciedade, numPatas)
{
    this->nivelStress = nivelStress;
    this->vida = vida;
    this->velocidade = velocidade;
    this->nivAtaque = nivAtaque;
}

AnimalSelvagem::~AnimalSelvagem(){

}

/*void AnimalSelvagem::fugirDePredadores(){
    cout << "O animal se sentiu ameacado e fugiu\n";
    if(this->nivelStress > 5){
        this->nivelStress -= 5;
        diminuirSaciedade();
        return;
    }

}*/

void AnimalSelvagem::setVida(int novaVida){
    if(isAlive()){
        this->vida = novaVida;
    }
}
int AnimalSelvagem::getVida(){
    return vida;
}
int AnimalSelvagem::getVelocidade(){
    return velocidade;
}

int AnimalSelvagem::getNivAtaque(){
    return nivAtaque;
}
int AnimalSelvagem::getVida()const{
    return vida;
}
int AnimalSelvagem::getVelocidade()const{
    return velocidade;
}

int AnimalSelvagem::getNivAtaque()const{
    return nivAtaque;
}

int AnimalSelvagem::getNivelStress(){
    return this->nivelStress;
}

int AnimalSelvagem::getNivelStress() const{
    return this->nivelStress;
}

void AnimalSelvagem::aumentoVelocidade(){
    this->velocidade++;
}

void AnimalSelvagem::aumentoNivAtaque(){
    this->nivAtaque += 3;
}

bool AnimalSelvagem::isAlive(){
    return (this->vida > 0);
}

void AnimalSelvagem::setNivelStress(int nivelStress){
    this->nivelStress = nivelStress;
}

void AnimalSelvagem::setVelocidade(int velocidade){
    this->velocidade = velocidade;
}

void AnimalSelvagem::setNivAtaque(int nivAtaque){
    this->nivAtaque = nivAtaque;
}

void AnimalSelvagem::printAnimalSelvagem(){
    printAnimal();
    cout << "Nivel de stress: " << this->nivelStress << "\n";
    cout << "Vida: " << this->vida << "\n";
    cout << "Velocidade: " << this->velocidade << "\n";
    cout << "Nivel de Ataque: " << this->nivAtaque << "\n";
}
void AnimalSelvagem::printAnimalSelvagem()const{
    printAnimal();
    cout << "Nivel de stress: " << this->nivelStress << "\n";
    cout << "Vida: " << this->vida << "\n";
    cout << "Velocidade: " << this->velocidade << "\n";
    cout << "Nivel de Ataque: " << this->nivAtaque << "\n";
}

ostream& operator<<(ostream& out, const AnimalSelvagem& animalSelvagem){
    //out << static_cast<Animal> (animalSelvagem);
    out << "Nilve de Stress: " << animalSelvagem.nivelStress << "\n";

    return out;
}

AnimalSelvagem& AnimalSelvagem::operator=(const AnimalSelvagem& ladoDireito){
    //*static_cast<Animal *>(this) = static_cast<Animal>( ladoDireito);
    this->nivelStress = ladoDireito.nivelStress;
    return *this;
}

bool AnimalSelvagem::operator==(const AnimalSelvagem& ladoDireito){
    /*if((static_cast<Animal > (*this) == static_cast<Animal> (ladoDireito)) == false){
        return false;
    }*/
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