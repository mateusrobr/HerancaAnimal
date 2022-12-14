#include <iostream>

#include "Animal.h"
#include "Animal.cpp"

#include "AnimalDomesticado.h"
#include "AnimalDomesticado.cpp"

#include "AnimalSelvagem.h"
#include "AnimalSelvagem.cpp"

#include "Cachorro.h"
#include "Cachorro.cpp"

#include "PeixeDourado.h"
#include "PeixeDourado.cpp"

#include "Bordercollie.h"
#include "Bordercollie.cpp"

#include "Terrier.h"
#include "Terrier.cpp"

#include "Lobo.h"
#include "Lobo.cpp"

#include "Presa.h"
#include "Presa.cpp"

#include <vector>
using std::vector;

int main(){
    srand(time(0));
    
    vector<Animal*> animais;
    animais.push_back(new Cachorro());
    animais.push_back(new Terrier());
    animais.push_back(new Bordercollie());
    animais.push_back(new PeixeDourado());
    animais.push_back(new Lobo("Lobo",2, 40, 4, 30, 40, 36, 40));
    animais.push_back(new Presa());

    for(int i = 0 ; i < animais.size() ; i++){

        if(typeid(*animais[i]).name() == typeid(Cachorro).name()){
            cout << "Cachorro:\n";
            Cachorro* cachorroPtr = dynamic_cast<Cachorro*>(animais[i]);
            cachorroPtr->funcaoSocial();
            cachorroPtr->alimentar();
        }
        else if (typeid(*animais[i]).name() == typeid(Terrier).name())
        {
            cout << "Terrier:\n";
            Terrier *terrierPtr = dynamic_cast<Terrier*>(animais[i]);
            terrierPtr->funcaoSocial();
        }
        else if (typeid(*animais[i]).name() == typeid(Bordercollie).name())
        {
            cout << "Bordercollie:\n";
            Bordercollie *bordercolliePtr = dynamic_cast<Bordercollie*>(animais[i]);
            bordercolliePtr->funcaoSocial();
        }
        else if (typeid(*animais[i]).name() == typeid(PeixeDourado).name())
        {
            cout << "Peixe Dourado:\n";
            PeixeDourado *peixePtr = dynamic_cast<PeixeDourado*> (animais[i]);
            peixePtr->funcaoSocial();
            peixePtr->nadar();
        }
        else if (typeid(*animais[i]).name() == typeid(Lobo).name())
        {
            cout << "Lobo:\n";
            Lobo *loboPtr = dynamic_cast<Lobo*>(animais[i]);
            loboPtr->cacar();
            loboPtr->alimentar();
        }
        else if (typeid(*animais[i]).name() == typeid(Presa).name())
        {
            cout << "Presa:\n";
            Presa *presaPtr = dynamic_cast<Presa*>(animais[i]);
            presaPtr->alimentar();
            cout << *presaPtr;
        }
        
        
        
        
    }



    vector<Animal *>::iterator animaisItr = animais.begin();
    for(int i = 0 ; i < animais.size() ; i++){
        animaisItr++;
        delete animais[i];
        animais.erase(animaisItr);
    }



}
