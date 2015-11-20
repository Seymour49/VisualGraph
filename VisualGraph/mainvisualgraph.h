#ifndef MAINVISUALGRAPH_H
#define MAINVISUALGRAPH_H

#include <QMainWindow>
#include "./model/grapheMat.h"

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

public slots:
    void launchProcess();
};

#endif // MAINVISUALGRAPH_H
