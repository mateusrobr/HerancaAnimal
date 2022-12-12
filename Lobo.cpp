#include "Lobo.h"

Lobo::Lobo()
    :AnimalSelvagem()
{

}

Lobo::~Lobo(){

}

ostream& operator<<(ostream& out, const Lobo & lobo){
    lobo.printAnimalSelvagem();

    return out;
}