#include "Terrier.h"

Terrier::Terrier()
    :RACA("Jack Russell Terrier"),Cachorro()
{

}
Terrier::Terrier(const string& especie, int idade, int saciedade, int numPatas, int nivelFelicidade, int expectativaDeVida, int quantidadeOrelhas, const string& RACA)
    :RACA(RACA), Cachorro(especie,idade,saciedade,numPatas,nivelFelicidade,expectativaDeVida,quantidadeOrelhas)
{

}
Terrier::Terrier(const Terrier& copia)
    :Cachorro(copia)
{
    this->RACA = copia.RACA;

}



Terrier::~Terrier(){

}

void Terrier::funcaoSocial(){
    int escolha;
    cout << "Escolha uma funcao para fazer: \n";
    cout << "1 - Ficar de Guarda\n";
    cout << "2 - Farejar\n";
    cout << "3 - Cacar\n";
    cout << "Escolha: ";
    cin >> escolha;

    if(escolha == 1){
        ficarDeGuarda();
    }
    if(escolha == 2){
        farejar();
    }
    if(escolha == 3){
        cacar();
    }
}

void Terrier::cacar(){
    //srand(time(NULL));
    cout << "O cachorro esta procurando alguma presa..\n";
    if(rand() < 3 % 10 ){
        cout << "Achou algum roedor!!\n";
        cout << "O cachorro eh premiado pelo esforco...\n";
        alimentar();
        setNivFelicidade(getNivelFelicidade() + 1);
        return;
    }
    cout << "O cachorro nao achou nada!\n";
    cout << "Ele ficou um pouco triste...\n";
    setNivFelicidade(getNivelFelicidade() - 1);
}

ostream& operator<<(ostream& out, const Terrier & terrier){
    out << static_cast<Cachorro>(terrier);
    out << "Raca: " << terrier.RACA << "\n";
    return out;
}

bool Terrier::operator==(const Terrier & ladoDireito){
    if((static_cast<Cachorro>(*this) == static_cast<Cachorro>(ladoDireito)) == false){
        return false;
    }
    if(this->RACA != ladoDireito.RACA){
        return false;
    }
    return true;

}
bool Terrier::operator!=(const Terrier& ladoDireito){
    return !(*this == ladoDireito);
}

Terrier& Terrier::operator=(const Terrier& ladoDireito){
    *static_cast<Cachorro*>(this) = static_cast<Cachorro>(ladoDireito);
    this->RACA = ladoDireito.RACA;

    return *this;
}

Terrier& Terrier::operator!(){
    setSaciedade(getSaciedade() - 1);
    return *this;
}