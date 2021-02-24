#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "List.h"
#include "ordine.h"



class Cliente{
private:
    std::string nomeCliente;
    int punti;
    List<Ordine*> ordini;
public:
    /**
     * @brief Cliente costruttore
     * @param c nome del cliente
     * @param p punti
     */
    Cliente(std::string c, int p=0);
    ~Cliente();
    /**
     * @brief calcolaPunti calcola i punti il base alla spesa fatta e li setta in punti
     * @param prezzo: spesa effettuata
     *
     */
    void calcolaPunti (double prezzo) ;
    /**
     * @brief setPunti setta i punti
     * @param p
     */
    void setPunti (int p);
    /**
     * @brief getPunti ritorna i punti totali di un cliente
     * @return punti
     */
    int getPunti () const;
    /**
     * @brief getNome ritorna il nome del cliente
     * @return nomeCliente
     */
    std::string getNome() const;
    /**
     * @brief addOrdine inserisce un nuovo ordine all'interno della lista degli ordine di un cliente
     * @param o: ordine da inserire
     */
    void addOrdine(Ordine* o);

};


#endif // CLIENTE_H
