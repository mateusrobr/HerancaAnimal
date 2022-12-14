#ifndef BORDERCOLLIE_H
#define BORDERCOLLIE_H

#include "Cachorro.h"

class Bordercollie : public Cachorro
{
    friend ostream& operator<<(ostream&, const Bordercollie&);
    public:
        Bordercollie();
        Bordercollie(const string&, int, int, int, int, int, int, const string&);
        Bordercollie(const Bordercollie &);
        ~Bordercollie();

        virtual void funcaoSocial();

        void pastorear();
        

        Bordercollie& operator=(const Bordercollie&);
        bool operator==(const Bordercollie&);
        bool operator!=(const Bordercollie&);
        Bordercollie& operator!();

    private:
        string RACA;



};
#endif