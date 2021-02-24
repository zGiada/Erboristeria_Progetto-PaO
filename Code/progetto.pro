QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apistica.cpp \
    bevande.cpp \
    capsule.cpp \
    cliente.cpp \
    clientela.cpp \
    echinacea.cpp \
    fluidi.cpp \
    goccetranquillanti.cpp \
    inseriscicliente.cpp \
    integratori.cpp \
    lineate.cpp \
    main.cpp \
    miele.cpp \
    ordine.cpp \
    pappareale.cpp \
    prodotto.cpp \
    handler.cpp\
    propoli.cpp \
    sciroppobalsamico.cpp \
    tisana.cpp \
    mostraclienti.cpp\
    inserirsciordine.cpp\
    home.cpp\

HEADERS += \
    List.h \
    apistica.h \
    bevande.h \
    capsule.h \
    cliente.h \
    clientela.h \
    handler.h\
    echinacea.h \
    fluidi.h \
    goccetranquillanti.h \
    inseriscicliente.h \
    integratori.h \
    lineate.h \
    miele.h \
    ordine.h \
    pappareale.h \
    prodotto.h \
    propoli.h \
    sciroppobalsamico.h \
    mostraclienti.h\
    inserirsciordine.h\
    tisana.h \
    home.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
