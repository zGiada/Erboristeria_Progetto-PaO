#include "prodotto.h"
#include "handler.h"
#include "clientela.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Handler w;
    w.show();
    return a.exec();
}
