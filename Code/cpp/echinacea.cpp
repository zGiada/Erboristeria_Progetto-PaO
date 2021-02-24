#include "echinacea.h"

double Echinacea::PEchinacea = 0.23;

Echinacea::Echinacea(double ps, bool s):Prodotto(ps),Capsule(ps,s)
{

}

double Echinacea::calcolaPrezzo()
{
    double p = getPeso()*PEchinacea;
    if (getSacchetto() && p!=0) p=p+p*getScontoSacchetto();
    setPrezzo(p);
    return p;
}

std::string Echinacea::stampa() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostringstream& operator<<(std::ostringstream& os,const Echinacea& m){
    os.precision(2);
    if(m.getSacchetto()){
        os<<"Echinacea ("<<std::fixed<<m.getPeso()<<" gr), in sacchetto: ";

        os<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    else{
        os<<"Echinacea ("<<std::fixed<<m.getPeso()<<" gr): ";
        os<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    return os;
}
