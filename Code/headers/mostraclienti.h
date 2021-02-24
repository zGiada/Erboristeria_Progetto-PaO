#ifndef MOSTRACLIENTI_H
#define MOSTRACLIENTI_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QStyle>
#include <QToolBar>
#include <QString>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QBoxLayout>
#include <QLabel>
#include <QHeaderView>
#include <QSharedPointer> //vediamo se serve
#include <QMessageBox>
#include "clientela.h"

class mostraClienti : public QMainWindow
{
    Q_OBJECT
private:
    QTreeWidget * tabella;
    std::vector<QTreeWidgetItem*> itemVect;
    void resizeEvent (QResizeEvent* ) override;
    Clientela * cl;
    void updatePunti (Clientela * c);
    static void resizeClienti (QTreeWidget* tr);
    void aggiornaTabella ();
public:
    explicit mostraClienti( Clientela*, QWidget *parent = nullptr);

signals:
    void goHomeSignal();

public slots:
    void aggiornaPuntiSlot ();

};

#endif // MOSTRACLIENTI_H
