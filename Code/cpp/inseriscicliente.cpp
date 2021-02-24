#include "inseriscicliente.h"

InserisciCliente::InserisciCliente(Clientela *cl, QWidget *parent):QMainWindow(parent), c(cl)
{
    QToolBar* toolbar = addToolBar("mainToolBar");
    QIcon tornaIndietro = QApplication::style()->standardIcon(QStyle::SP_ArrowLeft);
    toolbar->setMovable(false);
    QAction* back = toolbar->addAction(tornaIndietro, "home");
    connect(back, SIGNAL(triggered()), this, SIGNAL(goToHomeSIGNAL()));
    QVBoxLayout *vLayout = new QVBoxLayout();
    QWidget *widgetGestore = new QWidget();
    vLayout->setAlignment(Qt::AlignCenter);
    widgetGestore->setLayout(vLayout);
    setCentralWidget(widgetGestore);
    QLabel * label = new QLabel("Inserire nome del cliente");
    label->setAlignment(Qt::AlignCenter);
    nomeCliente = new QLineEdit();
    nomeCliente->setMaximumWidth(200);
    aggiungiCliente = new QPushButton("Aggiungi");
    aggiungiCliente->setMaximumWidth(100);
    vLayout->addStretch();
    vLayout->addWidget(label);
    vLayout->addWidget(nomeCliente);
    vLayout->addWidget(aggiungiCliente);
    vLayout->setAlignment(aggiungiCliente, Qt::AlignCenter);
    vLayout->addStretch();
    connect(aggiungiCliente, SIGNAL(pressed()), this, SLOT (nuovoClientePressed()));


}
void InserisciCliente::nuovoClientePressed(){
    std::string nome = nomeCliente->text().toStdString();
    Cliente * tmp = new Cliente(nome);
    c->nuovoCliente(tmp);
    emit inseritoClienteSIGNAL();
    emit aggiornaComboClienteSIGNAL();
    QMessageBox * m = new QMessageBox();
    m->setText("Cliente Inserito");
    QPushButton *okButton = m->addButton("OK",QMessageBox::ActionRole);
    connect(okButton, SIGNAL(pressed()), this, SIGNAL(goToHomeSIGNAL()));
    m->exec();
    nomeCliente->clear();

}


