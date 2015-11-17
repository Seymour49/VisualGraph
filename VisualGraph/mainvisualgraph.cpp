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
