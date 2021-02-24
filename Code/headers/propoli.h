#ifndef PROPOLI_H
#define PROPOLI_H
#include <iostream>
#include <sstream>
#include "apistica.h"
#include "capsule.h"

class Propoli : public Apistica, public Capsule //derivazione a diamante
{
friend std::ostringstream& operator<<(std::ostringstream&,const Propoli&);
private:
    static double pPropoli;
    static double prezzoLavorP;
    bool naturale;
    static double pNaturale;
public:
    /**
     * @brief Propoli costruttore di propoli
     * @param ps        peso del prodotto
     * @param n         true sse la lavorazione del propoli è stata naturale
     * @param s         true sse è venduto in sacchetti
     */
    Propoli(double ps, bool n, bool s);

    /**
     * @brief calcolaLavorazione calcola quanto è costata la lavorazione del propoli.
     *                  se naturale==true il prezzo aumentera di pNaturale altrimenti resta invariato
     *
     */
    virtual double calcolaLavorazione();

    /**
     * @brief calcolaPrezzo calcola il prezzo totale del prodotto. Il valore calcolato viene salvato
     *                  nell'attributo prezzo tramite Prodotto::setPrezzo()
     */
    virtual double calcolaPrezzo();

    virtual std::string stampa() const;



};

#endif // PROPOLI_H
