#include <iostream>
#include <string>

#include "ASCIIHangman.h"

class Hangman {
private:
    //stores count of incorrect guesses
    int incorrectGuesses;

public:
    //constrtuctor initialized to 0
    Hangman() : incorrectGuesses(0) {}

    //updates incorrect guesses count
    void update(int incorrectGuesses) {
        this->incorrectGuesses = incorrectGuesses;
    }

    //maximum number of guessses to 6
    int getMaxIncorrectGuesses() const {
        return 6;
    }

    //displays ascii art representation of incorrect guesses
    void display() {
        switch (incorrectGuesses) {
            case 0:
                std::cout << ASCIIHangman::ASCIIHangmanNone() << std::endl;
                break;

            case 1:
                std::cout << ASCIIHangman::ASCIIHangmanHead() << std::endl;
                break;

            case 2:
                std::cout << ASCIIHangman::ASCIIHangmanBody() << std::endl;
                break;

            case 3:
                std::cout << ASCIIHangman::ASCIIHangmanArmL() << std::endl;
                break;

            case 4:
                std::cout << ASCIIHangman::ASCIIHangmanArmR() << std::endl;
                break;

            case 5:
                std::cout << ASCIIHangman::ASCIIHangmanLegL() << std::endl;
                break;

            case 6:
                std::cout << ASCIIHangman::ASCIIHangmanFull() << std::endl;
                break;
            }
    }


};
