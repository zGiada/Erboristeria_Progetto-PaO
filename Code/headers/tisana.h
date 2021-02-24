#ifndef TISANA_H
#define TISANA_H
#include "bevande.h"
#include <iostream>
#include <sstream>
class Tisana : public Bevande{
    friend std::ostringstream& operator<<(std::ostringstream&,const Tisana&);

    private:
        bool filtro;
        static double prezzofiltro;
        static double pTisana;
    public:
        Tisana(double,bool,bool);

        virtual double calcolaPrezzo();
        virtual std::string stampa() const;
};

#endif // TISANA_H
