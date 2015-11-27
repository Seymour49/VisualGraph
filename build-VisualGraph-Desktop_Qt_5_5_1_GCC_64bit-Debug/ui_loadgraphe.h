/********************************************************************************
** Form generated from reading UI file 'loadgraphe.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADGRAPHE_H
#define UI_LOADGRAPHE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadGraph
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QPushButton *testBtn;
    QLabel *filenameLbl;
    QLineEdit *filenameLineEdit;
    QToolButton *toolButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoadGraph)
    {
        if (LoadGraph->objectName().isEmpty())
            LoadGraph->setObjectName(QStringLiteral("LoadGraph"));
        LoadGraph->resize(409, 228);
        actionQuit = new QAction(LoadGraph);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(LoadGraph);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        testBtn = new QPushButton(centralWidget);
        testBtn->setObjectName(QStringLiteral("testBtn"));
        testBtn->setGeometry(QRect(150, 110, 85, 27));
        filenameLbl = new QLabel(centralWidget);
        filenameLbl->setObjectName(QStringLiteral("filenameLbl"));
        filenameLbl->setGeometry(QRect(120, 30, 151, 17));
        filenameLbl->setInputMethodHints(Qt::ImhNone);
        filenameLbl->setFrameShape(QFrame::Box);
        filenameLineEdit = new QLineEdit(centralWidget);
        filenameLineEdit->setObjectName(QStringLiteral("filenameLineEdit"));
        filenameLineEdit->setGeometry(QRect(120, 70, 151, 27));
        filenameLineEdit->setCursorPosition(0);
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(270, 70, 81, 27));
        LoadGraph->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoadGraph);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 409, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        LoadGraph->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoadGraph);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LoadGraph->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoadGraph);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LoadGraph->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(LoadGraph);
        QObject::connect(testBtn, SIGNAL(clicked()), LoadGraph, SLOT(launchProcess()));
        QObject::connect(toolButton, SIGNAL(clicked()), LoadGraph, SLOT(loadFile()));

        QMetaObject::connectSlotsByName(LoadGraph);
    } // setupUi

    void retranslateUi(QMainWindow *LoadGraph)
    {
        LoadGraph->setWindowTitle(QApplication::translate("LoadGraph", "Load a Graph", 0));
        actionQuit->setText(QApplication::translate("LoadGraph", "Quit", 0));
        testBtn->setText(QApplication::translate("LoadGraph", "Lancer", 0));
        filenameLbl->setText(QApplication::translate("LoadGraph", "Entrer le nom du fichier", 0));
        filenameLineEdit->setText(QString());
        toolButton->setText(QApplication::translate("LoadGraph", "Browse...", 0));
        menuFile->setTitle(QApplication::translate("LoadGraph", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class LoadGraph: public Ui_LoadGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADGRAPHE_H
