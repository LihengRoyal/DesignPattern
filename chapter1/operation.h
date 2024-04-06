#pragma once

#include <string>

class Operation {
 public:
    virtual ~Operation() { }

    virtual double getResult(double a, double b) = 0;

};


class OperationAdd : public Operation {
 public:
    virtual double getResult(double a, 
                             double b) override {
        return a + b;
    }
};

class OperationSub : public Operation {
 public:
    virtual double getResult(double a,
                             double b) override {
        return a - b;
    }
};