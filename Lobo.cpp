#include "Lobo.h"

Lobo::Lobo()
    :AnimalSelvagem()
{

}

Lobo::Lobo(const string& especie, int idade, int saciedade, int numPatas, int nivelStress, int vida, int velocidade, int nivAtaque)
    :AnimalSelvagem(especie,idade,saciedade,numPatas,nivelStress, vida, velocidade, nivAtaque)
{

}

Lobo::Lobo(const Lobo& copia)
    :AnimalSelvagem(copia)
{
    for(int i = 0 ; i < copia.toca.size() ; i++){
        this->toca.push_back(new Presa(*  dynamic_cast<Presa*>( copia.toca[i] )  )); 
    }
}

Lobo::~Lobo(){
    for(int i = 0 ; i < toca.size() ; i++){
        delete toca[i];
    }

}

void Lobo::alimentar(){
    if(!isAlive()){
        return;
    }
    if(toca.size() == 0){
        cout << "O lobo nao cacou nada ainda\n";
        return;
    }
    int escolha;

    printToca();
    cout << "Escolha qual presa voce deseja comer: ";
    cin >> escolha;

    if(escolha < toca.size() && escolha  >= 0 ){
        Presa *presaPtr = dynamic_cast<Presa*> (toca[escolha]);
        tocaItr = toca.begin();
        
        if(presaPtr != 0){
            int i = 0;
            for(i ; i != escolha ; i++){
                tocaItr++;
            }
            setSaciedade(getSaciedade() + presaPtr->getVida());
            if(getVida() < 100){
                setVida(getVida() + 15);
            }
            presaPtr = 0;
            delete toca[i];
            toca.erase(tocaItr);
        }

        cout << "Lobo se alimentou..\n";
        return;
    }

    


}

void Lobo::cacar(){
    if(!isAlive()){
        return;
    }
    //srand(time(NULL));
    setSaciedade(getSaciedade() - 10);
    int rand_Number = rand() % 10;
    cout << "O lobo esta procurando alguma presa...\n";
    if(rand_Number < 1){
        cout << "Não achou nada!\n";
        return;
    }
    else if(rand_Number < 6 && rand_Number >= 1){
        cout << "Encontrou uma presa pequena!\n";
        Presa* presa = new Presa("Esquilo", 1, 20, 4, 40, 5, 40, 1, "Nenhum");
        
        if(presa->getVelocidade() < this->getVelocidade() + 5){
            
            levarParaToca(*presa);
            delete presa;
            return;
        }
        cout << "A presa foi mais rapida e fugiu!\n";
        cout << "Porem o lobo ganhou mais experiencia..\n";
        aumentoVelocidade();
        delete presa;

        return;
    }
    else if (rand_Number > 6 && rand_Number <= 9)
    {
        cout << "Encontrou uma presa media!\n";
        Presa* presa = new Presa("Capivara", 3, 40, 4, 40, 20, 25, 1, "Nenhum");
        if(presa->getVelocidade() < getVelocidade() - 5 && presa->getVida() <= getNivAtaque() ){
            
            levarParaToca(*presa);

            delete presa;
            return;

        }
        cout << "A presa foi mais rapida ou conseguiu aguentar o ataque e fugiu!!\n";
        cout << "Porem o lobo ganhou mais experiencia..\n";
        aumentoNivAtaque();
        aumentoVelocidade();


        delete presa;
        return;
    }

    cout << "Encontrou uma presa grande!\n";
    Presa* presa = new Presa("Alce", 3, 40, 4, 40, 50, 25, 20, "Chifres");
    int escolha;
    cout << "Voce se sente capaz de cacar uma presa grande? A presa pode revidar..\n";
    cout << "1 - Sim\n";
    cout << "2 - Nao\n";
    cout << "Escolha: ";
    cin >> escolha;

    if(escolha == 1){
        cout << "A caca comeca..\n";
        if(presa->getVelocidade() < getVelocidade() - 5 && presa->getVida() <= getNivAtaque() ){
            
            levarParaToca(*presa);

            delete presa;
            return;

        }

        cout << "A presa foi mais rapida ou conseguiu aguentar o ataque e fugiu!!\n";
        cout << "Ela revidou...\n";
        setVida(getVida() - presa->getNivAtaque());
        if(getVida() < 0){
            "O lobo acabou morrendo...\n";
            return;
        }
        cout << "O lobo resistiu\n..";
        cout << "O lobo ganhou mais experiencia..\n";
        aumentoNivAtaque();
        aumentoVelocidade();
        delete presa;
        return;

    }


    cout << "O lobo decide nao se arriscar tanto...\n";

    delete presa;
    
}

void Lobo::uivar(){
    cout << "AUUUUUUUUUUUUUUUUUUUU\n";
    setNivelStress(getNivelStress() - 1);
}

void Lobo::levarParaToca(const Presa& presa){
    cout << "O lobo capturou a presa!\n";
    cout << "O lobo esta levando a presa para a toca...\n";

    toca.push_back(new Presa( presa ));

}

void Lobo::printToca(){
    if(toca.size() == 0){
        cout << "Toca sem alimentos\n";
        return;
    }
    for(int i = 0 ; i < toca.size() ; i++){
        cout << i <<"- Especie: " << toca[i]->getEspecie() << "\n";
        cout << "---------------------------------------\n";
    }
}
ostream& operator<<(ostream& out, const Lobo & lobo){
    lobo.printAnimalSelvagem();

    return out;
}

bool Lobo::operator==(const Lobo& ladoDireito){
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
    if(this->getNivelStress() != ladoDireito.getNivelStress()){
        return false;
    }
    if(this->getVida() != ladoDireito.getVida()){
        return false;
    }
    if(this->getVelocidade() != ladoDireito.getVelocidade()){
        return false;
    }
    if(this->getNivAtaque() != ladoDireito.getNivAtaque()){
        return false;
    }
    if(this->toca.size() != ladoDireito.toca.size()){
        return false;
    }
    for (int i = 0; i < toca.size(); i++)
    {
        //cout << dynamic_cast<Presa*>(this->toca[i]) << "\n";
        if(*dynamic_cast<Presa*>(this->toca[i]) != *dynamic_cast<Presa*>(ladoDireito.toca[i])){
            return false;
        }
    }
    


    return true;
}

bool Lobo::operator!=(const Lobo& ladoDireito){
    return !(*this == ladoDireito);
}

Lobo& Lobo::operator=(const Lobo& ladoDireito){
    this->setEspecie(ladoDireito.getEspecie());
    this->setIdade(ladoDireito.getIdade());
    this->setNumPatas(ladoDireito.getNumPatas());
    this->setSaciedade(ladoDireito.getSaciedade());

    this->setNivelStress(ladoDireito.getNivelStress());
    this->setVida(ladoDireito.getVida());
    this->setVelocidade(ladoDireito.getVelocidade());
    this->setNivAtaque(ladoDireito.getNivAtaque());

    if(this->toca.size() > 0 ){
        this->tocaItr = this->toca.begin();
        for(int i = 0 ; i < this->toca.size() ; i++){
            tocaItr++;
            delete toca[i];
            this->toca.erase(tocaItr);
        }
    }

    this->toca.resize(ladoDireito.toca.size());

    for(int i = 0 ; i < ladoDireito.toca.size() ; i++){
        this->toca[i] = new Presa(*  dynamic_cast<Presa*>( ladoDireito.toca[i] )  ) ;
    }

    return *this;
}

Lobo& Lobo::operator!(){
    cout << "Voce tropecou!\n";
    setVida(getVida() - 1);
    return *this;
}