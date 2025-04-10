#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Count = 0;
    y1 = 0;
    z1 =0;
    y2 =0;
    z2 =0;
    y3 =0;
    z3 =0;
    int index = 0;


    /*  ui->plot_1->setNotAntialiasedElements(QCP::aeAll);
        QFont font;
        font.setStyleStrategy(QFont::NoAntialias);
        // Configure x-Axis as time in secs
        QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
        timeTicker->setTimeFormat("%s");
        ui->plot_1->xAxis->setTicker(timeTicker);
        // Configure x and y-Axis to display Labels
        ui->plot_1->xAxis->setTickLabelFont(QFont(QFont().family(),6));
        ui->plot_1->yAxis->setTickLabelFont(QFont(QFont().family(),6));
        ui->plot_1->yAxis->setVisible(true);

        //add graph plot_1
        ui->plot_1->addGraph(); // blue line
        ui->plot_1->graph(0)->setPen(QPen(Qt::blue));
        ui->plot_1->graph(0)->setAntialiasedFill(false);
      */
// setting plot1

    ui->plot_1->setNotAntialiasedElements(QCP::aeAll);
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);

    ui->plot_1->yAxis->grid()->setPen(QPen(Qt::black));
    ui->plot_1->setNoAntialiasingOnDrag(true);

   // ui->plot_1->yAxis->setRange(-5.00,5.00);
    ui->plot_1->xAxis->setLabel("time");
    ui->plot_1->yAxis->setLabel("amplitude");
    ui->plot_1->addGraph();
    ui->plot_1->graph(0)->setPen(QPen(Qt::red));

    ui->plot_1->addGraph();
    ui->plot_1->graph(1)->setPen(QPen(Qt::blue));

// set the font of the scale
    QFont pfont;
    pfont.setStyleHint(QFont::Times);
    pfont.setPointSize(10);
    ui->plot_1->xAxis->setTickLabelFont(pfont);
    ui->plot_1->yAxis->setTickLabelFont(pfont);

//seting plot2
    ui->plot_2->setNotAntialiasedElements(QCP::aeAll);
    QFont Font;
    Font.setStyleStrategy(QFont::NoAntialias);

    ui->plot_2->yAxis->grid()->setPen(QPen(Qt::black));
    ui->plot_2->setNoAntialiasingOnDrag(true);

   // ui->plot_1->yAxis->setRange(-5.00,5.00);
    ui->plot_2->xAxis->setLabel("time");
    ui->plot_2->yAxis->setLabel("amplitude");
    ui->plot_2->addGraph();
    ui->plot_2->graph(0)->setPen(QPen(Qt::red));

    ui->plot_2->addGraph();
    ui->plot_2->graph(1)->setPen(QPen(Qt::blue));

// set the font of the scale
    QFont pFont;
    pfont.setStyleHint(QFont::Times);
    pfont.setPointSize(10);
    ui->plot_2->xAxis->setTickLabelFont(pFont);
    ui->plot_2->yAxis->setTickLabelFont(pFont);


    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(wavePlotting()));
  //  connect(&dataTimer, SIGNAL(timeout()), this, SLOT(SingleGraph(double)));

    dataTimer.start(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wavePlotting()
{  Count = 0;
   static int i=0;
   i++;
  y1 =2 ; // * sin(i*0.01744);
  z1 =4 ; //* cos(i*0.01744);
  y2 =6 ; //* sin(2*i*0.01744);
  z2 =8 ; //* sin(2*i*0.01744);
  y3 =10 ; //* sin(3*i*0.01744);
  z3 =12 ; //* cos(3*i*0.01744);


    QString current = ui->option2->currentText();

    for(int i=0;i<2;i++)
    {
     if(Count == 0)
      index = ui->option1->currentIndex();
    else if(Count == 1 )
      index = ui->option2->currentIndex();

    switch(index)
    {
    case 0:
        DoubleGraph(y1,z1);
        break;
    case 1:
        DoubleGraph(y2,z2);
        break;
    case 2:
        DoubleGraph(y3,z3);
        break;
    }
    Count++;
  }
}
void MainWindow::DoubleGraph(double y,double z )
{

    QString title = ui->option1->currentText();
    ui->plot_1->yAxis->setLabel(title);

    static QTime time(QTime::currentTime());
    double x = time.elapsed()/1000.0;

    if(Count == 0)
    {
    ui->plot_1->graph(0)->addData(x,y);
    ui->plot_1->graph(1)->addData(x,z);

    ui->plot_1->xAxis->setRange(x,10,Qt::AlignRight);
    ui->plot_1->yAxis->setRange(-10,10);

    ui->plot_1->graph(0)->rescaleValueAxis();
    ui->plot_1->graph(1)->rescaleValueAxis();
    ui->plot_1->replot();
    }
    if(Count == 1)
    {
    ui->plot_2->graph(0)->addData(x,y);
    ui->plot_2->graph(1)->addData(x,z);

    ui->plot_2->xAxis->setRange(x,10,Qt::AlignRight);
    ui->plot_2->yAxis->setRange(-10,10);

    ui->plot_2->graph(0)->rescaleValueAxis();
    ui->plot_2->graph(1)->rescaleValueAxis();
    ui->plot_2->replot();
    }
}



//void MainWindow::DoubleGraph(Data Local)
//{
//    double *pointer = &(Local.y1);

//    int index = ui->option1->currentIndex();

//    double y = *(pointer+index*2);
//    double z = *(pointer + index*2+1);

//    qDebug()<<y<<"....."<<z;

//    QString title = ui->option1->currentText();
//    ui->plot_1->yAxis->setLabel(title);

//    static QTime time(QTime::currentTime());
//    double x = time.elapsed()/1000.0;

//    ui->plot_1->graph(0)->addData(x,y);
//    ui->plot_1->graph(1)->addData(x,z);

//    ui->plot_1->xAxis->setRange(x,10,Qt::AlignRight);
//    ui->plot_1->yAxis->setRange(-10,10);

//    ui->plot_1->graph(0)->rescaleValueAxis();
//    ui->plot_1->graph(1)->rescaleValueAxis();
//    ui->plot_1->replot();

//}

void MainWindow::SingleGraph(double)
{
    static int i=0;

    static QTime time(QTime::currentTime());
    double key = time.elapsed()/1000.0;
    ui->plot_1->graph(0)->addData(key,4*sin(i*0.01744));
    ui->plot_1->xAxis->setRange(key,10,Qt::AlignRight);
    ui->plot_1->graph(0)->rescaleValueAxis();
    ui->plot_1->replot();
}



