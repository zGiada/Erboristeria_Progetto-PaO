#include "ordine.h"

Ordine::Ordine(double s):saldo(s){

}

Ordine::~Ordine()
{
    List<Prodotto*>::Iterator it = prodotti.begin();
    for (; it!=prodotti.end(); ++it){
        delete *it;
    }
}

double Ordine::calcolaTotale(){
    double prezzo=0;
    List<Prodotto*>::Iterator it = prodotti.begin();
    for (; it!=prodotti.end(); ++it) {
        prezzo += (*it)->calcolaPrezzo();
    }
    setSaldo(prezzo);
    return prezzo;
}

double Ordine::addIva() const
{
    return saldo+(saldo * 0.22);
}

void Ordine::setSaldo(double p)
{
    saldo = p;
}

double Ordine::getSaldo() const
{
    return saldo;
}

void Ordine::inserisciProdotto(Prodotto * o){
    prodotti.insertBack(o);
}

std::string Ordine::stampaTotali() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
};

std::ostringstream& operator<<(std::ostringstream& os,const Ordine& m){
    os.precision(2);
    os<<"Prezzo totale (con IVA) "<<std::fixed<<m.addIva()<<" euro\n";
    os<<"Prezzo totale (no IVA) "<<std::fixed<<m.getSaldo()<<" euro"<<std::endl;
    return os;
}

