/*
decltype() Specifier:

The decltype() specifier is used to deduce the type of an expression or variable at compile time. It's particularly useful when you want to determine the type of an expression without actually evaluating it.*/

#include <iostream>

template <typename T1, typename T2>
auto add(T1 val1, T2 val2) -> decltype(val1 + val2)
{
    return val1 + val2;
}

int main() {
    int x = 5;
    decltype(x) y = 10; // 'decltype(x)' deduces the type of 'x'
    std::cout << "Type of y: " << typeid(y).name() << std::endl;

   std::cout<< add(1.2,5)<< std::endl;
   std::cout<< add(1,5.2)<< std::endl;

    return 0;
}

//Type of y: i


