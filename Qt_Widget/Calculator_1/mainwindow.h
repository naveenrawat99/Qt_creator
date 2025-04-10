#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionStandard_triggered();

    void on_actionScientific_triggered();

    void on_actionProgrammer_triggered();

    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button0_clicked();

    void on_Button3_clicked();

    void on_Button6_clicked();

    void on_Button5_clicked();

    void on_Button4_clicked();

    void on_Button9_clicked();

    void on_Button8_clicked();

    void on_Button7_clicked();

    void on_Reverse_clicked();

    void on_Square_clicked();

    void on_Squarer_clicked();

    void on_Division_clicked();

    void on_Multi_clicked();

    void on_Sub_clicked();

    void on_Add_clicked();

    void on_Equal_clicked();

    void on_Signc_clicked();

    void on_Clear_clicked();


    void on_Percent_clicked();

    void on_Sbutton7_clicked();

    void on_Sbutton8_clicked();

    void on_Sbutton9_clicked();

    void on_Sbutton4_clicked();

    void on_Sbutton5_clicked();

    void on_Sbutton6_clicked();

    void on_Sbutton1_clicked();

    void on_Sbutton2_clicked();

    void on_Sbutton3_clicked();

    void on_Sbutton0_clicked();

    void on_Ssignc_clicked();

    void on_Sequal_clicked();

    void on_Sadd_clicked();

    void on_Ssub_clicked();

    void on_Smulti_clicked();

    void on_Sdivision_clicked();

    void on_Ssquare_clicked();

    void on_Ssquarer_clicked();

    void on_Sreverse_clicked();

    void on_Sclear_clicked();

    void on_Spow_clicked();

    void on_Spow10_clicked();

    void on_Slog10_clicked();

    void on_Slog_clicked();

    void on_Smod_clicked();

    void on_Sexp_clicked();

    void on_Se_clicked();

    void on_Spi_clicked();

    void on_Smodulus_clicked();

    void on_Sfact_clicked();

    void on_Back_clicked();

    void on_Sback_clicked();

    void on_Sdecimal_clicked();

    void on_Decimal_clicked();

    void on_Pback_clicked();

    void on_Pbutton1_clicked();

    void on_Pbutton2_clicked();

    void on_Pbutton3_clicked();

    void on_psignc_clicked();

    void on_Pbutton0_clicked();

    void on_Pdecimal_clicked();

    void on_Pequal_clicked();

    void on_Padd_clicked();

    void on_Psub_clicked();

    void on_Pmulti_clicked();

    void on_Pdivision_clicked();

    void on_Pclear_clicked();

    void on_Prsh_clicked();

    void on_Plsh_clicked();

    void on_POR_clicked();

    void on_Ppercent_clicked();

    void on_Pbutton4_clicked();

    void on_Pbutton5_clicked();

    void on_Pbutton6_clicked();

    void on_Pbutton7_clicked();

    void on_Pbutton8_clicked();

    void on_Pbutton9_clicked();

    void on_Pand_clicked();

private:
    Ui::MainWindow *ui;
    bool preOperator;
    float first,second;
    bool  firstDecimal;
    int operation;
    float e;
};
#endif // MAINWINDOW_H
