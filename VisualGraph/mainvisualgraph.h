#ifndef MAINVISUALGRAPH_H
#define MAINVISUALGRAPH_H

#include <QMainWindow>

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
};

#endif // MAINVISUALGRAPH_H
