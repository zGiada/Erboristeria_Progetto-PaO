#include "bevande.h"

double Bevande::prezzoConfReg=3.5;


Bevande::Bevande(double ps, bool conf=false):Prodotto(ps), tipoConfezione(conf)
{

}

bool Bevande::getTipoConf() const
{
    return tipoConfezione;

}



double Bevande::getPrezzoConReg() const
{
    return prezzoConfReg;
}

