#include "AnimalDomesticado.h"


AnimalDomesticado::AnimalDomesticado()
    :nivelFelicidade(20), Animal()
{
    //cout << "Construtor animalDomesticado\n";
}

AnimalDomesticado::AnimalDomesticado(const AnimalDomesticado& copia)
    :Animal(copia)
{
    this->nivelFelicidade = copia.nivelFelicidade;
}

AnimalDomesticado::AnimalDomesticado(const string& especie, int idade, int saciedade, int numPatas, int nivelFelicidade)
    :Animal(especie,idade,saciedade, numPatas)
{
    this->nivelFelicidade = nivelFelicidade;
    //cout << "Construtor animalDomesticado\n";
}



AnimalDomesticado::~AnimalDomesticado(){}


int AnimalDomesticado::getNivelFelicidade(){
    return nivelFelicidade;
}
int AnimalDomesticado::getNivelFelicidade()const{
    return nivelFelicidade;
}

/*void AnimalDomesticado::interagir(){
    int interacao;
    cout << "Escolha o tipo de interacao: \n";
    cout << "1 - Acariricar\n";
    cout << "2 - Atazanar\n";
    cout << "Escolha: ";
    cin >> interacao;
    if(interacao == 1 ){
        this->nivelFelicidade += 5;
    }
    else if(interacao == 2){
        this->nivelFelicidade -= 5;
    }
}*/

void AnimalDomesticado::aumentarNivFelicidade(){
    if(this->nivelFelicidade < 50){
        this->nivelFelicidade++;
        return;
    }
    
}

void AnimalDomesticado::setNivFelicidade(int nivelFelicidade){
    this->nivelFelicidade = nivelFelicidade;
}

void AnimalDomesticado::printAnimalDomestico(){
    cout << "Nivel de Felicidade: " << this->nivelFelicidade << "\n";
}

void AnimalDomesticado::printAnimalDomestico() const{
    printAnimal();
    cout << "Nivel de felidade: " << nivelFelicidade << "\n";
}


std::ostream& operator<<( std::ostream& out, const AnimalDomesticado& animalDomesticado){
    //out << static_cast<Animal> (animalDomesticado);
    out << "Nivel de Felicidade: " <<animalDomesticado.nivelFelicidade << "\n";

    return out;
}
AnimalDomesticado & AnimalDomesticado::operator=(const AnimalDomesticado& ladoDireito){
    //*static_cast<Animal *>(this) = static_cast<Animal>( ladoDireito);
    this->nivelFelicidade = ladoDireito.nivelFelicidade;
    return *this;
}

bool AnimalDomesticado::operator==(const AnimalDomesticado& ladoDireito){
    /*if((static_cast<Animal > (*this) == static_cast<Animal> (ladoDireito)) == false){
        return false;
    }*/
    if(this->nivelFelicidade != ladoDireito.nivelFelicidade){
        return false;
    }
    return true;
}

bool AnimalDomesticado::operator!=(const AnimalDomesticado& ladoDireito){
    return !(*this == ladoDireito);
}
AnimalDomesticado & AnimalDomesticado::operator!(){
    this->nivelFelicidade -= 5;
    return *this;
}