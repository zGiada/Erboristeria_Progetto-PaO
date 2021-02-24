#include "handler.h"

void Handler::HomeSlot(){stackW->setCurrentIndex(0);}
void Handler::inserisciClienteSlot(){stackW->setCurrentIndex(1);}
void Handler::inserisciOrdineSlot(){stackW->setCurrentIndex(2);}
void Handler::mostraClientiSlot(){stackW->setCurrentIndex(3);}



Handler::Handler(QWidget *parent) : QWidget(parent), stackW(new QStackedWidget()), cl(Clientela()){

    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout ->setMargin(0);
    QMainWindow * home = new Home();
    QMainWindow * inseriscicliente = new InserisciCliente(&cl);
    QMainWindow * inserisciordine = new InserirsciOrdine(&cl);
    QMainWindow * mostraclienti = new mostraClienti(&cl);

    //connect home
    connect(home, SIGNAL(nuovoClienteButtonSignal()), this, SLOT(inserisciClienteSlot()));
    connect(home, SIGNAL(nuovoOrdineButtonSignal()), this, SLOT(inserisciOrdineSlot()));
    connect(home, SIGNAL(listaClientiButtonSignal()), this, SLOT(mostraClientiSlot()));

    //connect inseriscicliente
    connect(inseriscicliente, SIGNAL(goToHomeSIGNAL()), this, SLOT(HomeSlot()));
    connect(inseriscicliente, SIGNAL(inseritoClienteSIGNAL()), mostraclienti, SLOT(aggiornaPuntiSlot()));
    connect(inseriscicliente, SIGNAL(aggiornaComboClienteSIGNAL()), inserisciordine, SLOT(aggiornaComboSLOT()));

    //connect inserisciordine
    connect(inserisciordine, SIGNAL(goToHomeSIGNAL()), this, SLOT(HomeSlot()));

    //connect listaclienti
    connect(mostraclienti, SIGNAL(goHomeSignal()), this, SLOT(HomeSlot()));
    connect(inserisciordine, SIGNAL(inseritoOrdineSignal()), mostraclienti, SLOT(aggiornaPuntiSlot()));

    //aggiungi a stackW
    stackW->addWidget(home);
    stackW->addWidget(inseriscicliente);
    stackW->addWidget(inserisciordine);
    stackW->addWidget(mostraclienti);

    mainLayout->addWidget(stackW);

    setLayout(mainLayout);


}

Handler::~Handler(){
    delete stackW;
}
