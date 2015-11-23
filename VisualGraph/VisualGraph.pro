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
    mainvisualgraph.cpp \
    model/sommetMat.cpp \
    model/graphemat.cpp \
    model/sommetlist.cpp \
    model/graphelist.cpp

HEADERS += \
    mainvisualgraph.h \
    model/sommetMat.h \
    model/graphemat.h \
    model/sommetlist.h \
    model/graphelist.h

FORMS    += mainvisualgraph.ui
