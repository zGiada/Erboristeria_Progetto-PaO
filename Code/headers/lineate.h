#ifndef LINEATE_H
#define LINEATE_H
#include <iostream>
#include <sstream>
#include "bevande.h"
class LineaTe : public Bevande
{
    friend std::ostringstream& operator<<(std::ostringstream&,const LineaTe&);

private:
    bool aromatizzato;
    static double prezzoaromatizzato;
    static double prezzoTe;

public:
    /**
     * @brief LineaTe costruttore
     * @param ps peso
     * @param con confezione (regalo=true)
     * @param a aromatizzato (true->aromatizzato, false normale)
     */
    LineaTe(double ps ,bool con, bool a=false);
    /**
     * @brief calcolaPrezzo calcola il prezzo speso
     * @return prezzo
     */
    virtual double calcolaPrezzo();
    virtual std::string stampa() const;
};

#endif // LINEATE_H
