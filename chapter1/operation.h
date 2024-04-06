#pragma once

#include <string>

class Operation {
 public:
    Operation(double op1, double op2) {
        oper1 = op1;
        oper2 = op2;
    }

    virtual ~Operation() { }

    virtual double getResult() = 0;

    double getFirst() { return oper1; }
    double getSecond() { return oper2; }
    void setFirst(double val) { oper1 = val; }
    void setSecond(double val) { oper2 = val; }

 private:
    double oper1;
    double oper2;
};


class OperationAdd : public Operation {
 public:
    OperationAdd(double a, double b) 
        : Operation(a, b) { }

    virtual double getResult() override {
        return getFirst() + getSecond();
    }
};

class OperationSub : public Operation {
 public:
    OperationSub(double a, double b) 
        : Operation(a, b) { }

    virtual double getResult() override {
        return getFirst() - getSecond();
    }
};