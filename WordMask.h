#include <iostream>
#include <string>

class WordMask {
private:
    std::string maskedWord;

public:
    //initializes masked word
    //sets letters with underscore
    void initialize(const std::string& word) {
        maskedWord = std::string(word.length(), '_');
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == ' ') {
                maskedWord[i] = ' ';
            }
        }
    }

    //updates the masked word
    //for every guessed letter
    bool update(const std::string& word, char guess) {
        bool correctGuess = false;

        for (size_t i = 0; i < word.length(); ++i) {
            if (std::tolower(word[i]) == std::tolower(guess)) {
                maskedWord[i] = word[i];
                correctGuess = true;
            }
        }

        return correctGuess;
    }

    //display prompt
    void display() {
        std::cout << "\t\t\t\t\t\t\t\t\t\t\tMasked Word: " << maskedWord << std::endl;
    }

    //checks whether masked word is completed
    bool isComplete() const {
        return maskedWord.find('_') == std::string::npos;
    }
};
