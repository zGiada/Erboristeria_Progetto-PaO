#include "cliente.h"

Cliente::Cliente(std::string c, int p) : nomeCliente(c), punti(p) {}

Cliente::~Cliente(){
    List<Ordine*>::Iterator it = ordini.begin();
    for (; it!=ordini.end(); ++it){
        delete *it;
    }
}
void Cliente::calcolaPunti(double prezzo)  {
    int p = prezzo*0.8;
    setPunti(p);

}
void Cliente::setPunti(int p){
    punti=punti+p;
}

int Cliente::getPunti() const
{
    return  punti;
}

std::string Cliente::getNome() const
{
    return  nomeCliente;
}

void Cliente::addOrdine(Ordine *o){
    ordini.insertFront(o);
}
