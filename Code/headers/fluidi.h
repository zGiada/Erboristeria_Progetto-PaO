#ifndef FLUIDI_H
#define FLUIDI_H
#include "integratori.h"

class Fluidi : public Integratori
{
private:
    bool confezionePlastica;
    static double prezzoPlastica;
    static double prezzoVetro;
public:
    /**
     * @brief Fluidi costruttore
     * @param ps peso
     * @param con true->plastica false->vetro
     */
    Fluidi(double ps, bool con);
    /**
     * @brief getConfF ritorna il tipo della confezione
     * @return true = plastica - false = vetro
     */
    bool getConfF() const;
    /**
     * @brief getPrezzoPlastica
     * @return prezzoPLastica
     */
    double getPrezzoPlastica() const;
    /**
     * @brief getPrezzoVetro
     * @return prezzoVetro
     */
    double getPrezzoVetro() const;
};

#endif // FLUIDI_H
