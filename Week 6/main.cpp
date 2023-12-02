#include <iostream>
#include <cstring>

class RuleOf6Example {
private:
    char* str;

public:
    // Constructor (Rule of 1)
    RuleOf6Example(const char* s) : str(nullptr) {   // we create a variable names character s 
        if (s) { // we check if s exists
            str = new char[strlen(s) + 1]; // yes it exists, now we allocate memory for char* s 
            strcpy(str, s);  // copy the inputed string s into the str...
        }
    }

    // Destructor (Rule of 1)
    ~RuleOf6Example() {
        delete[] str; // clen up str....
    }

    // Copy constructor (Rule of 3)
    RuleOf6Example(const RuleOf6Example& other) : str(nullptr) {  // create new variable for copy
        if (other.str) {  // if exists and not null
            str = new char[strlen(other.str) + 1];  // allocate memory for s and +1 for null terminator
            strcpy(str, other.str);  // copy the other.str into str
        }
    }

    // Copy assignment operator (Rule of 3)
    RuleOf6Example& operator=(const RuleOf6Example& other) {   //
        if (this != &other) { // cchecks if we dont copy to same object
            delete[] str;
            str = nullptr;
            if (other.str) {
                str = new char[strlen(other.str) + 1];
                strcpy(str, other.str);
            }
        }
        return *this;
    }

    // Move constructor (Rule of 5)
    RuleOf6Example(RuleOf6Example&& other) noexcept : str(other.str) {
        other.str = nullptr;
    }

    // Move assignment operator (Rule of 5)
    RuleOf6Example& operator=(RuleOf6Example&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            other.str = nullptr;
        }
        return *this;
    }

    // Function to display the stored string
    void display() const {
        if (str) {
            std::cout << "Stored String: " << str << std::endl;
        } else {
            std::cout << "No string stored." << std::endl;
        }
    }
};

int main() {
    RuleOf6Example obj1("Hello, World!"); // Constructor
    RuleOf6Example obj2(obj1); // Copy constructor

    RuleOf6Example obj3("Copy assignment test");
    obj3 = obj1; // Copy assignment operator

    RuleOf6Example obj4("Move constructor test");
    RuleOf6Example obj5 = std::move(obj4); // Move constructor

    RuleOf6Example obj6("Move assignment test");
    obj6 = std::move(obj5); // Move assignment operator

    obj1.display();
    obj2.display();
    obj3.display();
    obj4.display();
    obj5.display();
    obj6.display();

    return 0;
}
