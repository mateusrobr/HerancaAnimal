#include "Bordercollie.h"

Bordercollie::Bordercollie()
    :RACA("Bordercollie"),Cachorro()
{

}
Bordercollie::Bordercollie(const string& especie, int idade, int saciedade, int numPatas, int nivelFelicidade, int expectativaDeVida, int quantidadeOrelhas, const string& RACA)
    :RACA(RACA), Cachorro(especie,idade,saciedade,numPatas,nivelFelicidade,expectativaDeVida,quantidadeOrelhas)
{

}
Bordercollie::Bordercollie(const Bordercollie& copia)
    :Cachorro(copia)
{
    this->RACA = copia.RACA;

}

Bordercollie::~Bordercollie(){

}


void Bordercollie::funcaoSocial(){
    int escolha;
    cout << "Escolha uma funcao para fazer: \n";
    cout << "1 - Ficar de Guarda\n";
    cout << "2 - Farejar\n";
    cout << "3 - Pastorear\n";
    cout << "Escolha: ";
    cin >> escolha;

    if(escolha == 1){
        ficarDeGuarda();
    }
    if(escolha == 2){
        farejar();
    }
    if(escolha == 3){
        pastorear();
    }
}

void Bordercollie::pastorear(){
    //srand(time(NULL));
    cout << "Cachorro esta tentando cumprir suas funcoes...\n";
    if(rand() % 10 < 2){
        cout << "Uma ovelha fugiu!!\n";
        cout << "Cachorro ficou triste...\n";
        setNivFelicidade(getNivelFelicidade() - 1);
        return;
    }
    cout << "Tudo ocorreu como esperado!!\n";
    cout << "Cachorro recebeu um premio pelo otimo trabalho..\n";
    alimentar();
    aumentarNivFelicidade();

}

ostream& operator<<(ostream& out, const Bordercollie & bordercollie){
    out << static_cast<Cachorro>(bordercollie);
    out << "Raca: " << bordercollie.RACA << "\n";

    return out;
}
bool Bordercollie::operator==(const Bordercollie& ladoDireito){
    if((static_cast<Cachorro>(*this) == static_cast<Cachorro>(ladoDireito)) == false){
        return false;
    }
    if(this->RACA != ladoDireito.RACA){
        return false;
    }
    return true;
}

bool Bordercollie::operator!=(const Bordercollie& ladoDireito){
    return !(*this == ladoDireito);
}

Bordercollie& Bordercollie::operator=(const Bordercollie& copia){
    *static_cast<Cachorro*>(this) = static_cast<Cachorro>(copia);
    //*static_cast<AnimalDomesticado *>(this) = static_cast<AnimalDomesticado>( ladoDireito);
    this->RACA = copia.RACA;
    return *this;
}