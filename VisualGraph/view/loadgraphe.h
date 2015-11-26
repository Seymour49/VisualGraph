#ifndef LOADGRAPH_H
#define LOADGRAPH_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFileDialog>

#include "./model/graphemat.h"
#include "showgraph.h"

namespace Ui {
class LoadGraph;
}

class LoadGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoadGraph(QWidget *parent = 0);
    ~LoadGraph();

private:
    Ui::LoadGraph *ui;

    void setFileDirectory(QString filename);

public slots:
    void launchProcess();
    bool loadFile();
};

#endif // LOADGRAPH_H
