/*
xvalue (X-value):

An xvalue, short for "eXpiring value," represents an expression that refers to a memory location that is going to be modified or changed. It's essentially an lvalue that represents a value in transition.
Xvalues can appear on both the left and right sides of an assignment operator, but they typically indicate that the referred object is about to change.*/

#include<iomanip>
#include<vector>

int z = 30;
int& ref = z;  // 'ref' is an lvalue
int&& rref = std::move(z); // 'std::move(z)' is an xvalue
