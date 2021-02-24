#include "clientela.h"

Clientela::Clientela()
{
    clienti.insertBack(new Cliente("Mario Rossi"));
    clienti.insertBack(new Cliente("Sofia Chiarello", 34));
    clienti.insertBack(new Cliente("Giada Zuccolo", 15));
}

Clientela::~Clientela()
{
    List<Cliente*>::Iterator it = clienti.begin();
    for (; it!=clienti.end(); ++it)
        delete *it;
}

List<Cliente *> Clientela::getClienti() const
{
    return clienti;
}

void Clientela::nuovoCliente(Cliente *c){
    clienti.insertFront(c);
}

void Clientela::aggiungiOrdine(Ordine *o, std::string nome){
    List<Cliente*>::Iterator it = clienti.begin();
    for (; it!=clienti.end(); ++it){
        if((*it)->getNome()==nome){
            (*it)->addOrdine(o);
            return;
        }
    }
}

void Clientela::aggiornaCliente(std::string nome, double pz){
    List<Cliente*>::Iterator it = clienti.begin();
    for (; it!=clienti.end(); ++it){
        if((*it)->getNome()==nome){
            (*it)->calcolaPunti(pz);
        }
    }


}
