#include "propoli.h"

 double Propoli::pPropoli=0.4;
 double Propoli::prezzoLavorP=0.003;

double Propoli::pNaturale=3;

Propoli::Propoli(double ps, bool n=false, bool s=false) :Prodotto(ps), Apistica(ps, 40), Capsule(ps,s), naturale(n)
{}

double Propoli::calcolaLavorazione()
{
    double prezzo = getTempoLavorazione()*prezzoLavorP;
    if (naturale) prezzo+=pNaturale;
    return prezzo;
}

double Propoli::calcolaPrezzo()
{
    double prezzo = Apistica::getPeso()*pPropoli + calcolaLavorazione(); // prezzo base
    if (getSacchetto()) prezzo = prezzo + prezzo*getScontoSacchetto();
    setPrezzo(prezzo);
    return prezzo;
}

std::string Propoli::stampa() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostringstream& operator<<(std::ostringstream& os,const Propoli& m){
    os.precision(2);
    if (m.naturale){
        if(m.getSacchetto())
            os<<"Propoli ("<<std::fixed<<m.getPeso()<<" gr), naturale, in sacchetto: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
        else
            os<<"Propoli ("<<std::fixed<<m.getPeso()<<" gr), naturale: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    else{
        if(m.getSacchetto())
            os<<"Propoli ("<<std::fixed<<m.getPeso()<<" gr), in sacchetto: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
        else
            os<<"Propoli ("<<std::fixed<<m.getPeso()<<" gr): "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    return os;
}

