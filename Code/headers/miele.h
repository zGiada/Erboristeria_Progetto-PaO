#ifndef MIELE_H
#define MIELE_H
#include "apistica.h"
#include <iostream>
#include <sstream>

class Miele : public Apistica
{
    friend std::ostringstream& operator<<(std::ostringstream&,const Miele&);

private:
    static double pMiele;
    static double PrezzoLavorazione;
public:
    /**
     * @brief Miele costruttore
     * @param ps            peso del prodotto
     *
     */
    Miele(double ps);


    /**
     * @brief calcolaLavorazione calcola il prezzo per quanto riguarda la lavorazione
     */
    virtual double calcolaLavorazione();

    /**
     * @brief calcolaPrezzo calcola il prezzo totale del prodotto sommandoci il prezzo di lavorazione e lo
     *                  salva in prezzo tramite Prodotto::setPrezzo()
     */
    virtual double calcolaPrezzo();

    virtual std::string stampa() const;
};

#endif // MIELE_H
