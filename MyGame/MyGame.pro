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
    abstractunites.cpp \
    base.cpp \
    boardcomponent.cpp \
    command.cpp \
    creature.cpp \
    gameboard.cpp \
    gamefacade.cpp \
    landscapes.cpp \
    main.cpp \
    mainwindow.cpp \
    mediator.cpp \
    myitem.cpp \
    neutralobjectinterface.cpp \
    settings.cpp \
    specificunites.cpp \
    strategy.cpp \
    unitfactory.cpp \
    unitinterface.cpp \
    unitobserverinterface.cpp

HEADERS += \
    UnitAttributes.h \
    abstractunites.h \
    base.h \
    boardcomponent.h \
    command.h \
    creature.h \
    enum.h \
    gameboard.h \
    gamefacade.h \
    landscapes.h \
    mainwindow.h \
    mediator.h \
    myitem.h \
    neutralobjectinterface.h \
    settings.h \
    specificunites.h \
    strategy.h \
    unitfactory.h \
    unitinterface.h \
    unitobserverinterface.h

FORMS += \
    mainwindow.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsrc.qrc
