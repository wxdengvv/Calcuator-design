#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

#include<QString>
#include<string>
#include<map>
#include<functional>
#include<memory>
#include"Operator.h"
// Object registeration
#define REGISTRAR(T, Key)  Factory::RegisterClass<T> reg_##T(Key);

using namespace std;

class Factory {
public:
    template<typename T>
    struct RegisterClass {
        RegisterClass(QString opr) {
            Factory::ms_operator.emplace(opr, [] {return make_unique<T>(); });
        }
    };

    static unique_ptr<Operator> create(QString opr) {
        auto it = ms_operator.find(opr);
        if (it != ms_operator.end())
            return it->second();
    }
    //private:
    static map<QString, function<unique_ptr<Operator>()>> ms_operator; //map: registered operation & pointer to constructor func
};
#endif // OPERATORFACTORY_H

#pragma once
