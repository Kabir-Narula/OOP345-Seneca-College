/*alignof() Operator:

The alignof() operator is used to determine the alignment requirement of a type or an expression in memory. Alignment is important for optimizing memory access and improving the efficiency of data storage and retrieval.*/



#include <iostream>

int main() {
    std::cout << "Alignment of int: " << alignof(int) << std::endl;
    std::cout << "Alignment of double: " << alignof(double) << std::endl;
    std::cout << "Alignment of char: " << alignof(char) << std::endl;
 
    return 0;
}

