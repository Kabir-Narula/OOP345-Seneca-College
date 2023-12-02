/*
noexcept() Operator:

The noexcept() operator is used to specify whether a function may throw exceptions. It is typically used in function declarations and definitions to indicate whether the function is expected to throw exceptions.*/

#include <iostream>

void myFunction(int x, int y) noexcept {
    if (y == 0) {
        throw "Division by zero";
    }
    std::cout << "Result: " << x / y << std::endl;
}

int main() {
    try {
        myFunction(10, 2);
        myFunction(5, 0);
    } catch (const char* message) {
        std::cerr << "Exception caught: " << message << std::endl;
    }
    return 0;
}


/*In this code, noexcept is used to indicate that myFunction does not throw exceptions. However, an exception is thrown if the divisor y is zero, which is caught and handled.*/