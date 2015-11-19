#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T11:51:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisualGraph
TEMPLATE = app


SOURCES += main.cpp\
        mainvisualgraph.cpp

HEADERS += model/sommet.h \
        model/grapheMat.h \
        mainvisualgraph.h

FORMS    += mainvisualgraph.ui
