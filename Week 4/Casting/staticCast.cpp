/*
Used for general type conversions, including numeric types, related class types, and user-defined conversions.
It is a compile-time operation and does not provide runtime type checking.
Performs implicit type conversions when safe, but it doesn't work with polymorphic class hierarchies.
Considered safe for most type conversions but should be used with care.*/

#include <iostream>

int main() {
    double pi = 3.14159;
    int approxPi = static_cast<int>(pi); // Static cast from double to int
    std::cout << "Approximate Pi as an integer: " << approxPi << std::endl;
    return 0;
}
