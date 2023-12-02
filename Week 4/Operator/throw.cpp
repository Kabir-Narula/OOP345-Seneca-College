/*
throw Operator:

The throw operator is used to throw an exception in C++ when an error or exceptional condition occurs. It is typically followed by an exception object or a value that provides information about the error.*/

#include <iostream>
#include <stdexcept>

int divide(int x, int y) {
    if (y == 0) {
        throw std::runtime_error("Division by zero");
    }
    return x / y;
}

int main() {
    try {
        int result = divide(10, 2);
        std::cout << "Result: " << result << std::endl;
        result = divide(5, 0); // This will throw an exception
    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
    return 0;
}
