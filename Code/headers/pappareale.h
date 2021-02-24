#ifndef PAPPAREALE_H
#define PAPPAREALE_H
#include "apistica.h"
#include <iostream>
#include <sstream>

class PappaReale : public Apistica
{
    friend std::ostringstream& operator<<(std::ostringstream&,const PappaReale&);
private:
    static double pPappaReale;
    static double PrezzoLav;
public:
    /**
     * @brief PappaReale costruttore
     * @param ps        peso
     *
     */
    PappaReale(double ps);



    /**
     * @brief calcolaLavorazione calcola il prezzo di lavorazione
     */
    virtual double calcolaLavorazione() ;

    /**
     * @brief calcolaPrezzo calcola il prezzo totale del prodotto sommando anche il prezzo della lavorazione
     *                  e lo salva in prezzo tramite Prodotto::setPrezzo()
     */
    virtual double calcolaPrezzo();

    virtual std::string stampa() const;

};

#endif // PAPPAREALE_H
