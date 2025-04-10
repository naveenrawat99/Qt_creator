#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcustomplot.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//    struct Data
//    {
       double y1;
       double z1;
       double y2;
       double z2;
       double y3;
       double z3;
       int index;
 //   }first;

    void DoubleGraph(double, double);
    void SingleGraph(double);

private slots:
    void wavePlotting();

private:
    Ui::MainWindow *ui;
    QTimer dataTimer;
    QCustomPlot *customplot;
    QCPAxis *newAxis;
    int Count;

};
#endif // MAINWINDOW_H
