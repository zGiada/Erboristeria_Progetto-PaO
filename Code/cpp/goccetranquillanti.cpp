#include "goccetranquillanti.h"
double GocceTranquillanti::prezzogocce = 0.23;
GocceTranquillanti::GocceTranquillanti(double ps, bool con): Prodotto(ps),Fluidi(ps,con)
{

}
double GocceTranquillanti::calcolaPrezzo()
{
    double p=getPeso()*prezzogocce;
    if (getConfF()) p+=getPrezzoPlastica();
    else p+=getPrezzoVetro();
    setPrezzo(p);
    return p;
}

std::string GocceTranquillanti::stampa() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostringstream& operator<<(std::ostringstream& os,const GocceTranquillanti& m){
    os.precision(2);
    if(m.getConfF()){
        os<<"Gocce Tranquillanti ("<<std::fixed<<m.getPeso()<<" gr), conf. in plastica: ";
        os<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }else{
        os<<"Gocce Tranquillanti ("<<std::fixed<<m.getPeso()<<" gr): conf. in vetro: ";
        os<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    return os;
}
