#ifndef HANDLER_H
#define HANDLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "home.h"
#include "clientela.h"
#include "inserirsciordine.h"
#include "mostraclienti.h"
#include "inseriscicliente.h"

class Handler : public QWidget
{
    Q_OBJECT
private:
    QStackedWidget *stackW;
    Clientela cl;
private slots:
    void HomeSlot();
    void inserisciClienteSlot();
    void inserisciOrdineSlot();
    void mostraClientiSlot();
public:
    Handler(QWidget *parent = nullptr);
    ~Handler();

};

#endif // HANDLER_H
