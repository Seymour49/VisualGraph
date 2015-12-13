#ifndef SHOWGRAPH_H
#define SHOWGRAPH_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFrame>
#include <QtGui/QPainter>
#include <QResizeEvent>

#include "../model/graphemat.h"
#include "../model/algographemat.h"

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

public slots:
    void startBronKerbosch() const;
    void startBronKerboschV2() const;
    void startBronKerboschV2_bis() const;

    void startAlgoGrowing() const;

};

#endif // SHOWGRAPH_H
