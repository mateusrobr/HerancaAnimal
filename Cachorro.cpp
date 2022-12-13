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

void Cachorro::alimentar(){
    int valorNutritivo;
    
    cout << "Descreva o alimento que voce vai oferecer: \n";
    cout << "Valor nutritivo: ";
    cin >> valorNutritivo;
    if((this->getSaciedade() + valorNutritivo) > 50 || valorNutritivo < 0){
        return;
    }
    setSaciedade(getSaciedade() + valorNutritivo);
}

void Cachorro::interagir(){
    int interacao;
    cout << "Escolha o tipo de interacao: \n";
    cout << "1 - Acariricar\n";
    cout << "2 - Atazanar\n";
    cout << "Escolha: ";
    cin >> interacao;
    if(interacao == 1 ){
        setNivFelicidade(getNivelFelicidade() + 5);
    }
    else if(interacao == 2){
        setNivFelicidade(getNivelFelicidade() - 5);
    }
}

void Cachorro::funcaoSocial(){
    int escolha;
    cout << "Escolha uma funcao para fazer: \n";
    cout << "1 - Ficar de Guarda\n";
    cout << "2 - Farejar\n";
    cin >> escolha;

    if(escolha == 1){
        ficarDeGuarda();
    }
    if(escolha == 2){
        farejar();
    }
}

void Cachorro::ficarDeGuarda(){
    //srand(time(NULL));
    cout << "O cachorro fica de prontidao pronto para avisar qualquer coisa...\n";
    if(rand() % 10 > 5){
        latir();
        return;
    }
    cout << "Nada ocorreu...\n";
}

void Cachorro::farejar(){
    srand(time(NULL));
    cout << "O cachorro esta procurando algo...\n";
    if(rand() % 10 > 3){
        cout << "Achou comida!!\n";
        alimentar();
        return;
    }
    else{
        cout << "Achou nada =(\n";
        setNivFelicidade(getNivelFelicidade() - 1);
    }
}

void Cachorro::printCachorro(){
    //printAnimal();
    printAnimalDomestico();
    cout << "Nivel de Nivel de felicidade: " << getNivelFelicidade() << "\n";
}

std::ostream& operator<<(std::ostream& out, const Cachorro& cachorro){
    //out << static_cast<AnimalDomesticado>(cachorro);
    //cachorro.printAnimal();
    cachorro.printAnimalDomestico();
    out << "Expectativa de Vida: " << cachorro.expectativaDeVida << "\n";
    out << "Habitat: " << cachorro.habitat << "\n";
    out << "Quantidade de Orelhas: " << cachorro.quantidadeOrelhas << "\n";
    return out;
}

Cachorro& Cachorro::operator=(const Cachorro & ladoDireito){
   // *static_cast<AnimalDomesticado *>(this) = static_cast<AnimalDomesticado>( ladoDireito);
    this->setEspecie(ladoDireito.getEspecie());
    this->setIdade(ladoDireito.getIdade());
    this->setNumPatas(ladoDireito.getNumPatas());
    this->setSaciedade(ladoDireito.getSaciedade());

    this->setNivFelicidade(ladoDireito.getNivelFelicidade());
    
    this->expectativaDeVida = ladoDireito.expectativaDeVida;
    this->habitat = ladoDireito.habitat;
    this->quantidadeOrelhas = ladoDireito.quantidadeOrelhas;

    return *this;
}

bool Cachorro::operator==(const Cachorro & ladoDireito){
   /* if((static_cast<AnimalDomesticado > (*this) == static_cast<AnimalDomesticado> (ladoDireito)) == false){
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