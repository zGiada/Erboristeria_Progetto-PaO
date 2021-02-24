#include "sciroppobalsamico.h"

double SciroppoBalsamico::prezzoScirop = 0.1;

SciroppoBalsamico::SciroppoBalsamico(double ps, bool s =false): Prodotto(ps), Fluidi(ps,s){}
double SciroppoBalsamico::calcolaPrezzo()
{
    double p =getPeso()*prezzoScirop;
    if(getConfF())
        p += getPrezzoPlastica();
    else
        p +=getPrezzoVetro();
    setPrezzo(p);
    return p;
}

std::string SciroppoBalsamico::stampa() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostringstream& operator<<(std::ostringstream& os,const SciroppoBalsamico& m){
    os.precision(2);
    if(m.getConfF())
        os<<"Sciroppo Balsamico ("<<std::fixed<<m.getPeso()<<" gr), conf. in plastica: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    else
        os<<"Sciroppo Balsamico ("<<std::fixed<<m.getPeso()<<" gr): conf. in vetro: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    return os;
}
