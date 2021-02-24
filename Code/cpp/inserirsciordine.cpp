#include "inserirsciordine.h"
#include <iomanip>

QString InserirsciOrdine::PLASTICA = "Plastica";
QString InserirsciOrdine::VETRO = "Vetro";
int count = 0;
bool aggiunta = false;

std::vector<QString> InserirsciOrdine::getNomeCliente() const{
    List<Cliente*> lista = cl->getClienti();
    std::vector<QString> nomi;
    for(List<Cliente*>::Iterator it = lista.begin(); it != lista.end(); ++it){
        nomi.push_back(QString::fromStdString((*it)->getNome()));
    }
    std::sort(nomi.begin(), nomi.end());
    return nomi;
}

void InserirsciOrdine::popolaComboClienti(QComboBox *comboBox) const{
    std::vector<QString> nome(getNomeCliente());
    for(unsigned int c = 0; c< nome.size(); c++)
        comboBox->addItem(nome[c]);
}

Prodotto *InserirsciOrdine::nuovoProdotto() const{
    if(miele->isChecked())
    {
        Miele * m = new Miele(peso->value());
        m->calcolaPrezzo();
        return m;
    }
    if(pappareale->isChecked()){
        PappaReale * p = new PappaReale(peso->value());
        p->calcolaPrezzo();
        return p;
    }
    if(propoli->isChecked()){
        Propoli * p = new Propoli(peso->value(),naturale->isChecked(),sacchetto->isChecked());
        p->calcolaPrezzo();
        return p;
    }

    if(echinacea->isChecked()){
        Echinacea * p = new Echinacea(peso->value(),sacchetto->isChecked());
        p->calcolaPrezzo();
        return p;
    }

    if(sciroppobals->isChecked()){
        if (confPlasticaVetro->currentText()==PLASTICA){
            SciroppoBalsamico * p = new SciroppoBalsamico(peso->value(),true);
            p->calcolaPrezzo();
            return p;
        }
        else{
            SciroppoBalsamico * p = new SciroppoBalsamico(peso->value(),false);
            p->calcolaPrezzo();
            return p;
        }
    }
    if(goccetranq->isChecked()){
        if (confPlasticaVetro->currentText()==PLASTICA){
            GocceTranquillanti * p = new GocceTranquillanti(peso->value(),true);
            p->calcolaPrezzo();
            return p;
        }
        else{
            GocceTranquillanti * p = new GocceTranquillanti(peso->value(),false);
            p->calcolaPrezzo();
            return p;
        }
    }
    if(tisana->isChecked()){
        if (confezioneRegalo->isChecked()){
            Tisana * p = new Tisana(peso->value(),confezioneRegalo->isChecked(),filtro->isChecked());
            p->calcolaPrezzo();
            return p;
        }
        else {
            Tisana * p = new Tisana(peso->value(),false,filtro->isChecked());
            p->calcolaPrezzo();
            return p;
        }
    }
    if(lineate->isChecked()){
        LineaTe * p = new LineaTe(peso->value(),confezioneRegalo->isChecked(),aromatizzato->isChecked());
        p->calcolaPrezzo();
        return p;
    }
    return nullptr;
}

void InserirsciOrdine::Reset(){
    peso->setValue(0);
    miele->setChecked(false);
    pappareale->setChecked(false);
    propoli->setChecked(false);
    echinacea->setChecked(false);
    sciroppobals->setChecked(false);
    goccetranq->setChecked(false);
    tisana->setChecked(false);
    lineate->setChecked(false);
    naturale->setChecked(false);
    sacchetto->setChecked(false);
    confezioneRegalo->setChecked(false);
    filtro->setChecked(false);
    aromatizzato->setChecked(false);
}

InserirsciOrdine::InserirsciOrdine(Clientela* c, QWidget *parent) : QMainWindow(parent), cl(c){
    listaOrdine = new Ordine();
    //*****************************************************************************
    //      TOOLBAR - COME BACK TO HOME
    //Tasto per tornare indietro
    QToolBar* toolbar = addToolBar("mainToolBar");
    QIcon tornaIndietro = QApplication::style()->standardIcon(QStyle::SP_ArrowLeft);
    toolbar->setMovable(false);
    QAction* back = toolbar->addAction(tornaIndietro, "home");
    connect(back, SIGNAL(triggered()), this, SLOT(goHomePressed()));

    QVBoxLayout *vLayout = new QVBoxLayout();
    QWidget *widgetGestore = new QWidget();
    widgetGestore->setLayout(vLayout);
    setCentralWidget(widgetGestore);
    //layout griglia
    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setSpacing(0);
    QWidget *mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    mainLayout->setColumnStretch(0,5);  //prima colonna
    mainLayout->setColumnStretch(1,1);
    mainLayout->setColumnStretch(2,5);  //terza colonna
    vLayout->addWidget(mainWidget);

    //GRID LAYOUT PER LA PRIMA COLONNA DEL GRID LAYOUT PRINCIPALE mainLayout
    QGridLayout *primacolonna = new QGridLayout();
    primacolonna->setSpacing(0);
    QWidget *primaColWidget = new QWidget();
    primaColWidget->setLayout(primacolonna);
    primacolonna->setColumnStretch(0,5);
    primacolonna->setColumnStretch(1,1);
    primacolonna->setColumnStretch(2,5);
    mainLayout->addWidget(primaColWidget,0,0);
        //prima colonna = radio button + peso + clienti

            //prima riga = clienti
            QWidget *sceltaCliente = new QWidget();
            QVBoxLayout *layoutCliente = new QVBoxLayout();
            sceltaCliente->setLayout(layoutCliente);
            listaClienti = new QComboBox();
            popolaComboClienti(listaClienti);
            layoutCliente->addWidget(listaClienti);
            layoutCliente->addStretch();
            primacolonna->addWidget(sceltaCliente,0,0);

            //seconda riga = peso
            QWidget *insPeso = new QWidget();
            QVBoxLayout *layoutPeso = new QVBoxLayout();
            QLabel* labelPeso = new QLabel("Peso: [gr]");
            insPeso->setLayout(layoutPeso);
            peso = new QDoubleSpinBox();
            peso->setSingleStep(5.00);
            peso->setRange(0, 2000);
            layoutPeso->addWidget(labelPeso);
            layoutPeso->addWidget(peso);
            layoutPeso->addStretch();
            primacolonna->addWidget(insPeso,1,0);

            //terza riga = radio button
            QWidget *listaRadio = new QWidget();
            QVBoxLayout *layoutRadio = new QVBoxLayout();
            listaRadio->setLayout(layoutRadio);
            miele = new QRadioButton("Miele");
            pappareale = new QRadioButton("Pappa reale");
            propoli = new QRadioButton("Propoli");
            echinacea = new QRadioButton("Echinacea");
            sciroppobals = new QRadioButton("Sciroppo balsamico");
            goccetranq = new QRadioButton("Gocce tranquillanti");
            tisana = new QRadioButton("Tisana");
            lineate = new QRadioButton("Linea te");
            layoutRadio->addWidget(miele);
            layoutRadio->addWidget(pappareale);
            layoutRadio->addWidget(propoli);
            layoutRadio->addWidget(echinacea);
            layoutRadio->addWidget(sciroppobals);
            layoutRadio->addWidget(goccetranq);
            layoutRadio->addWidget(tisana);
            layoutRadio->addWidget(lineate);
            layoutRadio->addStretch();
            primacolonna->addWidget(listaRadio,2,0);

            //quarta riga = bottone aggiungi
            QWidget *bottoneAggiungi = new QWidget();
            QVBoxLayout *layoutAggiungi= new QVBoxLayout();
            bottoneAggiungi->setLayout(layoutAggiungi);
            aggiungiButton = new QPushButton("Aggiungi prodotto");
            aggiungiButton->setMinimumWidth(100);
            layoutAggiungi->addSpacing(20);
            layoutAggiungi->setAlignment(aggiungiButton, Qt::AlignCenter);
            layoutAggiungi->addWidget(aggiungiButton);
            layoutAggiungi->addStretch();
            primacolonna->addWidget(bottoneAggiungi,3,0);
            connect(aggiungiButton, SIGNAL(clicked()), this, SLOT(AggiungiPressed()));

        //seconda colonna = spazio

        //terza colonna = checkbox
            //terza riga = scelte
            QWidget *listaScelte = new QWidget();
            QVBoxLayout *layoutScelte = new QVBoxLayout();
            listaScelte->setLayout(layoutScelte);
            QLabel *space1 = new QLabel(" ");
            QLabel *space2 = new QLabel(" ");
            naturale = new QCheckBox("Naturale");
            sacchetto = new QCheckBox("Sacchetto");
            QLabel *ConfVPL = new QLabel("Confezione (Vetro/Plastica):");
            confPlasticaVetro = new QComboBox();
            confPlasticaVetro->addItem(PLASTICA);
            confPlasticaVetro->addItem(VETRO);
            confezioneRegalo = new QCheckBox("Confezione regalo");
            filtro = new QCheckBox("Filtro");
            aromatizzato = new QCheckBox("Aromatizzato");
            layoutScelte->addWidget(space1);
            layoutScelte->setAlignment(space1, Qt::AlignCenter);
            layoutScelte->addWidget(space2);
            layoutScelte->setAlignment(space2, Qt::AlignCenter);
            layoutScelte->addWidget(naturale);
            layoutScelte->addWidget(sacchetto);
            layoutScelte->addWidget(ConfVPL);
            layoutScelte->setAlignment(ConfVPL, Qt::AlignCenter);
            layoutScelte->addWidget(confPlasticaVetro);
            layoutScelte->addWidget(confezioneRegalo);
            layoutScelte->addWidget(filtro);
            layoutScelte->addWidget(aromatizzato);
            layoutScelte->addStretch();
            primacolonna->addWidget(listaScelte,2,2);

            //quarta riga = bottone calcola
            QWidget *bottoneCalcola = new QWidget();
            QVBoxLayout *layoutCalcola= new QVBoxLayout();
            bottoneCalcola->setLayout(layoutCalcola);
            calcolaButton = new QPushButton("Calcola");
            calcolaButton->setMinimumWidth(100);
            layoutCalcola->addSpacing(20);
            layoutCalcola->setAlignment(calcolaButton, Qt::AlignCenter);
            layoutCalcola->addWidget(calcolaButton);
            layoutCalcola->addStretch();
            primacolonna->addWidget(bottoneCalcola,3,2);
            connect(calcolaButton, SIGNAL(clicked()), this, SLOT(CalcolaPressed()));

    //seconda colonna = spazio
    //terza colonna = fattura
            QGridLayout *terzacolonna = new QGridLayout();
            terzacolonna->setSpacing(0);
            QWidget *terzaColWidget = new QWidget();
            terzaColWidget->setLayout(terzacolonna);
            terzacolonna->setColumnStretch(0,1);
            terzacolonna->setColumnStretch(1,8);
            terzacolonna->setColumnStretch(2,1);
            mainLayout->addWidget(terzaColWidget,0,2);
            fattura = new QPlainTextEdit;
            fattura->setMinimumWidth(500);
            fattura->setReadOnly(true);
            terzacolonna->addWidget(fattura, 1, 1);


}

void InserirsciOrdine::AggiungiPressed(){
    if (peso->value()==0){
        QMessageBox m (QMessageBox::Warning,"Errore", "Selezionare un prodotto con un peso maggiore di 0", QMessageBox::Ok);
        m.exec();
    }
    else {
        count++;
        Prodotto* p = nuovoProdotto();
        listaOrdine->inserisciProdotto(p);
        fattura->appendPlainText(QString::fromStdString(p->stampa()));
        listaClienti->setEnabled(false);
        Reset();
    }
}

void InserirsciOrdine::CalcolaPressed(){
    if(count==0){
        QMessageBox m (QMessageBox::Warning,"Errore", "Inserire almeno un prodotto nell'ordine"
                                                      "\nSeleziona un prodotto e clicca su ''Aggiungi prodotto'' ", QMessageBox::Ok);
        m.exec();
    }
    else{
        aggiunta = true;
        std::string nome;
        //calcolo prezzo dell'ordine
        double pz = listaOrdine->calcolaTotale();

       //cerco il cliente
        nome = listaClienti->currentText().toStdString();
        cl->aggiungiOrdine(listaOrdine,nome);
        cl->aggiornaCliente(nome,pz);
        int punti= pz*0.8;

        fattura->appendPlainText("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"
                                 "Nome cliente: "+QString::fromStdString(nome)
                                 +"; \tProdotti: "+QString::number(count)
                                 +"; \n " + QString::fromStdString(listaOrdine->stampaTotali())
                                 +" \nPunti: "+QString::number(punti)

                                 );
        aggiungiButton->setEnabled(false);
        calcolaButton->setEnabled(false);
        emit inseritoOrdineSignal();
    }
}

void InserirsciOrdine::goHomePressed(){
    if(aggiunta){
        QMessageBox * m = new QMessageBox();
        m->setText("Ordine eseguito");//elaborato
        QPushButton *okButton = m->addButton("OK",QMessageBox::ActionRole);
        connect(okButton, SIGNAL(pressed()), this, SIGNAL(goToHomeSIGNAL()));
        m->exec();
        count = 0;
        aggiunta = false;


    }
    else{

        QMessageBox * m = new QMessageBox();
        m->setText("Ordine non eseguito");
        QPushButton *okButton = m->addButton("OK",QMessageBox::ActionRole);
        connect(okButton, SIGNAL(pressed()), this, SIGNAL(goToHomeSIGNAL()));
        m->exec();
    }
    //cancellare l'ordine
    fattura->clear();
    listaClienti->setEnabled(true);
    aggiungiButton->setEnabled(true);
    calcolaButton->setEnabled(true);

    listaOrdine = new Ordine(); //creo vuoto

}

void InserirsciOrdine::aggiornaComboSLOT()
{
    listaClienti->clear();
    popolaComboClienti(listaClienti);


}

