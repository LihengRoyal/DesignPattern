#include <iostream>
#include "operation.h"

int main() {
    int a = 10, b = 20;
    Operation* oper = new OperationAdd(a, b);
    std::cout << oper->getResult() << std::endl;
    oper = new OperationSub(a, b);
    std::cout << oper->getResult() << std::endl;
    return 0;
}