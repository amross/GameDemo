#-------------------------------------------------
#
# Project created by QtCreator 2018-09-08T10:22:45
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = CardMatch
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    main.cpp \
    card.cpp \
    deck.cpp \
    scorer.cpp \
    gameengine.cpp \
    Symbols/square.cpp \
    gamewindow.cpp \
    cardslot.cpp \
    Symbols/circle.cpp \
    Symbols/triangle.cpp \
    Symbols/coloredSymbol.cpp \
    Modifiers/add.cpp \
    Modifiers/multiply.cpp \
    Modifiers/negate.cpp \
    Modifiers/zero.cpp \
    Modifiers/wildcard.cpp

HEADERS += \
    card.h \
    deck.h \
    scorer.h \
    gameengine.h \
    Symbols/symbol.h \
    Symbols/square.h \
    gamewindow.h \
    cardslot.h \
    Symbols/circle.h \
    Symbols/triangle.h \
    Symbols/coloredSymbol.h \
    Modifiers/add.h \
    Modifiers/multiply.h \
    Modifiers/negate.h \
    Modifiers/zero.h \
    Modifiers/wildcard.h \
    Modifiers/modifysymbol.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Notes.txt
