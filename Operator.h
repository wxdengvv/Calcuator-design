#ifndef OPERATOR_H
#define OPERATOR_H

#include<QString>
#include<string>
#include<cmath>
using namespace std;

class Operator {
public:
    Operator(QString c, int numOprd, int pre) :m_symbol(c), m_numOprand(numOprd), m_precedence(pre) { }
    QString symbol() const { return m_symbol; }
    int numOprand() const { return m_numOprand; }
    int precedence() const { return m_precedence; }
    virtual double get(double a, double b) const = 0;
    virtual ~Operator();
protected:
    const QString m_symbol;         // operator itself
    const int m_numOprand;          // number of operators
    const int m_precedence;
};

class Plus : public Operator {      // operator +
public:
    Plus() :Operator("+", 2, 3) {}
    double get(double a, double b) const;
};

class Minus :public Operator {      // operator -
public:
    Minus() :Operator("-", 2, 3) {}
    double get(double a, double b) const;
};

class Multiply :public Operator {   // operator *
public:
    Multiply() :Operator("*", 2, 4) {}
    double get(double a, double b) const;
};

class Divide :public Operator {     // operator /
public:
    Divide() :Operator("/", 2, 4) {}
    double get(double a, double b) const;
};

class Right : public Operator {     // operator )
public:
    Right() :Operator(")", 1, 2) {}
    double get(double a, double b) const {
        return a;
    }
};

class Left : public Operator {      // operator (
public:
    Left() :Operator("(", 1, 7) {}
    double get(double a, double b) const {
        return a;
    }
};

class Power :public Operator {      // operator ^
public:
    Power() :Operator("^", 2, 6) {}
    double get(double a, double b) const;
};

class Sin :public Operator {        // operator sin
public:
    Sin() :Operator("sin", 1, 5) {}
    double get(double a, double b) const;
};

class Cos :public Operator {        // operator cos
public:
    Cos() :Operator("cos", 1, 5) {}
    double get(double a, double b) const;
};

class Tan :public Operator {        // operator tan
public:
    Tan() :Operator("tan", 1, 5) {}
    double get(double a, double b) const;
};

class Ln :public Operator {         // operator ln
public:
    Ln() :Operator("ln", 1, 5) {}
    double get(double a, double b) const;
};

class Factorial :public Operator {  // operator !
public:
    Factorial() :Operator("!", 1, 5) {}
    double get(double a, double b) const;
};

class SquareRoot :public Operator {  // operator !
public:
    SquareRoot() :Operator("sqrt", 1, 5) {}
    double get(double a, double b) const;
};

class Hash :public Operator {       // operator #
public:
    Hash() :Operator("#", 1, 1) {}
    double get(double a, double b) const;
};

class Equal :public Operator {      // operator =
public:
    Equal() :Operator("=", 2, 0) {}
    double get(double a, double b) const;
};

#endif // OPERATOR_H

#pragma once
