#include "lineate.h"

double LineaTe::prezzoaromatizzato=0.002;
double LineaTe::prezzoTe= 0.09;

LineaTe::LineaTe(double ps, bool con, bool a):Bevande(ps,con), aromatizzato(a)
{

}

double LineaTe::calcolaPrezzo()
{
    double p=getPeso()*prezzoTe;
        if(getTipoConf()){
            if(aromatizzato)
                p = p+(getPeso()*prezzoaromatizzato)+getPrezzoConReg();
            else
                p = p + getPrezzoConReg();
        } else if (aromatizzato)
            p = p+(getPeso()*prezzoaromatizzato);

        setPrezzo(p);

        return p;

}

std::string LineaTe::stampa() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostringstream& operator<<(std::ostringstream& os,const LineaTe& m){
    os.precision(2);
    if (m.aromatizzato){
        if(m.getTipoConf())
            os<<"Linea Te ("<<std::fixed<<m.getPeso()<<" gr), aromatizzato, conf. regalo: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
        else
            os<<"Linea Te ("<<std::fixed<<m.getPeso()<<" gr), aromatizzato: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    else{
        if(m.getTipoConf())
            os<<"Linea Te ("<<std::fixed<<m.getPeso()<<" gr), conf. regalo: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
        else
            os<<"Linea Te ("<<std::fixed<<m.getPeso()<<" gr): "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    return os;
}
