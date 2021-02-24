#include "pappareale.h"
double PappaReale:: pPappaReale=0.39;
double PappaReale::PrezzoLav=0.0003;


PappaReale::PappaReale(double ps) : Prodotto(ps),Apistica(ps, 60) //60 tempo di lavorazione
{}

double PappaReale::calcolaLavorazione()
{
    return (getTempoLavorazione()*PrezzoLav);

}

double PappaReale::calcolaPrezzo()
{
    double p = calcolaLavorazione()+pPappaReale*getPeso();
    setPrezzo(p);
    return p;

}

std::string PappaReale::stampa() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
};

std::ostringstream& operator<<(std::ostringstream& os,const PappaReale& m){
    os.precision(2);
    os<<"Pappa reale ("<<std::fixed<<m.getPeso()<<" gr): "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    return os;
}
