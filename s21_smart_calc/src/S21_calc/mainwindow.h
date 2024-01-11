#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
extern "C"{
    #include"../s21_calculator.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
     double  h, X;
    int N;

private slots:
    void digits_numbers();
    void func_numbers();
    void res_numbers();
    void AC_numbers();
    void on_pushButton_CE_clicked();
    void plot_numbers();

};
#endif // MAINWINDOW_H
