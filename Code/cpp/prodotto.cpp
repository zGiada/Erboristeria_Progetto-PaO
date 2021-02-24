#include "prodotto.h"

Prodotto::Prodotto(double ps): peso(ps),prezzo(0){}

Prodotto::~Prodotto(){}

double Prodotto::getPeso() const{
    return peso;
}

double Prodotto::getPrezzo() const{
    return prezzo;
}

void Prodotto::setPrezzo(double p){
    prezzo=p;
}

