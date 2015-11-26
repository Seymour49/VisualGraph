#ifndef SHOWGRAPH_H
#define SHOWGRAPH_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFrame>
#include <QtGui/QPainter>
#include <QResizeEvent>

#include "graphemat.h"

namespace Ui {
class ShowGraph;
}

class ShowGraph : public QMainWindow
{
    Q_OBJECT
private:
    GrapheMat const* graph;
    qreal scale;

    QPainter* bufferPainter;
    QImage* bufferPicture;

public:
    explicit ShowGraph(QWidget *parent = 0);
    virtual ~ShowGraph();

    void init(const GrapheMat *gm);
    void redraw();

    // Redéfinition de méthodes
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);

private:
    Ui::ShowGraph *ui;

};

#endif // SHOWGRAPH_H
