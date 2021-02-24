#ifndef APISTICA_H
#define APISTICA_H
#include "prodotto.h"

class Apistica : virtual public Prodotto
{
    private:
        double tempoLavorazione;

    public:
        /**
         * @brief Apistica costruttore a due parametri
         * @param ps            peso del prodotto
         * @param l             tempo di lavorazione
         */
        Apistica(double ps, double l);

        /**
         * @brief calcolaLavorazione calcola quanto è costato la lavorazione dei prodotti, metodo virtuale puro
         */
        virtual double calcolaLavorazione()=0;

        /**
         * @brief getTempoLavorazione restituisce il tempoLavorazione
         * @return tempoLavorazione
         */
        double getTempoLavorazione() const;

        /**
         * @brief getTotaleLavorazione restituisce il costo della lavorazione
         * @return totaleLavorazione
         */
        double getTotaleLavorazione () const;
};

#endif // APISTICA_H
