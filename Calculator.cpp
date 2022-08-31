#include "Calculator.h"
#include "OperatorFactory.h"

const static double pi = atan(1.0) * 4;
const static double e = 2.718281828459;
// read number to be operated
double Calculator::readNum(string::const_iterator& it) {
    string t;
    while (isNum(it)) {
        t += *it++;
        if (t == "pi") return pi;
        if (t == "e") return e;
        if (*(it - 1) > '0' && *(it - 1) < '9' && *it <= 'z' && *it >= 'a') throw "Missing operator!";
    }
    return stod(t);
}

QString Calculator::readOpr(string::const_iterator& it) {
    QString t;
    int f = 0;
    if (*it < 'a' || *it>'z') { f = 1; t = *it++; return t; }
    else
        while (*it >= 'a' && *it <= 'z') {
            t += *it++;
            if (t == "sin" || t == "cos" || t == "tan" || t == "sqrt" || t == "ln") {
                f = 1; return t;
            }                   //get operator then break
        }
    if (f == 0) throw "Unidentified operator!";
}
// calculate with top element from operator and number stacks
void Calculator::calculate() {
    // get number from stack and pass to Opearor for calculation
    double a[2] = { 0 };
    for (auto i = 0; i < m_opr.top()->numOprand(); ++i) {
        a[i] = m_num.top();
        m_num.pop();
    }
    m_num.push(m_opr.top()->get(a[1], a[0]));
    m_opr.pop();
}

double Calculator::doIt(const string& exp) {
    string t;
    for (auto it = exp.begin(); it != exp.end();) {
        // push if it's number
        if (isNum(it))
            m_num.push(readNum(it));
        else {  // push or calculate if it's operator
                // change string from readOpr to Operator
            if (it == exp.begin() && *it == '-')
                m_num.push(0);
            auto oo = Factory::create(readOpr(it));
            // calculation higher than read operation
            while (oo->precedence() <= m_opr.top()->precedence()) {
                if (m_opr.top()->symbol() == "#" || m_opr.top()->symbol() == "(")
                    break;
                calculate();
            }
            // not push "="
            if (oo->symbol() == "(" && *it == '-')
                m_num.push(0);
            if (oo->symbol() == ")" && m_opr.top()->symbol() == '(')
                m_opr.pop();
            if (oo->symbol() != "=" && oo->symbol() != ')')
                m_opr.push(std::move(oo));
        }
    }
    double result = m_num.top();
    m_num.pop();
    return result;
}