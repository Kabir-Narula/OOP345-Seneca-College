#include <iostream>

// Function pointers for mathematical operations
typedef int (*MathOperation)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        std::cerr << "Error: Division by zero!" << std::endl;
        return 0; // Return 0 for division by zero
    }
}

int main() {
    // Function pointers initialization
    MathOperation operationPtr;

    // Menu for selecting the operation
    std::cout << "Select operation:" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;

    int choice;
    std::cin >> choice;

    // Assign function pointer based on user choice
    switch (choice) {
        case 1:
            operationPtr = add;
            break;
        case 2:
            operationPtr = subtract;
            break;
        case 3:
            operationPtr = multiply;
            break;
        case 4:
            operationPtr = divide;
            break;
        default:
            std::cerr << "Invalid choice!" << std::endl;
            return 1;
    }

    // Get user input for numbers
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    // Perform the selected operation using the function pointer
    int result = operationPtr(num1, num2);

    // Output the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}
