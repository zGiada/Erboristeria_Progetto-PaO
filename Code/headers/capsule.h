#ifndef CAPSULE_H
#define CAPSULE_H

#include "integratori.h"
class Capsule : public Integratori
{
private:
    bool sacchetto;
    static double scontoSacchetto;
public:
    /**
     * @brief Capsule costruttore
     * @param ps peso
     * @param s true->è venduto in sacchetti, false->non è venduto in sacchetti
     */
    Capsule(double ps, bool s);
    /**
         * @brief getSacchetto
         * @return          ritorna il valore booleano di sacchetto
         */
    bool getSacchetto() const;
    /**
      * @brief getScontoSacchetto
         * @return          ritorna il valore dello scontoSacchetto
         */
     double getScontoSacchetto() const;
};

#endif // CAPSULE_H
