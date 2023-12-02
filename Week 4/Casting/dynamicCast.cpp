/*
Dynamic Cast (dynamic_cast):

Primarily used for type-safe downcasting in polymorphic class hierarchies.
Requires that at least one virtual function be present in the class hierarchy.
Provides runtime type checking, returning a nullptr or throwing an exception if the conversion is not possible.
Safely handles conversions between base and derived class pointers or references in a polymorphic hierarchy.*/

#include <iostream>

class Base {
public:
    virtual void foo() {}
};

class Derived : public Base {};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Dynamic cast in a polymorphic hierarchy
    if (derivedPtr) {
        std::cout << "Dynamic cast successful" << std::endl;
    } else {
        std::cout << "Dynamic cast failed" << std::endl;
    }
    delete basePtr;
    return 0;
}
