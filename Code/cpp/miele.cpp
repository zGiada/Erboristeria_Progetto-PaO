#include "miele.h"
#include "math.h"
double Miele::pMiele = 0.05;
double Miele::PrezzoLavorazione = 0.0003;
Miele::Miele(double ps): Prodotto(ps),Apistica(ps, 20) {} //tempo di lavorazione per il miele

double Miele::calcolaLavorazione()
{
    return (PrezzoLavorazione * getTempoLavorazione());
}

double Miele::calcolaPrezzo()
{

    double p=calcolaLavorazione()+(pMiele*getPeso());
    setPrezzo(p);
    return p;
}

std::string Miele::stampa() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
};

std::ostringstream& operator<<(std::ostringstream& os,const Miele& m){
    os.precision(2);
    os<<"Miele ("<<std::fixed<<m.getPeso()<<" gr): ";
    os<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    return os;
}
