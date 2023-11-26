#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int secretNumber = std::rand() % 100 + 1;

    int tries = 0;
    int guess;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;
        tries++;

        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << tries << " tries!" << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}
