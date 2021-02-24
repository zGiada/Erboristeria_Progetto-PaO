#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QAction>
#include <QStyle>
#include <QToolBar>
#include <QLabel>

class Home : public QMainWindow
{
    Q_OBJECT
public:
    explicit Home(QWidget *parent = nullptr);

signals:
    void nuovoClienteButtonSignal () const;
    void nuovoOrdineButtonSignal () const;
    void listaClientiButtonSignal () const;


};

#endif // HOME_H
