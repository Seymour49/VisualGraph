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

    if(g->tryLoadFile("../VisualGraph/model/testGraphe25.txt")){
        std::cout <<(*g) << std::endl;
    }
    else{
        std::cout << "Erreur de fichier" << std::endl;
    }
    delete(g);
}
