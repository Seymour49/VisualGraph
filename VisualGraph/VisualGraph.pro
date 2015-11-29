#-------------------------------------------------
#
# Project created by QtCreator 2015-11-17T11:51:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisualGraph
TEMPLATE = app

DEPENDPATH += . model
INCLUDEPATH += . model

SOURCES += main.cpp\
    model/sommetMat.cpp \
    model/graphemat.cpp \
    model/sommetlist.cpp \
    model/graphelist.cpp \
    view/loadgraphe.cpp \
    view/showgraph.cpp \
    controller/algographemat.cpp

HEADERS += model/sommetMat.h \
    model/graphemat.h \
    model/sommetlist.h \
    model/graphelist.h \
    view/loadgraphe.h \
    view/showgraph.h \
    controller/algographemat.h

FORMS    += view/loadgraphe.ui \
    view/showgraph.ui
