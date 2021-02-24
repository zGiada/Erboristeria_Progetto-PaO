#include "tisana.h"
double Tisana::prezzofiltro = 0.45;
double Tisana:: pTisana = 0.13;
//bool reg = confezione regalo T/F; bool f = filtro oppure no
Tisana::Tisana(double ps, bool reg, bool f=true) : Bevande(ps,reg), filtro(f){}

double Tisana::calcolaPrezzo(){
    double p= getPeso()*pTisana;
    if(getTipoConf()){
        if(filtro)
            p +=(getPeso()*prezzofiltro)+getPrezzoConReg();
        else
            p +=getPrezzoConReg();
    }
    else {
        if(filtro)
            p +=(getPeso()*prezzofiltro);

    }
    setPrezzo(p);

    return p;
}

std::string Tisana::stampa() const{
    std::ostringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostringstream& operator<<(std::ostringstream& os,const Tisana& m){
    os.precision(2);
    if (m.filtro){
        if(m.getTipoConf())
            os<<"Tisana ("<<std::fixed<<m.getPeso()<<" gr), con filtro, conf. regalo: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
        else
            os<<"Tisana ("<<std::fixed<<m.getPeso()<<" gr), con filtro: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    else{
        if(m.getTipoConf())
            os<<"Tisana ("<<std::fixed<<m.getPeso()<<" gr), conf. regalo: "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
        else
            os<<"Tisana ("<<std::fixed<<m.getPeso()<<" gr): "<<std::fixed<<m.getPrezzo()<<" euro"<<std::endl;
    }
    return os;
}
