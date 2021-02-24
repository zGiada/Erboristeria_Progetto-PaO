#include "home.h"

Home::Home(QWidget *parent) : QMainWindow(parent)
{
    //toolbar in alto
    QToolBar * BarUp = addToolBar("main toolbar");
    BarUp->setMovable(false);
    QHBoxLayout * barUpLayout = new QHBoxLayout();
    QLabel * titoloBarUp = new QLabel("Erboristeria"); //da cambiare
    QFont font = titoloBarUp->font();
    font.setPointSize(20);
    font.setBold(true);
    titoloBarUp->setFont(font);
    titoloBarUp->setAlignment(Qt::AlignCenter);
    barUpLayout->addWidget(titoloBarUp, Qt::AlignCenter);
    barUpLayout->setMargin(5);
    QWidget * tmp = new QWidget();
    tmp->setContentsMargins(20,10,20,10);
    tmp->setLayout(barUpLayout);
    tmp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    BarUp->addWidget(tmp);
    //bottoni
    QWidget * mainWidget = new QWidget ();
    QVBoxLayout * layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(20);
    layout->setContentsMargins(150,120,150,120);
    QPushButton * nuovoClienteButton = new QPushButton("Inserisci un nuovo cliente");
    QPushButton * nuovoOrdineButton = new QPushButton("Inserisci un nuovo ordine");
    QPushButton * listaClientiButton = new QPushButton("Mostra lista clienti");

    nuovoClienteButton->setMinimumSize(250,50);
    nuovoOrdineButton->setMinimumSize(250,50);
    listaClientiButton->setMinimumSize(250,50);

    //connessioni bottoni
    connect(nuovoClienteButton, SIGNAL (clicked()), this, SIGNAL (nuovoClienteButtonSignal()));
    connect(nuovoOrdineButton, SIGNAL (clicked()), this, SIGNAL (nuovoOrdineButtonSignal()));
    connect(listaClientiButton, SIGNAL (clicked()), this, SIGNAL (listaClientiButtonSignal()));

    //posizionamento
    layout->addWidget(nuovoClienteButton);
    layout->addWidget(nuovoOrdineButton);
    layout->addWidget(listaClientiButton);

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);



}
