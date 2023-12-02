#include <iostream>
#include <stdexcept>

template <typename T>
class FibonacciCalculator {
public:
    // Function to calculate the Fibonacci number for a given input 'n'
    static T calculate(unsigned int n) {
        // Check if n is too large (greater than or equal to 47)
        if (n >= 47) {
            // If n is too large, throw an exception with the value of n
            throw std::overflow_error("Fibonacci number is too large for n=" + std::to_string(n));
        }
        
        // Base cases for Fibonacci: F(0) = 0 and F(1) = 1
        if (n == 0) {
            return static_cast<T>(0);
        } else if (n == 1) {
            return static_cast<T>(1);
        } else {
            // Initialize variables to store Fibonacci numbers
            T a = static_cast<T>(0), b = static_cast<T>(1), c;
            
            // Calculate Fibonacci numbers iteratively
            for (unsigned int i = 2; i <= n; ++i) {
                c = a + b;
                a = b;
                b = c;
            }
            
            // Return the nth Fibonacci number
            return b;
        }
    }
};

int main() {
    try {
        // Loop from 0 to 49 and calculate Fibonacci numbers for integers
        for (unsigned int i = 0u; i < 50; ++i) {
            std::cout << "F(" << i << ") = " << FibonacciCalculator<int>::calculate(i) << std::endl;
        }

        // Loop from 0 to 49 and calculate Fibonacci numbers for doubles
        for (unsigned int i = 0u; i < 50; ++i) {
            std::cout << "F(" << i << ") = " << FibonacciCalculator<double>::calculate(i) << std::endl;
        }
    } catch (const std::overflow_error& error) {
        // If an exception is caught, print an error message
        std::cerr << "Exception caught: " << error.what() << std::endl;
    }

    return 0;
}
