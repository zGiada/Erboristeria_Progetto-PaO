#ifndef GOCCETRANQUILLANTI_H
#define GOCCETRANQUILLANTI_H
#include "fluidi.h"
#include <iostream>
#include <sstream>
class GocceTranquillanti : public Fluidi
{
    friend std::ostringstream& operator<<(std::ostringstream&,const GocceTranquillanti&);

private:
    static double prezzogocce;

public:
    /**
     * @brief GocceTranquillanti
     * @param ps peso
     * @param con true->plastica false->vetro
     */
    GocceTranquillanti(double ps, bool con);
    /**
     * @brief calcolaPrezzo calcola il prezzo delle gocce tranquillanti
     * @return
     */
    virtual double calcolaPrezzo ();

    virtual std::string stampa() const;
};

#endif // GOCCETRANQUILLANTI_H
