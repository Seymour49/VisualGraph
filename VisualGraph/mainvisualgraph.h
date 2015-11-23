#ifndef MAINVISUALGRAPH_H
#define MAINVISUALGRAPH_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFileDialog>

#include "./model/graphemat.h"

namespace Ui {
class MainVisualGraph;
}

class MainVisualGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainVisualGraph(QWidget *parent = 0);
    ~MainVisualGraph();

private:
    Ui::MainVisualGraph *ui;

    void setFileDirectory(QString filename);

public slots:
    void launchProcess();
    bool loadFile();
};

#endif // MAINVISUALGRAPH_H
