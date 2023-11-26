#include <iostream>

int main() {
    char operation;
    double num1, num2, result;

    std::cout << "Simple Calculator" << std::endl;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return 1;
            }
            break;
        default:
            std::cout << "Invalid operation selected." << std::endl;
            return 1;
    }

    std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;

    return 0;
}
