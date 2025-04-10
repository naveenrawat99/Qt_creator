#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>
#include<QDebug>
#define display_1 Display

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
      preOperator = true;
      first=0;
      second=0;
       firstDecimal = false;
       operation=0;
      e=2.71828;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionStandard_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_actionScientific_triggered()
{
     ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_actionProgrammer_triggered()
{
     ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_Reverse_clicked()
{
   ui->display_1->setText(QString::number(1/ui->display_1->text().toFloat()));
}
void MainWindow::on_Square_clicked()
{
    ui->display_1->setText(QString::number(pow(ui->display_1->text().toFloat(),2)));
}
void MainWindow::on_Squarer_clicked()
{
    ui->display_1->setText(QString::number(pow(ui->display_1->text().toFloat(),0.5)));
}
void MainWindow::on_Percent_clicked()
{
    ui->display_1->setText(QString::number(ui->display_1->text().toFloat()/100));
}
void MainWindow::on_Division_clicked()
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
void MainWindow::on_Multi_clicked()
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
void MainWindow::on_Sub_clicked()
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
void MainWindow::on_Add_clicked()
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
void MainWindow::on_Equal_clicked()
{
   switch(operation)
   {
   case 0:
      // ui->display_1->setText(QString::number(first/100));

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
void MainWindow::on_Button0_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "0");

    if(!preOperator){
        second = second * 10 + 0;
        ui->display_1->setText(ui->display_1->text() + "0");
    }
}

void MainWindow::on_Button1_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "1");

   if(!preOperator){
       second = second * 10 + 1;
       ui->display_1->setText(ui->display_1->text() + "1");
   }
}
void MainWindow::on_Button2_clicked()
{
    if(preOperator)
   ui->display_1->setText(ui->display_1->text() + "2");

   if(!preOperator){
       second = second * 10 + 2;
       ui->display_1->setText(ui->display_1->text() + "2");
   }
}
void MainWindow::on_Button3_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "3");

    if(!preOperator){
        second = second * 10 + 3;
        ui->display_1->setText(ui->display_1->text() + "3");
    }
}
void MainWindow::on_Button4_clicked()
{
    if(preOperator)
   ui->display_1->setText(ui->display_1->text() + "4");

   if(!preOperator){
       second = second * 10 + 4;
       ui->display_1->setText(ui->display_1->text() + "4");
   }
}
void MainWindow::on_Button5_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "5");

    if(!preOperator){
        second = second * 10 + 5;
        ui->display_1->setText(ui->display_1->text() + "5");
    }
}

void MainWindow::on_Button6_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "6");

    if(!preOperator){
        second = second * 10 + 6;
        ui->display_1->setText(ui->display_1->text() + "6");
    }
}
void MainWindow::on_Button7_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "7");

    if(!preOperator){
        second = second * 10 + 7;
        ui->display_1->setText(ui->display_1->text() + "7");
    }
}
void MainWindow::on_Button8_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "8");

    if(!preOperator){
        second = second * 10 + 8;
        ui->display_1->setText(ui->display_1->text() + "8");
    }
}
void MainWindow::on_Button9_clicked()
{
    if(preOperator)
    ui->display_1->setText(ui->display_1->text() + "9");

    if(!preOperator){
        second = second * 10 + 9;
        ui->display_1->setText(ui->display_1->text() + "9");
    }
}
void MainWindow::on_Clear_clicked()
{
    ui->display_1->clear();
    first =0;
    second =0;
    preOperator = true;
}
void MainWindow::on_Signc_clicked()
{
    if(preOperator){
        float num = -(ui->display_1->text().toFloat());
        ui->display_1->setText(QString::number(num));
    }
}


//********** page2 ***********

void MainWindow::on_Sdivision_clicked()
{
    if(ui->Display2->text() == " ")
        return;
    if(preOperator){
        operation=1;
        first = ui->Display2->text().toFloat();
        preOperator = false;
        ui->Display2->setText(ui->Display2->text() + "/");
    }
}
void MainWindow::on_Smulti_clicked()
{
    if(ui->Display2->text() == " ")
        return;
    if(preOperator){
        operation=2;
        first = ui->Display2->text().toFloat();
        preOperator = false;
        ui->Display2->setText(ui->Display2->text() + "*");
    }
}
void MainWindow::on_Ssub_clicked()
{
    if(ui->Display2->text() == " ")
        return;
    if(preOperator){
        operation=3;
        first = ui->Display2->text().toFloat();
        preOperator = false;
        ui->Display2->setText(ui->Display2->text() + "-");
    }
}
void MainWindow::on_Sadd_clicked()
{
    if(ui->Display2->text() == " ")
        return;
    if(preOperator){
        operation=4;
        first = ui->Display2->text().toFloat();
        preOperator = false;
        ui->Display2->setText(ui->Display2->text() + "+");
    }
}
void MainWindow::on_Sequal_clicked()
{
   switch(operation)
   {
   case 0:
      // ui->display_1->setText(QString::number(first/100));

   case 1:
       ui->Display2->setText(QString::number(first/second));
       break;

   case 2:
       ui->Display2->setText(QString::number(first*second));
       break;

   case 3:
       ui->Display2->setText(QString::number(first-second));
       break;

   case 4:
       ui->Display2->setText(QString::number(first+second));
       break;
   case 5:
       ui->Display2->setText(QString::number(pow(first,second)));
       break;
   case 6:
       ui->Display2->setText(QString::number((int)first % (int)second));
       break;
   }

   first = ui->Display2->text().toFloat();
   preOperator = true;
   second =0;

}
void MainWindow::on_Sbutton0_clicked()
{
    if(preOperator)
    ui->Display2->setText(ui->Display2->text() + "0");

    if(!preOperator){
        second = second * 10 + 0;
        ui->Display2->setText(ui->Display2->text() + "0");
    }
}

void MainWindow::on_Sbutton1_clicked()
{
    if(preOperator)
    ui->Display2->setText(ui->Display2->text() + "1");

   if(!preOperator){
       second = second * 10 + 1;
       ui->Display2->setText(ui->Display2->text() + "1");
   }
}
void MainWindow::on_Sbutton2_clicked()
{
    if(preOperator)
   ui->Display2->setText(ui->Display2->text() + "2");

   if(!preOperator){
       second = second * 10 + 2;
       ui->Display2->setText(ui->Display2->text() + "2");
   }
}
void MainWindow::on_Sbutton3_clicked()
{
    if(preOperator)
    ui->Display2->setText(ui->Display2->text() + "3");

    if(!preOperator){
        second = second * 10 + 3;
        ui->Display2->setText(ui->Display2->text() + "3");
    }
}
void MainWindow::on_Sbutton4_clicked()
{
    if(preOperator)
   ui->Display2->setText(ui->Display2->text() + "4");

   if(!preOperator){
       second = second * 10 + 4;
       ui->Display2->setText(ui->Display2->text() + "4");
   }
}
void MainWindow::on_Sbutton5_clicked()
{
    if(preOperator)
    ui->Display2->setText(ui->Display2->text() + "5");

    if(!preOperator){
        second = second * 10 + 5;
        ui->Display2->setText(ui->Display2->text() + "5");
    }
}

void MainWindow::on_Sbutton6_clicked()
{
    if(preOperator)
    ui->Display2->setText(ui->Display2->text() + "6");

    if(!preOperator){
        second = second * 10 + 6;
        ui->Display2->setText(ui->Display2->text() + "6");
    }
}
void MainWindow::on_Sbutton7_clicked()
{
    if(preOperator)
    ui->Display2->setText(ui->Display2->text() + "7");

    if(!preOperator){
        second = second * 10 + 7;
        ui->Display2->setText(ui->Display2->text() + "7");
    }
}
void MainWindow::on_Sbutton8_clicked()
{
    if(preOperator)
    ui->Display2->setText(ui->Display2->text() + "8");

    if(!preOperator){
        second = second * 10 + 8;
        ui->Display2->setText(ui->Display2->text() + "8");
    }
}
void MainWindow::on_Sbutton9_clicked()
{
    if(preOperator)
    ui->Display2->setText(ui->Display2->text() + "9");

    if(!preOperator){
        second = second * 10 + 9;
        ui->Display2->setText(ui->Display2->text() + "9");
    }
}
void MainWindow::on_Sclear_clicked()
{
    ui->Display2->clear();
    first =0;
    second =0;
    preOperator = true;
}
void MainWindow::on_Ssignc_clicked()
{
    if(preOperator){
        float num = -(ui->Display2->text().toFloat());
        ui->Display2->setText(QString::number(num));
    }
}

void MainWindow::on_Sreverse_clicked()
{
   ui->Display2->setText(QString::number(1/ui->Display2->text().toFloat()));
}
void MainWindow::on_Ssquare_clicked()
{
    ui->Display2->setText(QString::number(pow(ui->Display2->text().toFloat(),2)));
}
void MainWindow::on_Ssquarer_clicked()
{
    ui->Display2->setText(QString::number(pow(ui->Display2->text().toFloat(),0.5)));
}


void MainWindow::on_Spow_clicked()
{
    if(ui->Display2->text() == " ")
        return;
    if(preOperator){
        operation=5;
        first = ui->Display2->text().toFloat();
        preOperator = false;
        ui->Display2->setText(ui->Display2->text() + "^");
}}




void MainWindow::on_Slog10_clicked()
{ ui->Display2->setText(QString::number(log10(ui->Display2->text().toFloat())));
     }


void MainWindow::on_Slog_clicked()
{
    ui->Display2->setText(QString::number(log(ui->Display2->text().toFloat())));
}


void MainWindow::on_Spow10_clicked()
{
    ui->Display2->setText(QString::number(pow(10,ui->Display2->text().toFloat())));
}


void MainWindow::on_Smod_clicked()
{
    if(ui->Display2->text().toFloat()<0)
        ui->Display2->setText(QString::number(ui->Display2->text().toFloat()*(-1)));
    else
        return;
}


void MainWindow::on_Sexp_clicked()
{
    ui->Display2->setText(QString::number(pow(e,ui->Display2->text().toFloat())));
}


void MainWindow::on_Se_clicked()
{
    ui->Display2->setText("2.718281");
}


void MainWindow::on_Spi_clicked()
{
     ui->Display2->setText(QString::number(3.141592*ui->Display2->text().toFloat()));
}


void MainWindow::on_Smodulus_clicked()
{
    if(ui->Display2->text() == " ")
        return;
    if(preOperator){
        operation=6;
        first = ui->Display2->text().toFloat();
        preOperator = false;
        ui->Display2->setText(ui->Display2->text() + "%");
}
}

void MainWindow::on_Sfact_clicked()
{int y=1;
    if(ui->Display2->text().toFloat()==0)
        ui->Display2->setText("1");
    for(int i=1;i<=ui->Display2->text().toInt();i++)
    {
    y*=i;
    }
     ui->Display2->setText(QString::number(y));
}


void MainWindow::on_Back_clicked()
{
    ui->display_1->setText(QString::number(ui->display_1->text().toInt()/10));

}
void MainWindow::on_Sback_clicked()
{
    ui->Display2->setText(QString::number(ui->Display2->text().toInt()/10));

}
void MainWindow::on_Pback_clicked()
{
    ui->Display3->setText(QString::number(ui->Display3->text().toInt()/10));

}
void MainWindow::on_Sdecimal_clicked()
{
    ui->Display2->setText(ui->Display2->text() + ".");
}
void MainWindow::on_Decimal_clicked()
{
     ui->display_1->setText(ui->display_1->text() + ".");
}

//******** page3 *********

void MainWindow::on_Ppercent_clicked()
{
    ui->Display3->setText(QString::number(ui->Display3->text().toFloat()/100));
}
void MainWindow::on_Pdivision_clicked()
{
    if(ui->Display3->text() == " ")
        return;
    if(preOperator){
        operation=1;
        first = ui->Display3->text().toFloat();
        preOperator = false;
        ui->Display3->setText(ui->Display3->text() + "/");
    }
}
void MainWindow::on_Pmulti_clicked()
{
    if(ui->Display3->text() == " ")
        return;
    if(preOperator){
        operation=2;
        first = ui->Display3->text().toFloat();
        preOperator = false;
        ui->Display3->setText(ui->Display3->text() + "*");
    }
}
void MainWindow::on_Psub_clicked()
{
    if(ui->Display3->text() == " ")
        return;
    if(preOperator){
        operation=3;
        first = ui->Display3->text().toFloat();
        preOperator = false;
        ui->Display3->setText(ui->Display3->text() + "-");
    }
}
void MainWindow::on_Padd_clicked()
{
    if(ui->Display3->text() == " ")
        return;
    if(preOperator){
        operation=4;
        first = ui->Display3->text().toFloat();
        preOperator = false;
        ui->Display3->setText(ui->Display3->text() + "+");
    }
}
void MainWindow::on_Pequal_clicked()
{
   switch(operation)
   {
   case 0:
      // ui->display_1->setText(QString::number(first/100));
   case 1:
       ui->Display3->setText(QString::number(first/second));
       break;
   case 2:
       ui->Display3->setText(QString::number(first*second));
       break;
   case 3:
       ui->Display3->setText(QString::number(first-second));
       break;
   case 4:
       ui->Display3->setText(QString::number(first+second));
       break;
   case 5:
       ui->Display3->setText(QString::number((int)first>>(int)second));
       break;
   case 6:
        ui->Display3->setText(QString::number((int)first<<(int)second));
       break;
   case 7:
       ui->Display3->setText(QString::number((int)first&(int)second));
       break;
   case 8:
       ui->Display3->setText(QString::number((int)first|(int)second));
       break;
   }

   first = ui->Display3->text().toFloat();
   preOperator = true;
   second =0;

}
void MainWindow::on_Pbutton0_clicked()
{
    if(preOperator)
    ui->Display3->setText(ui->Display3->text() + "0");

    if(!preOperator){
        second = second * 10 + 0;
        ui->Display3->setText(ui->Display3->text() + "0");
    }
}
void MainWindow::on_Pbutton1_clicked()
{
    if(preOperator)
    ui->Display3->setText(ui->Display3->text() + "1");

   if(!preOperator){
       second = second * 10 + 1;
       ui->Display3->setText(ui->Display3->text() + "1");
   }
}
void MainWindow::on_Pbutton2_clicked()
{
    if(preOperator)
   ui->Display3->setText(ui->Display3->text() + "2");

   if(!preOperator){
       second = second * 10 + 2;
       ui->Display3->setText(ui->Display3->text() + "2");
   }
}
void MainWindow::on_Pbutton3_clicked()
{
    if(preOperator)
    ui->Display3->setText(ui->Display3->text() + "3");

    if(!preOperator){
        second = second * 10 + 3;
        ui->Display3->setText(ui->Display3->text() + "3");
    }
}
void MainWindow::on_Pbutton4_clicked()
{
    if(preOperator)
   ui->Display3->setText(ui->Display3->text() + "4");

   if(!preOperator){
       second = second * 10 + 4;
       ui->Display3->setText(ui->Display3->text() + "4");
   }
}
void MainWindow::on_Pbutton5_clicked()
{
    if(preOperator)
    ui->Display3->setText(ui->Display3->text() + "5");

    if(!preOperator){
        second = second * 10 + 5;
        ui->Display3->setText(ui->Display3->text() + "5");
    }
}

void MainWindow::on_Pbutton6_clicked()
{
    if(preOperator)
    ui->Display3->setText(ui->Display3->text() + "6");

    if(!preOperator){
        second = second * 10 + 6;
        ui->Display3->setText(ui->Display3->text() + "6");
    }
}
void MainWindow::on_Pbutton7_clicked()
{
    if(preOperator)
    ui->Display3->setText(ui->Display3->text() + "7");

    if(!preOperator){
        second = second * 10 + 7;
        ui->Display3->setText(ui->Display3->text() + "7");
    }
}
void MainWindow::on_Pbutton8_clicked()
{
    if(preOperator)
    ui->Display3->setText(ui->Display3->text() + "8");

    if(!preOperator){
        second = second * 10 + 8;
        ui->Display3->setText(ui->Display3->text() + "8");
    }
}
void MainWindow::on_Pbutton9_clicked()
{
    if(preOperator)
    ui->Display3->setText(ui->Display3->text() + "9");

    if(!preOperator){
        second = second * 10 + 9;
        ui->Display3->setText(ui->Display3->text() + "9");
    }
}
void MainWindow::on_Pclear_clicked()
{
    ui->Display3->clear();
    first =0;
    second =0;
    preOperator = true;
}
void MainWindow::on_psignc_clicked()
{
    if(preOperator){
        float num = -(ui->Display3->text().toFloat());
        ui->Display3->setText(QString::number(num));
    }
}
void MainWindow::on_Pdecimal_clicked()
{
     ui->Display3->setText(ui->Display3->text() + ".");
}
void MainWindow::on_Pand_clicked()
{
    if(ui->Display3->text() == " ")
        return;
    if(preOperator){
        operation=7;
        first = ui->Display3->text().toFloat();
        preOperator = false;
        ui->Display3->setText(ui->Display3->text() + "&");
}
}
void MainWindow::on_Prsh_clicked()
{
    if(ui->Display3->text() == " ")
        return;
    if(preOperator){
        operation=5;
        first = ui->Display3->text().toFloat();
        preOperator = false;
        ui->Display3->setText(ui->Display3->text() + ">>");
}
}
void MainWindow::on_POR_clicked()
{
    if(ui->Display3->text() == " ")
        return;
    if(preOperator){
        operation=8;
        first = ui->Display3->text().toFloat();
        preOperator = false;
        ui->Display3->setText(ui->Display3->text() + "|");
}
}
void MainWindow::on_Plsh_clicked()
{
    if(ui->Display3->text() == " ")
        return;
    if(preOperator){
        operation=6;
        first = ui->Display3->text().toFloat();
        preOperator = false;
        ui->Display3->setText(ui->Display3->text() + "<<");
}}

