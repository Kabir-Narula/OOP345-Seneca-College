/*
Const Cast (const_cast):

Used to add or remove the const qualifier from a variable.
Typically used when you need to modify a const object or work with non-const versions of a variable.
Can be used with pointers and references to modify the const-ness of the underlying object.*/

#include <iostream>

int main() {
    const int x = 5;
    int* ptr = const_cast<int*>(&x); // Remove const qualifier to modify 'x'
    *ptr = 10;
    std::cout << "Modified x: " << x << std::endl;
    return 0;
}
