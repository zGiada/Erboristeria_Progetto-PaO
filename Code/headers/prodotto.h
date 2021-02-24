#ifndef PRODOTTO_H
#define PRODOTTO_H
#include <string>
class Prodotto
{
private:
    double peso;
    double prezzo;


public:
    /**
     * @brief Prodotto costruttore
     * @param ps peso
     */
    Prodotto(double ps);
    virtual ~Prodotto();
    /**
     * @brief calcolaPrezzo calcola e restituisce il prezzo di ogni prodotto
     * @return
     */
    virtual double calcolaPrezzo() = 0;
    /**
     * @brief getPeso
     * @return  peso
     */
    double getPeso() const;
    /**
     * @brief getPrezzo
     * @return  prezzo
     */
    double getPrezzo() const;
    /**
     * @brief setPrezzo prezzo=p
     * @param p
     */
    void setPrezzo(double p);
    /**
     * @brief stampa visualizza le caratteristiche del prodotto
     * @return stringa
     */
    virtual std::string stampa() const =0;

};
#endif // PRODOTTO_H
