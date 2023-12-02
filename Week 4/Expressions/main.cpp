#include <iostream>
#include <vector>

int getValue() { return 100; }

int main() {
    // Example variables
    int x = 10;
    int y = 20;
    int z;

    // Lvalues
    int& ref = x; // 'ref' is an lvalue, a reference to 'x'
    std::vector<int> vec = {1, 2, 3};
    int* ptr = &x; // 'ptr' is an lvalue, a pointer to 'x'

    // Xvalues
    z = std::move(x); // 'x' is an lvalue, but 'std::move(x)' turns it into an xvalue
    int&& rref = std::move(y); // 'y' is an lvalue, but 'std::move(y)' turns it into an xvalue

    // Prvalues
    int result = x + y; // 'x + y' is a prvalue, a temporary result of the addition
    int num = 42; // '42' is a prvalue, a literal constant
    int val = getValue(); // 'getValue()' returns a prvalue

    // Display values
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "ref = " << ref << ", rref = " << rref << std::endl;
    std::cout << "result = " << result << ", num = " << num << ", val = " << val << std::endl;

    return 0;
}


/*In this example:

x, y, and z are lvalues. They are variables that can be assigned and manipulated.
ref is an lvalue reference to x.
ptr is an lvalue pointer to x.
std::move(x) and std::move(y) are xvalues. They represent values that are in transition or about to be moved.
x + y is a prvalue. It's a temporary result of the addition and doesn't have a persistent memory location.
42 is a prvalue, representing a literal constant.
getValue() returns a prvalue.
Understanding these distinctions is essential for various aspects of C++ programming, including move semantics, efficient resource management, and the behavior of expressions in different contexts.*/