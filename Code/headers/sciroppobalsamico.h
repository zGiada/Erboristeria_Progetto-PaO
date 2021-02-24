#ifndef SCIROPPOBALSAMICO_H
#define SCIROPPOBALSAMICO_H
#include <iostream>
#include <sstream>
#include "fluidi.h"

class SciroppoBalsamico : public Fluidi{
    friend std::ostringstream& operator<<(std::ostringstream&,const SciroppoBalsamico&);

    private:
        static double prezzoScirop;

public:
        /**
         * @brief SciroppoBalsamico costruttore
         */
        SciroppoBalsamico(double, bool);
        /**
         * @brief calcolaPrezzo restituisce il prezzo dello sciroppo balsamico in base al peso
         * @return
         */
        virtual double calcolaPrezzo ();
        virtual std::string stampa() const;
};
#endif // SCIROPPOBALSAMICO_H
