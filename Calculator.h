#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <memory>
#include "Operator.h"
#include "Stack.h"
#include <cmath>

class Calculator {
private:
    Stack<double> m_num;							// ����ջ
    Stack<unique_ptr<Operator>> m_opr;				// �����ջ
    double readNum(string::const_iterator& it); 	// ��ȡ������
    QString readOpr(string::const_iterator& it);    // ��ȡ��ĸ������
    bool isNum(string::const_iterator& c) {			// �ж��ַ��Ƿ�Ϊ����
        if ((*c == 'p' && *(c + 1) == 'i') || (*c == 'i' && *(c - 1) == 'p'))
            return true;
        if (*c == 'e') return true;
        return (*c >= '0' && *c <= '9') || *c == '.';
    }
    void calculate();
public:
    Calculator() { m_opr.push(make_unique<Hash>()); }
    double doIt(const string& exp);
};
#endif												// CALCULATOR_H

#pragma once
