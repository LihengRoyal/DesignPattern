#pragma once

#include "operation.h"

class OperFactory {
 public:
    Operation* CreateOperator(char c) {
        Operation* oper;
        switch (c) {
         case '+':
            oper = new OperationAdd();
            break;
         case '-':
            oper = new OperationSub();
            break;
         default:
            break;
        }
        return oper;
    }
};