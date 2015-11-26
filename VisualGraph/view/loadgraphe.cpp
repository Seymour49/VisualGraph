#include "loadgraphe.h"
#include "ui_loadgraphe.h"

#include <ostream>

using namespace std;

LoadGraph::LoadGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoadGraph)
{
    ui->setupUi(this);
    ui->grapheArea->hide();
    ui->graphicView_graphe->hide();
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
        ostringstream oss;
        oss <<(*g) << std::endl;
        ShowGraph* graph= new ShowGraph();
        graph->init(g);
        graph->show();
    }
    else{
        cout << "Erreur de fichier" << std::endl;
    }
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
