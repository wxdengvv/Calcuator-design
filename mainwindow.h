#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "Calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_One_clicked();

    void on_Two_clicked();

    void on_Three_clicked();

    void on_Four_clicked();

    void on_Five_clicked();

    void on_Six_clicked();

    void on_Seven_clicked();

    void on_Eight_clicked();

    void on_Nine_clicked();

    void on_Zero_clicked();

    void on_Dot_clicked();

    void on_pi_clicked();

    void on_e_clicked();

    void on_tan_clicked();

    void on_cos_clicked();

    void on_sin_clicked();

    void on_ln_clicked();

    void on_Power_clicked();

    void on_sqrt_clicked();

    void on_Factorial_clicked();

    void on_Bracket_clicked();

    void on_RBracket_clicked();

    void on_Clear_clicked();

    void on_Divide_clicked();

    void on_Times_clicked();

    void on_Backspace_clicked();

    void on_Minus_clicked();

    void on_Plus_clicked();

    void on_Equal_clicked();

private:
    Ui::MainWindow* ui;
    QString a, b;
    string exp;
};
#endif // MAINWINDOW_H
#pragma once
