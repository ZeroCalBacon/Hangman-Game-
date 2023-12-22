#include <iostream>

class InputManager {
private:
    //takes character whether valid or not
    bool isValidGuess(char guess) {
        return (std::isalpha(guess) && std::islower(guess));
    }

public:
    char getValidGuess() {
        char guess;
        bool validGuess = false;

        //while not invalid guess
        while (!validGuess) {
            std::cout << "\t\t\t\t\t\t\t\t\t\t\tEnter your guess: ";
            std::cin >> guess;

            //validates guess
            if (isValidGuess(guess)) {
                validGuess = true;
            } else {
                std::cout << "\t\t\t\t\t\t\t\t\t\t\tInvalid guess. Please try again." << std::endl;
            }
        }

        return guess;
    }


};
