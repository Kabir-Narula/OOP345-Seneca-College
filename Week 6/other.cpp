#include<iostream>
using namespace std;
// trailing type
//auto add(int a, int b) -> int { // mentiones int as return type
  //  return a + b;
//}

//enums with class
class MyClass {
public:
    enum class Status { OK, ERROR };
    Status checkStatus() {
        return Status::OK;
    }
};

//recursion
int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}


//function pointers

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*funcPtr)(int, int) = add;
    std::cout << funcPtr(2, 3); // Outputs 5
    return 0;
}
