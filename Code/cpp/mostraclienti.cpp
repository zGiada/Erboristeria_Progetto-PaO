#include "mostraclienti.h"

void mostraClienti::resizeEvent(QResizeEvent * event) {

    tabella->setColumnWidth(0, this->width()/10*6);
    tabella->setColumnWidth(1, this->width()/10*4);
    QMainWindow::resizeEvent(event);

}

void mostraClienti::resizeClienti(QTreeWidget *tr) {
    for (int i = 0; i<2; ++i) tr->resizeColumnToContents(i);
}
    //creo la tabella
void mostraClienti::updatePunti(Clientela *c)
{
    tabella=new QTreeWidget();
    tabella->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tabella->setColumnCount(2);
    QStringList nomeColonne;
    nomeColonne<<"Nome Cliente"<<"Punti";
    tabella->setHeaderLabels(nomeColonne);
    for (int i=0; i<2; ++i){
        tabella->headerItem()->setTextAlignment(i, Qt::AlignCenter);
    }
    tabella->header()->setSectionResizeMode(QHeaderView::Fixed);

    List<Cliente*> tmp = c->getClienti();
    QTreeWidgetItem * itm;
    //popolo tabella
    for (List<Cliente*>::Iterator it = tmp.begin(); it!=tmp.end(); ++it){
        itm = new QTreeWidgetItem(tabella);
        itemVect.push_back(itm);
        itm->setText(0,QString::fromStdString((*it)->getNome()));
        itm->setText(1,QString::number((*it)->getPunti()));
        for(int k=0; k<2; ++k) {
            itm->setTextAlignment(k,Qt::AlignCenter);
        }
        tabella->addTopLevelItem(itm);

    }
    tabella->setColumnWidth(0, this->width()/10*6);
    tabella->setColumnWidth(1, this->width()/10*4);

    setCentralWidget(tabella);


}


void mostraClienti::aggiornaTabella(){
    delete tabella;
    updatePunti(cl);


}
mostraClienti::mostraClienti(Clientela *c, QWidget *parent) : QMainWindow(parent),tabella(nullptr), cl(c)
{

    QToolBar * toolbar= addToolBar("mainBar");
    //freccia per tornare alla home
    QIcon frecciaHome = QApplication::style()->standardIcon(QStyle::QStyle::SP_ArrowLeft);
    toolbar->setMovable(false); //non la faccio muovere
    QAction * freccia = toolbar->addAction(frecciaHome, "home");
    connect(freccia, SIGNAL (triggered()), this, SIGNAL (goHomeSignal()));
    aggiornaTabella();


}

void mostraClienti::aggiornaPuntiSlot(){

    itemVect.clear();

    aggiornaTabella();


}
