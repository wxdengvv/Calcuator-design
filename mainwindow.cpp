#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include "Calculator.h"
#include "OperatorFactory.h"

//register Operator
map<QString, function<unique_ptr<Operator>()>> Factory::ms_operator;
REGISTRAR(Plus, "+");
REGISTRAR(Minus, "-");
REGISTRAR(Multiply, "*");
REGISTRAR(Divide, "/");
REGISTRAR(Equal, "=");
REGISTRAR(Power, "^");
REGISTRAR(Left, "(");
REGISTRAR(Right, ")");
REGISTRAR(Sin, "sin");
REGISTRAR(Cos, "cos");
REGISTRAR(Tan, "tan");
REGISTRAR(Ln, "ln");
REGISTRAR(Factorial, "!")
REGISTRAR(SquareRoot, "sqrt")

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("WD's Calculator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_One_clicked()
{
    a += "1";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Two_clicked()
{
    a += "2";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Three_clicked()
{
    a += "3";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Four_clicked()
{
    a += "4";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Five_clicked()
{
    a += "5";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Six_clicked()
{
    a += "6";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Seven_clicked()
{
    a += "7";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Eight_clicked()
{
    a += "8";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Nine_clicked()
{
    a += "9";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Zero_clicked()
{
    string t = "0";
    t += a.toStdString();
    if ((t.back() >= '0' && t.back() <= '9') || t.back() == '.') {
        a += "0";
    }                                                             //no redundent 0s in front
    else {
        a.left(a.size() - 1)
    };
    if (a == "0") a.clear();
    ui->lineEdit->setText(a);
}

void MainWindow::on_Dot_clicked()
{
    string t = "0";
    t += a.toStdString();
    if (t.back() != '.') a += ".";
    ui->lineEdit->setText(a);
}

void MainWindow::on_pi_clicked()
{
    a += "pi";
    ui->lineEdit->setText(a);
}

void MainWindow::on_e_clicked()
{
    a += "e";
    ui->lineEdit->setText(a);
}

void MainWindow::on_tan_clicked()
{
    a += "tan";
    ui->lineEdit->setText(a);
}

void MainWindow::on_cos_clicked()
{
    a += "cos";
    ui->lineEdit->setText(a);
}

void MainWindow::on_sin_clicked()
{
    a += "sin";
    ui->lineEdit->setText(a);
}

void MainWindow::on_ln_clicked()
{
    a += "ln";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Power_clicked()
{
    a += "^";
    ui->lineEdit->setText(a);
}

void MainWindow::on_sqrt_clicked()
{
    a += "sqrt";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Factorial_clicked()
{
    a += "!";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Bracket_clicked()
{
    a += "(";
    ui->lineEdit->setText(a);
}

void MainWindow::on_RBracket_clicked()
{
    a += ")";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Clear_clicked()
{
    a.clear();
    ui->lineEdit->setText(a);
}

void MainWindow::on_Divide_clicked()
{
    a += "/";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Times_clicked()
{
    a += "*";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Backspace_clicked()     //delete operators
{
    string t1 = a.toStdString(), t2;
    char flag = 1;
    if (t1.size() == 0) flag = 0;
    while (flag != 0 && t1.back() >= 'a' && t1.back() <= 'z') {
        t2 += t1.back();
        t1.pop_back();
        if (t2 == "nis" || t2 == "soc" || t2 == "nat") { flag = 3; break; }
        else if (t2 == "ip" || t2 == "nl") { flag = 2; break; }
        else if (t2 == "trqs") { flag = 4; break; }
        else if (t2 == "e") break;
    }
    a = a.left(a.size() - flag);
    ui->lineEdit->setText(a);
}

void MainWindow::on_Minus_clicked()
{
    a += "-";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Plus_clicked()
{
    a += "+";
    ui->lineEdit->setText(a);
}

void MainWindow::on_Equal_clicked()
{
    Calculator Cal;
    try {
        a += "=";
        QString c, d = a;
        if (a == "=") { a.clear(); QApplication::beep(); return; }          //case: input is = directly
        exp = a.toStdString();
        int w = 10;                               //max numbers to keep after decimal
        c += QString::number(Cal.doIt(exp), 'g', w);
        exp = c.toStdString();                  //remove redundent 0s
        double flag1 = stod(exp);
        int flag2 = flag1;
        if (flag1 != flag2)
            while (exp.back() == '0' || exp.back() == '.') { c = c.left(c.size() - 1); exp.pop_back(); }
        else if (flag1 == flag2) c = c.left(c.size() - w - 1);
        if (c == "-0") c = "0";                      //case: -0
        d += c;
        ui->lineEdit->setText(d);
        a.clear();
    }
    catch (const char* str) {
        cerr << str << endl;
        ui->lineEdit->setText(str);
        a.clear();
        QApplication::beep();
    }
}

