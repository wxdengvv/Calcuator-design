#include "Operator.h"
#include<QtCore/qmath.h>

Operator::~Operator() {}

double Plus::get(double a, double b) const {
    return a + b;
}

double Minus::get(double a, double b) const {
    return a - b;
}

double Multiply::get(double a, double b) const {
    return a * b;
}

double Divide::get(double a, double b) const {
    return a / b;
}

double Sin::get(double a, double b) const {
    return sin(b);
}

double Cos::get(double a, double b) const {
    return cos(b);
}

double Tan::get(double a, double b) const {
    return tan(b);
}

double Ln::get(double a, double b) const {
    return qLn(b);
}

double Factorial::get(double a, double b) const {
    int c = b;
    if (c != b) throw "Must be an integer!";
    int t = 1;
    for (int i = 1; i <= b; ++i) t *= i;
    return t;
}

double SquareRoot::get(double a, double b) const {
    return sqrt(b);
}

double Power::get(double a, double b) const {
    return pow(a, b);
}

double Hash::get(double a, double b) const {
    return a;   // return itself
}

double Equal::get(double a, double b) const {
    return a;
}
