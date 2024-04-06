#include <iostream>
#include "operation.h"

int main() {
    int a = 10, b = 20;
    Operation* oper = new OperationAdd();
    std::cout << oper->getResult(a, b) << std::endl;
    oper = new OperationSub();
    std::cout << oper->getResult(a, b) << std::endl;
    return 0;
}