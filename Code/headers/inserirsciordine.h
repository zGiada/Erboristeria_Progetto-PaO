#ifndef INSERIRSCIORDINE_H
#define INSERIRSCIORDINE_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QStyle>
#include <QToolBar>
#include <QGridLayout>
#include <QComboBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QSpacerItem>
#include <QPushButton>
#include <QCheckBox>
#include <QMessageBox>
#include <QPlainTextEdit>

#include "clientela.h"
#include "echinacea.h"
#include "goccetranquillanti.h"
#include "prodotto.h"
#include "sciroppobalsamico.h"
#include "propoli.h"
#include "miele.h"
#include "pappareale.h"
#include "lineate.h"
#include "tisana.h"



class InserirsciOrdine : public QMainWindow
{
    Q_OBJECT
private:
    Clientela* cl;
    Ordine* listaOrdine;

    static QString PLASTICA;
    static QString VETRO;

    QComboBox *listaClienti;

    QDoubleSpinBox *peso;

    QRadioButton *pappareale;
    QRadioButton *propoli;
    QRadioButton *miele;
    QRadioButton *echinacea;
    QRadioButton *sciroppobals;
    QRadioButton *goccetranq;
    QRadioButton *lineate;
    QRadioButton *tisana;

    QCheckBox *naturale;            //propoli
    QCheckBox *sacchetto;           //integratori-capsule
    QComboBox *confPlasticaVetro;   //integratori-fluidi
    QCheckBox *confezioneRegalo;    //bevande
    QCheckBox *filtro;              //bevande-tisana
    QCheckBox *aromatizzato;        //bevande-lineate

    QPlainTextEdit *fattura;

    /**
     * @brief getNomeCliente scorrre tutti i clienti per salvare in un vettore di QString i nomi di tutti i clienti
     * @return nomi dei clienti dell'erboristeria
     */
    std::vector<QString> getNomeCliente() const;
    /**
     * @brief popolaComboClienti popola la combobox con i nomi di tutti i clienti
     * @param comboBox
     */
    void popolaComboClienti(QComboBox *comboBox) const;
    /**
     * @brief nuovoProdotto in base alle scelte fatte ritorna un puntatore a un nuovo prodotto
     * @return puntatore a Prodotto
     */
    Prodotto *nuovoProdotto() const;
    /**
     * @brief Reset resetta tutti i campi
     */
    void Reset();
    //pulsanti
    QPushButton *aggiungiButton;
    QPushButton *calcolaButton;
public:
    explicit InserirsciOrdine(Clientela* c, QWidget *parent = nullptr);

signals:
    void goToHomeSIGNAL();
    void inseritoOrdineSignal();

private slots:
    /**
     * @brief AggiungiPressed: se non è selezionato il peso->message box di errore
     *                         altrimenti creo un nuovo prodotto che salvo nell'ordine listaOrdine, lo stampo nella fattura,
     *                         fisso la combobox dei clienti e resetto i campi
     */
    void AggiungiPressed();
    /**
     * @brief CalcolaPressed:
     * calcolo il totale dell'ordine
     * aggiungo al cliente l'ordine
     * aggiorno i punti del cliente
     * stampo nella fattura il resoconto
     * emetto il segnale per far aggiornare la lista clienti
     */
    void CalcolaPressed();
    /**
     * @brief goHomePressed torna alla schermata home
     */
    void goHomePressed();

public slots:
    void aggiornaComboSLOT();
};

#endif // INSERIRSCIORDINE_H
