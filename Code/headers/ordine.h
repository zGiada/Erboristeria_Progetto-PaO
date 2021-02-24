#ifndef ORDINE_H
#define ORDINE_H

#include "List.h"
#include "prodotto.h"

#include <string>
#include <iostream>
#include <sstream>
class Ordine
{
private:
    friend std::ostringstream& operator<<(std::ostringstream& os,const Ordine& m);
    List<Prodotto*> prodotti;
    double saldo;

public:
    /**
     * @brief Ordine costruttore
     * @param s saldo
     */
    Ordine(double s=0);
    /**
      distruttore
      */
    ~Ordine ();
    /**
     * @brief calcolaTotale calcola il costo totale dell'ordine sommando il prezzo di ogni prodotto
     */
    double calcolaTotale ();
    /**
     * @brief addIva aggiunge l'iva al costo
     * @return prezzo ivato
     */
    double addIva() const;
    /**
     * @brief setSaldo setta il valore calcolato al saldo
     * @param p prezzo calcolato
     */
    void setSaldo(double p);
    /**
     * @brief getSaldo restituisce il saldo
     * @return saldo
     */
    double getSaldo() const;
    /**
     * @brief inserisciProdotto inserisce nella lista un nuovo prodotto passato per parametro
     */
    void inserisciProdotto(Prodotto*);
    std::string stampaTotali() const;


};

#endif // ORDINE_H
