#include "Terrier.h"

Terrier::Terrier()
    :RACA("Jack Russell Terrier"),Cachorro()
{

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
    srand(time(NULL));
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