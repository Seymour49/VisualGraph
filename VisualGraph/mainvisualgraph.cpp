#include "mainvisualgraph.h"
#include "ui_mainvisualgraph.h"

MainVisualGraph::MainVisualGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainVisualGraph)
{
    ui->setupUi(this);
}

MainVisualGraph::~MainVisualGraph()
{
    delete ui;
}

void MainVisualGraph::launchProcess(){

    GrapheMat* g = new GrapheMat("Test");

    if(g->tryLoadFile("dummy.txt")){
        cout <<(*g) << endl;
    }
    else{
        cout << "Erreur de fichier" << endl;
    }
    delete(g);
}
