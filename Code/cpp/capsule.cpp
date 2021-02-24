#include "capsule.h"
double Capsule::scontoSacchetto=0.1;

Capsule::Capsule(double ps, bool s=false): Prodotto(ps), Integratori(ps), sacchetto(s)
{
}

bool Capsule::getSacchetto() const
{
    return sacchetto;

}

double Capsule::getScontoSacchetto() const
{
    return scontoSacchetto;
}
