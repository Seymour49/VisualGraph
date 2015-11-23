#include "loadgraphe.h"
#include "ui_loadgraphe.h"

LoadGraph::LoadGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadGraph)
{
    ui->setupUi(this);
}

LoadGraph::~LoadGraph()
{
    delete ui;
}


void LoadGraph::setFileDirectory(QString filename){
    ui->filenameLineEdit->setText(filename);
}

void LoadGraph::launchProcess(){
    GrapheMat* g = new GrapheMat("Test");

    if(g->tryLoadFile(QString(ui->filenameLineEdit->text()).toStdString())){
        std::cout <<(*g) << std::endl;
    }
    else{
        std::cout << "Erreur de fichier" << std::endl;
    }
    delete(g);
}

bool LoadGraph::loadFile(){
    QFileDialog loader(this, "Ouverture d'une clique", "./");
    loader.setDirectory("../../VisualGraph/VisualGraph/model");

    loader.show();
    if (loader.exec()){
        setFileDirectory(loader.selectedFiles()[0]);
        return true;
    }
    else return false;
}
