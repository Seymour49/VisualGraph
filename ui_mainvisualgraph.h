/********************************************************************************
** Form generated from reading UI file 'mainvisualgraph.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVISUALGRAPH_H
#define UI_MAINVISUALGRAPH_H

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

class Ui_MainVisualGraph
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

    void setupUi(QMainWindow *MainVisualGraph)
    {
        if (MainVisualGraph->objectName().isEmpty())
            MainVisualGraph->setObjectName(QStringLiteral("MainVisualGraph"));
        MainVisualGraph->resize(409, 228);
        actionQuit = new QAction(MainVisualGraph);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainVisualGraph);
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
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(270, 70, 81, 27));
        MainVisualGraph->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainVisualGraph);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 409, 27));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainVisualGraph->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainVisualGraph);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainVisualGraph->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainVisualGraph);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainVisualGraph->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainVisualGraph);
        QObject::connect(testBtn, SIGNAL(clicked()), MainVisualGraph, SLOT(launchProcess()));
        QObject::connect(toolButton, SIGNAL(clicked()), MainVisualGraph, SLOT(loadFile()));

        QMetaObject::connectSlotsByName(MainVisualGraph);
    } // setupUi

    void retranslateUi(QMainWindow *MainVisualGraph)
    {
        MainVisualGraph->setWindowTitle(QApplication::translate("MainVisualGraph", "MainVisualGraph", 0));
        actionQuit->setText(QApplication::translate("MainVisualGraph", "Quit", 0));
        testBtn->setText(QApplication::translate("MainVisualGraph", "Lancer", 0));
        filenameLbl->setText(QApplication::translate("MainVisualGraph", "Entrer le nom du fichier", 0));
        filenameLineEdit->setText(QApplication::translate("MainVisualGraph", "Entrez le nom du fichier", 0));
        toolButton->setText(QApplication::translate("MainVisualGraph", "Browse...", 0));
        menuFile->setTitle(QApplication::translate("MainVisualGraph", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainVisualGraph: public Ui_MainVisualGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVISUALGRAPH_H
