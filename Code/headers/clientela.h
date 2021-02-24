#ifndef CLIENTELA_H
#define CLIENTELA_H

#include "cliente.h"
#include "List.h"
class Clientela
{
private:
    List<Cliente*> clienti;
public:
    /**
     * @brief Clientela costruttore: inseriamo già alcuni clienti
     */
    Clientela();
    //distruttore profondo
    ~Clientela();
    /**
     * @brief getClienti ritorna la lista di tutti i clienti dell'erboristeria
     * @return clienti
     */
    List<Cliente *> getClienti () const;
    /**
     * @brief nuovoCliente aggiunge alla lista di clienti un nuovo cliente
     * @param c: cliente da aggiungere
     */
    void nuovoCliente(Cliente* c);
    /**
     * @brief aggiungiOrdine cerca nella lista dei clienti il cliente a cui si vuole aggiungere un ordine e lo si aggiunge
     * @param o: ordine da aggiungere
     * @param nome: nome del cliente da cercare
     */
    void aggiungiOrdine(Ordine* o, std::string nome);
    /**
     * @brief aggiornaCliente vengono aggiornati i punti del cliente in base alla spesa appena fatta
     * @param nome: nome del cliente da cercare
     * @param pz: spesa effettuata su cui calcolare i punti guadagnati
     */
    void aggiornaCliente(std::string nome, double pz);

};

#endif // CLIENTELA_H
