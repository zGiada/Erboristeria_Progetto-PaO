#ifndef INSERISCICLIENTE_H
#define INSERISCICLIENTE_H
#include "clientela.h"
#include <QMainWindow>
#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QToolBar>
#include <QApplication>
#include <QStyle>
#include <QVBoxLayout>
#include <QLabel>
#include "cliente.h"
#include <QMessageBox>


class InserisciCliente : public QMainWindow
{
    Q_OBJECT
private:
    Clientela * c;
    QLineEdit * nomeCliente;
    QPushButton * aggiungiCliente;

public:
    explicit InserisciCliente(Clientela* cl, QWidget *parent = nullptr);

signals:
     void goToHomeSIGNAL();
     void inseritoClienteSIGNAL();
     void aggiornaComboClienteSIGNAL();
private slots:
     /**
      * @brief nuovoClientePressed aggiunge un nuovo cliente a clientela e emette i segnali per aggiornare la combobox in inserisciordine e la lista in mostraclienti
      */
     void nuovoClientePressed();



};

#endif // INSERISCICLIENTE_H
