#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionScientefic_triggered();
    void on_actionStandard_triggered();
    void on_actionProgrammmer_triggered();

    void on_module_1_clicked();
    void on_reverse_PB1_clicked();
    void on_square_PB1_clicked();
    void on_root_PB1_clicked();
    void on_divide_PB1_clicked();
    void on_multi_PB1_clicked();
    void on_sub_PB1_clicked();
    void on_add_PB1_clicked();

    void on_zero_PB1_clicked();
    void on_one_PB1_clicked();
    void on_two_PB1_clicked();
    void on_three_PB1_clicked();
    void on_four_PB1_clicked();
    void on_five_PB1_clicked();
    void on_six_PB1_clicked();
    void on_seven_PB1_clicked();
    void on_eight_PB1_clicked();
    void on_nine_PB1_clicked();



    void on_decimal_PB1_clicked();

    void on_equal_PB1_clicked();


    void on_clear_PB_clicked();

    void on_minus_PB1_clicked();

private:
    Ui::MainWindow *ui;
    bool preOperator;
    bool firstDecimal;
    float first;
    float second;
    int operation;

};
#endif // MAINWINDOW_H
