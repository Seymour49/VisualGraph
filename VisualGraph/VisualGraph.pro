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
    model/algographemat.cpp \
    controller/loadgraphe.cpp \
    controller/showgraph.cpp

HEADERS += model/sommetMat.h \
    model/graphemat.h \
    model/sommetlist.h \
    model/graphelist.h \
    model/algographemat.h \
    controller/loadgraphe.h \
    controller/showgraph.h

FORMS    += view/loadgraphe.ui \
    view/showgraph.ui
