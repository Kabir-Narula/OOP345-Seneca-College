#include <iostream>
#include <iomanip>
#include <typeinfo> // Added for typeid

using namespace std;

// OOP Characteristics
//  - Encapsulation: Achieved by private data members and public member functions.
//  - Inheritance
//  - Polymorphism (do the same thing in different ways)
//    - Fake polymorphism (ad hoc polymorphism)

// Assumptions about T
//  - T must have a default constructor
//  - T must have a destructor

// Forward declaration of the Foo class and the operator<< function template
template <typename T>
class Foo;

template <typename T>
std::ostream &operator<<(std::ostream &out, const Foo<T> &obj);

// Definition of the Foo class template
template <typename T>
class Foo
{ 
    static int cnt; // Static counter variable
    std::string m_data;
    T m_value;

public:
    // Constructor
    Foo();

      static void displayCount()
    {
        cout << "Current count: " << cnt << endl;
    }
    
    // Friend declaration for the operator<< function
    friend std::ostream &operator<<<T>(std::ostream &out, const Foo<T> &obj); // Add <T>
};

template <typename T>
int Foo<T>::cnt = 0;

// Constructor definition
template <typename T>
Foo<T>::Foo() : m_data("Hello from Foo"), m_value()
{
    cnt++;
    // You can also initialize m_data and m_value in the member initializer list.
    // In this case, m_value is initialized with its default constructor.
    // m_data = "I am Foo"; // This line is not needed since you're initializing m_data in the member initializer list.
}

// Definition of the operator<< function template for Foo<T>
template <typename T>
std::ostream &operator<<(std::ostream &out, const Foo<T> &obj)
{
    return out << obj.m_data << " with value " << obj.m_value;
}

// Assumption about template type <T> (operations/functions that must exist for type T)
// - operator<<(ostream&, const T&)
// - Copy constructor
// - Destructor

// Template function to print the type and value of a variable
template <typename T, size_t WIDTH = 30u>
void print(const T &value)
{
    cout << setw(WIDTH) << typeid(value).name() << " ???  [" << value << "]\n";
}

int main()
{
    // Create an instance of Foo<int>
    Foo<int> aFoo;
    Foo<int> bFoo;
    
    // Display the current count of Foo objects
    Foo<int>::displayCount(); // Should display 2
    
    // Print different types using the print function
    print(10);         // Instantiation for template for T = int
    print(40.56);      // Instantiation for template for T = double
    print(aFoo);       // Instantiation for template for T = Foo<int>
    
    // Print the Foo<int> instance using the overloaded operator<< for Foo<T>
    cout << aFoo;
    
    return 0;
}
