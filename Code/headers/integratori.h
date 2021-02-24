#ifndef INTEGRATORI_H
#define INTEGRATORI_H
#include "prodotto.h"

class Integratori : virtual public Prodotto
{
public:
    Integratori(double ps);
};

#endif // INTEGRATORI_H
