#ifndef ECHINACEA_H
#define ECHINACEA_H
#include "capsule.h"
#include <iostream>
#include <sstream>

class Echinacea : public Capsule
{
friend std::ostringstream& operator<<(std::ostringstream&,const Echinacea&);
private:
    static double PEchinacea;
public:
    /**
     * @brief Echinacea costruttore
     * @param ps            peso
     * @param s             sacchetto, di default=false
     */
    Echinacea(double ps, bool s);
    /**
         * @brief calcolaPrezzo calcola il prezzo totale del prodotto e lo salva in Prodotto::
         *          se sacchetto==true prezzo*scontoSacchetto altrimenti prezzo*PEchinacea
         */
    virtual double calcolaPrezzo ();
    /**
     * @brief stampa: per stampare caratteristiche di echinacea
     * @return  stringa
     */
    virtual std::string stampa() const;

};

#endif // ECHINACEA_H
