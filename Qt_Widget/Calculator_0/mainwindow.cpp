#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    preOperator = true;
    firstDecimal = false;
    first = 0;
    second = 0;
    ui->title_1->setText("Standard");
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionStandard_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->title_1->setText("Standard");
}

void MainWindow::on_actionScientefic_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->title_2->setText("Scientefic");
}


void MainWindow::on_actionProgrammmer_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->title_3->setText("Programmer");
}


void MainWindow::on_reverse_PB1_clicked()
{
    QString str = ui->display_1->text();
    float num = str.toFloat();
    float revnum = 1/num;
    QString data = QString::number(revnum);
    ui->display_1->setText(data);

  //  ui->display_1->setText(QString::number(1/ui->display_1->text().toFloat()));
}

void MainWindow::on_square_PB1_clicked()
{
    ui->display_1->setText(QString::number(pow(ui->display_1->text().toFloat(),2)));
}

void MainWindow::on_root_PB1_clicked()
{
    ui->display_1->setText(QString::number(pow(ui->display_1->text().toFloat(),0.5)));
}

void MainWindow::on_module_1_clicked()
{
    if(ui->display_1->text() == " ")
        return;
    operation =0;
    first = ui->display_1->text().toFloat();
    preOperator = false;
}

void MainWindow::on_divide_PB1_clicked()
{
    if(ui->display_1->text() == " ")
        return;
    if(preOperator){
        operation=1;
        first = ui->display_1->text().toFloat();
        preOperator = false;
        ui->display_1->setText(ui->display_1->text() + "/");
    }
}

void MainWindow::on_multi_PB1_clicked()
{
    if(ui->display_1->text() == " ")
        return;
    if(preOperator){
        operation=2;
        first = ui->display_1->text().toFloat();
        preOperator = false;
        ui->display_1->setText(ui->display_1->text() + "*");
    }
}

void MainWindow::on_sub_PB1_clicked()
{
    if(ui->display_1->text() == " ")
        return;
    if(preOperator){
        operation=3;
        first = ui->display_1->text().toFloat();
        preOperator = false;
        ui->display_1->setText(ui->display_1->text() + "-");
    }
}

void MainWindow::on_add_PB1_clicked()
{
    if(ui->display_1->text() == " ")
        return;
    if(preOperator){
        operation=4;
        first = ui->display_1->text().toFloat();
        preOperator = false;
        ui->display_1->setText(ui->display_1->text() + "+");
    }
}

void MainWindow::on_equal_PB1_clicked()
{
   switch(operation)
   {
   case 0:
      // ui->display_1->setText(QString::number(first % second));

   case 1:
       ui->display_1->setText(QString::number(first/second));
       break;

   case 2:
       ui->display_1->setText(QString::number(first*second));
       break;

   case 3:
       ui->display_1->setText(QString::number(first-second));
       break;

   case 4:
       ui->display_1->setText(QString::number(first+second));
       break;
   }

   first = ui->display_1->text().toFloat();
   preOperator = true;
   second =0;

}



void MainWindow::on_zero_PB1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "0");

    if(!preOperator){
        second = second * 10 + 0;
        ui->display_1->setText(ui->display_1->text() + "0");
    }
}

void MainWindow::on_one_PB1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "1");

   if(!preOperator){
       second = second * 10 + 1;
       ui->display_1->setText(ui->display_1->text() + "1");
   }
}

void MainWindow::on_two_PB1_clicked()
{
    if(preOperator)
   ui->display_1->setText(ui->display_1->text() + "2");

   if(!preOperator){
       second = second * 10 + 2;
       ui->display_1->setText(ui->display_1->text() + "2");
   }
}

void MainWindow::on_three_PB1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "3");

    if(!preOperator){
        second = second * 10 + 3;
        ui->display_1->setText(ui->display_1->text() + "3");
    }
}
void MainWindow::on_four_PB1_clicked()
{
    if(preOperator)
   ui->display_1->setText(ui->display_1->text() + "4");

   if(!preOperator){
       second = second * 10 + 4;
       ui->display_1->setText(ui->display_1->text() + "4");
   }
}

void MainWindow::on_five_PB1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "5");

    if(!preOperator){
        second = second * 10 + 5;
        ui->display_1->setText(ui->display_1->text() + "5");
    }
}

void MainWindow::on_six_PB1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "6");

    if(!preOperator){
        second = second * 10 + 6;
        ui->display_1->setText(ui->display_1->text() + "6");
    }
}


void MainWindow::on_seven_PB1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "7");

    if(!preOperator){
        second = second * 10 + 7;
        ui->display_1->setText(ui->display_1->text() + "7");
    }
}

void MainWindow::on_eight_PB1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "8");

    if(!preOperator){
        second = second * 10 + 8;
        ui->display_1->setText(ui->display_1->text() + "8");
    }
}

void MainWindow::on_nine_PB1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "9");

    if(!preOperator){
        second = second * 10 + 9;
        ui->display_1->setText(ui->display_1->text() + "9");
    }
}

void MainWindow::on_decimal_PB1_clicked()
{


    QString data = ui->display_1->text();
    float num = data.toFloat();

    qDebug()<<num;

}

void MainWindow::on_clear_PB_clicked()
{
    ui->display_1->clear();
    first =0;
    second =0;
    preOperator = true;
}

void MainWindow::on_minus_PB1_clicked()
{
    if(preOperator){
        float num = -(ui->display_1->text().toFloat());
        ui->display_1->setText(QString::number(num));
    }
}
