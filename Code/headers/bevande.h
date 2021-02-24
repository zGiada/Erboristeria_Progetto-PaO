#ifndef BEVANDE_H
#define BEVANDE_H
#include "prodotto.h"

class Bevande : public Prodotto
{
private:
    bool tipoConfezione; //true->confezione regalo
    static double prezzoConfReg;
public:
    /**
     * @brief Bevande costruttore
     * @param ps peso
     * @param conf confezione: true->confezione regalo, false->confezione normale (default confezione normale)
     */
    Bevande(double ps, bool conf);
    /**
     * @brief getTipoConf
     * @return ritorna true se la confezione è regalo, false se normale
     */
    bool getTipoConf() const;
    /**
     * @brief getPrezzoConReg
     * @return ritorna prezzoConfReg
     */
    double getPrezzoConReg () const;
};

#endif // BEVANDE_H
