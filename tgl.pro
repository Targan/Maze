#-------------------------------------------------
#
# Project created by QtCreator 2014-05-10T01:39:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tgl
TEMPLATE = app

QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg

SOURCES += main.cpp\
        mainwindow.cpp \
    gridscene.cpp \
    map.cpp \
    game.cpp \
    playeritem.cpp

HEADERS  += mainwindow.h \
    gridscene.h \
    map.h \
    game.h \
    playeritem.h \
    common.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    gen.py
