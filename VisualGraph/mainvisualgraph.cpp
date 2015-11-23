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


void MainVisualGraph::setFileDirectory(QString filename){
    ui->filenameLineEdit->setText(filename);
}

void MainVisualGraph::launchProcess(){
    GrapheMat* g = new GrapheMat("Test");

    if(g->tryLoadFile(QString(ui->filenameLineEdit->text()).toStdString())){
        std::cout <<(*g) << std::endl;
    }
    else{
        std::cout << "Erreur de fichier" << std::endl;
    }
    delete(g);
}

bool MainVisualGraph::loadFile(){
    QFileDialog loader(this, "Ouverture d'une clique", "./");
    loader.setDirectory("../../VisualGraph/VisualGraph/model");

    loader.show();
    if (loader.exec()){
        setFileDirectory(loader.selectedFiles()[0]);
        return true;
    }
    else return false;
}
