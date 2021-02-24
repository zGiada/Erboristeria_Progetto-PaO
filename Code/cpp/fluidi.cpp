#include "fluidi.h"

double Fluidi::prezzoVetro=1.5;
double Fluidi::prezzoPlastica=0.99;

Fluidi::Fluidi(double ps, bool con=true): Integratori(ps), confezionePlastica(con)
{

}
bool Fluidi::getConfF() const {
    return confezionePlastica;
}

double Fluidi::getPrezzoPlastica() const{
    return prezzoPlastica;
}

double Fluidi::getPrezzoVetro() const {
    return prezzoVetro;
}
