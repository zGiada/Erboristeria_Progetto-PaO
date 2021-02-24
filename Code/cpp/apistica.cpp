#include "apistica.h"



Apistica::Apistica(double ps, double l): Prodotto(ps), tempoLavorazione(l) {}



double Apistica::getTempoLavorazione() const
{
    return tempoLavorazione;
}


