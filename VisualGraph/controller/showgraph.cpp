#include "showgraph.h"
#include "ui_showgraph.h"

#include <QLabel>

using namespace std;

#include <iostream>
#include <QTableView>
#include <QTableWidgetItem>

ShowGraph::ShowGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowGraph)
{
    ui->setupUi(this);

    bufferPainter= new QPainter;
    bufferPicture= new QImage;
    scale= 1.0;
}

ShowGraph::~ShowGraph(){
    delete ui;

    delete bufferPainter;
    delete bufferPicture;

    delete graph;
}

void ShowGraph::init( const GrapheMat* gm)
{
    graph= gm;
}

#include <QTextItem>
void ShowGraph::redraw(){
    if (bufferPainter->isActive()){
        cout<< "buffer actif"<< endl;
    }
    else cout<< "buffer non actif"<< endl;

    if (!bufferPicture->isNull() || bufferPicture == NULL){
        delete(bufferPicture);
    }
    bufferPicture = new QImage(graph->getNbSommets()+1, graph->getNbSommets()+1, QImage::Format_ARGB32);

    if (bufferPainter->begin(bufferPicture)) cout << "Debut dessin redraw"<< endl;
    else cout << "Impossible dessiner redraw"<< endl;

    bufferPainter->fillRect(0,0, 1,1, QColor(Qt::black));
    for (int i= 1; i< graph->getNbSommets()+1; ++i){
        // diagonale peinte en gris
        bufferPainter->fillRect(i,i, 1,1, QColor(Qt::gray));
        // hauteur peinte en bleu
        bufferPainter->fillRect(0,i, 1,1, QColor(Qt::blue));
        // largeur peinte en vert
        bufferPainter->fillRect(i,0, 1,1, QColor(Qt::green));
    }

    for (int i= 1; i<= graph->getNbSommets()+1; ++i){
        for (int j= i+1; j<= graph->getNbSommets()+1; ++j){
            if (graph->at(i)->isArc(j)){
                bufferPainter->fillRect(i, j, 1, 1,QColor(Qt::red));
                bufferPainter->fillRect(j, i, 1, 1,QColor(Qt::yellow));
            }
            else{
                bufferPainter->fillRect(i, j, 1, 1,QColor(Qt::white));
                bufferPainter->fillRect(j, i, 1, 1,QColor(Qt::white));
            }
        }
    }
    bufferPainter->end();

    update();
}

void ShowGraph::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);
    QPainter paint(this);
    paint.scale(scale, scale);
    paint.drawImage(0, 0, *bufferPicture);
}

void ShowGraph::resizeEvent(QResizeEvent* event)
{
    #if PERF_RESIZE
    cout << "test resizeEvent firewidget"<< endl;
    #endif

    scale= min(event->size().width() / ((qreal)graph->getNbSommets()+1.0), event->size().height() / ((qreal)graph->getNbSommets()+1.0)) ;
//    cout<<"event->size().width()_ "<<event->size().width()<< " event->size().height()_ "<< event->size().height() << " scaling : "<< scale <<"(qreal)graph->getNbSommets() "<<(qreal)graph->getNbSommets() << endl;
    redraw();
}

#include <QDialog>
#include <QVBoxLayout>
void ShowGraph::showRes(GrapheMat* clique) const
{
    cout<< "================================"<< endl;
    cout<< "  La plus grande clique trouvée est de taille : "<< clique->size() +1<< endl;
    cout<< "================================"<< endl;
    ostringstream oss;
    oss << "La plus grande clique trouvée est de taille : " << clique->size() +1;
    QDialog* winRes= new QDialog();

    QVBoxLayout* lay = new QVBoxLayout(winRes);
    lay->addWidget(new QLabel(QString::fromStdString(oss.str())));

    winRes->show();
//    delete winRes;
}

void ShowGraph::startBronKerbosch() const
{
    GrapheMat* clique= algoGrapheMat::BronKerbosch(graph);
    showRes(clique);
}


void ShowGraph::startBronKerboschV2() const
{
    GrapheMat* clique= algoGrapheMat::BronKerboschV2(graph);
    showRes(clique);
}

void ShowGraph::startBronKerboschV2_bis() const
{
    GrapheMat* clique= algoGrapheMat::BronKerboschV2_bis(graph);
    showRes(clique);
}


void ShowGraph::startAlgoGrowing() const
{
    GrapheMat* clique= algoGrapheMat::AlgoGrowing(graph);
    showRes(clique);
}

void ShowGraph::startAlgoGrowingWithBK() const
{
    GrapheMat* clique= algoGrapheMat::AlgoGrowingWithBK(graph);
    showRes(clique);
}

void ShowGraph::startBKWithGrowing() const
{
    GrapheMat* clique= algoGrapheMat::BronKerboschWithGrowing(graph);
    showRes(clique);
}
