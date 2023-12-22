#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

#include "WordDatabase.h"
#include "Hangman.h"
#include "WordMask.h"
#include "Input.h"
#include "ASCIIUI.h"

class HangmanGame {
public:
    std::string currentCategory;
    int wins;
    int losses;
    WordDatabase wordDatabase;
    Hangman hangman;
    WordMask wordMask;
    InputManager inputManager;

    HangmanGame() : wins(0), losses(0) {}

    //CLEAR screen function
    void clearScreen() {
        system("cls");
    }
    //PAUSE screen function
    void pauseScreen(int milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }


    //WELCOME screen
    void displayWelcomeScreen() {
        pauseScreen(1000);
        std::cout << ASCIIUI::ASCIIIntro1();

        pauseScreen(1000);
        clearScreen();

        std::cout << ASCIIUI::ASCIIIntro2();
        pauseScreen(1500);
        clearScreen();


        std::cout << ASCIIUI::ASCIIIntro3();
        pauseScreen(2000);
        clearScreen();

        std::cout << ASCIIUI::ASCIIIntro4();
        pauseScreen(2500);
        
        std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to continue..." << std::endl;
        std::cin.ignore();
        clearScreen();
    }

    //CUSTOM Manage Menu
    void CustomMenuManage() {
        int selectedCustomManage = 0;
        bool customManageActive = true;

        while (customManageActive) {
            clearScreen();

            //MANAGE MENU
            //add
            if (selectedCustomManage == 0) {
                std::cout << ASCIIUI::ASCIICustomManage1();
            //remove
            } else if (selectedCustomManage == 1) {  
                std::cout << ASCIIUI::ASCIICustomManage2();
            //read
            } else if (selectedCustomManage == 2) {
                std::cout << ASCIIUI::ASCIICustomManage3();
            //custom (back)
            } else if (selectedCustomManage == 3) {
                std::cout << ASCIIUI::ASCIICustomManage4();
            }
            char input = _getch();
            switch (input) {
                //upp arrow key
                case 'w':
                    selectedCustomManage = (selectedCustomManage - 1 + 4) % 4;  // Wrap around the options
                    break;
                //down arrow key
                case 's':  
                    selectedCustomManage = (selectedCustomManage + 1) % 4;  // Wrap around the options
                    break;
                //enter key
                case '\r':  
                    clearScreen();
                    switch (selectedCustomManage) {
                        //MANAGE: add words
                        case 0: {
                            std::cout << ASCIIUI::ASCIICustomAdd() << std::endl;
                            std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tEnter a custom word: ";
                            std::string word;
                            std::cin >> word;
                            wordDatabase.addCustomWord(word);
                            std::cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to return to menu..." << std::endl;
                            std::cin.ignore();
                            break;
                        }
                        
                        //MANAGE: remove words
                        case 1: {
                            if (wordDatabase.getCustomWords().empty()) {
                                std::cout << ASCIIUI::ASCIICustomRemove() << std::endl;
                                std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tCustomWords.txt is empty! No words to remove." << std::endl;
                            } else {
                                std::string word;
                                std::cout << ASCIIUI::ASCIICustomRemove() << std::endl;
                                std::cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter word to remove: ";
                                std::cin >> word;
                        
                                // Check if word is empty
                                if (word.empty()) {
                                    std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tYou entered an empty word. No removal performed." << std::endl;
                                } else {
                                    bool removed = false;
                                    for (const std::string& customWord : wordDatabase.getCustomWords()) {
                                        if (customWord == word) {
                                            wordDatabase.removeCustomWord(word);
                                            removed = true;
                                            break;
                                        }
                                    }
                                    if (!removed) {
                                    std::cout << "\n\n\n\t\t\t\t\t\t\t\t\t\t\t'" << word << "' does not exist in CustomWords.txt!" << std::endl;
                                    }
                                }

                            }
                            std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to return to menu..." << std::endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.get();
                            break;
                        }

                        //MANAGE: read words
                        case 2: {
                            std::cout << ASCIIUI::ASCIICustomRead() << std::endl;
                            const std::vector<std::string>& customWords = wordDatabase.getCustomWords();
                            if (customWords.empty()) {
                                std::cout << "\t\t\t\t\t\t\t\t\t\t\tCustomWords.txt is currently empty!" << std::endl;
                            } else {
                                wordDatabase.readCustomWords();

                                wordDatabase.displayCustomWordsWithDash();

                            }
                            
                            std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to return to menu..." << std::endl;
                            std::cin.ignore();
                            break;
                        }

                        //MANAGE: Custom menu
                        case 3:
                            customManageActive = false;
                            CustomMenu();
                            break;
                    }
                    break;
            }
        }
    }

    //CUSTOM MENU
    void CustomMenu() {
        int selectedCustom = 0;
        bool customActive = true;

        //check CustomWords.txt exists
        bool customWordsExist = wordDatabase.checkCustomWordsFile();
        //check if .txt has words
        bool customWordsEmpty = !customWordsExist  || wordDatabase.getCustomWords().empty();

        while (customActive) {
            clearScreen();

            //Display Menu 
            //play
            if (selectedCustom == 0) {
                std::cout << ASCIIUI::ASCIICustomMenu1();
            //manage
            } else if (selectedCustom == 1) {  
                std::cout << ASCIIUI::ASCIICustomMenu2();
            //category
            } else if (selectedCustom == 2) {
                std::cout << ASCIIUI::ASCIICustomMenu3();
            }

            // Wait for user input
            char input = _getch();  // Get a character from the console
            //process the user input
            switch (input) {
                //Up arrow key
                case 'w':
                    selectedCustom = (selectedCustom - 1 + 3) % 3;  // Wrap around the options
                    break;
                // Down arrow key
                case 's':  
                    selectedCustom = (selectedCustom + 1) % 3;  // Wrap around the options
                    break;
                // Enter key
                case '\r':  
                    clearScreen();
                    switch (selectedCustom) {
                        //add
                        case 0:
                            wordDatabase.readCustomWords();
                            if (!customWordsExist) {
                                clearScreen();
                                std::cout << ASCIIUI::ASCIIError() << std::endl;
                                std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tCustomWords.txt does not exist!" << std::endl;
                                std::cout << "\n\t\t\t\t\t\t\t\t\tMake sure there is a text file called CustomWords.txt in the same folder." << std::endl;
                                std::cout << "\n\t\t\t\t\t\t\t\t\tYou can add one in in the 'Add' option from the 'Manage' custom menu." << std::endl;
                                pauseScreen(2000);
                                std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to continue..." << std::endl;
                                std::cin.ignore();
                            } else if (customWordsEmpty) {
                                clearScreen();
                                std::cout << ASCIIUI::ASCIIError() << std::endl;
                                std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tCustomWords.txt contains no words!" << std::endl;
                                std::cout << "\n\t\t\t\t\t\t\t\t\tPlease add words in the 'Add' option from the 'Manage' custom menu." << std::endl;
                                pauseScreen(2000);
                                std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to continue..." << std::endl;
                                std::cin.ignore();
                            } else {
                                std::cout << "You selected Custom";
                                currentCategory = "Custom";
                                playRound();
                            }
                            break;
                            
                        //remove
                        case 1:
                            customActive = false;
                            CustomMenuManage();
                            break;
                        //category
                        case 2:
                            customActive = false;  // Exit the menu
                            mainMenu();
                            break;  
                    }
            }
        }
    }


    //CATEGORY MENU (Classic Selected)
    void selectCategory() {
        std::cout << "Please select a category:" << std::endl;

        int selectedCategory = 0;
        bool categoryActive = true;
        bool showTryAgainMenu = false;

        while (categoryActive) {
            //Display Categories
            clearScreen();
            //CATEGORY DISPLAY VideoGames 
            if (selectedCategory == 0) {
                std::cout << ASCIIUI::ASCIICategory1();
            }
            //CATEGORY DISPLAY Movies
            else if (selectedCategory == 1) {
                std::cout << ASCIIUI::ASCIICategory2();
            }
            //CATEGORY DISPLAY Custom (User inserted)
            else if (selectedCategory == 2) {
                std::cout << ASCIIUI::ASCIICategory3();
            }

            char input = _getch();

            // Process the user input
            switch (input) {
                //Up key
                case 'w':
                    selectedCategory = (selectedCategory - 1 + 3) % 3;
                    break;
                //Down key
                case 's':
                    selectedCategory = (selectedCategory + 1) % 3;
                    break;
                //Enter key
                case '\r':
                    clearScreen();
                    switch (selectedCategory) {
                        //CATEGORY: VideoGames
                        case 0:
                            std::cout << "You selected Games";
                            currentCategory = "Video Games";
                            wordDatabase.setCurrentCategory(currentCategory);
                            playRound();
                            break;
                        //CATEGORY: Movies
                        case 1:
                            std::cout << "You selected Movies";
                            currentCategory = "Movies";
                            wordDatabase.setCurrentCategory(currentCategory);
                            playRound();
                            break;
                        //CATEGORY: Main menu
                        case 2:
                            categoryActive = false;
                            mainMenu();
                            break;
                    }

                    //flag sets try again menu
                    showTryAgainMenu = categoryActive;
                    break;
            }
        }

        //display try again menu if needed
        if (showTryAgainMenu) {
            bool runAgain = true;
            while (runAgain) {
                int selectedOption = 0;
                bool menuActive = true;
                while (menuActive) {
                    clearScreen();
                    if (selectedOption == 0) {
                        std::cout << ASCIIUI::ASCIITryAgainYes();
                    }
                    else if (selectedOption == 1) {
                        std::cout << ASCIIUI::ASCIITryAgainNo();
                    }

                    char input = _getch();

                    switch (input) {
                        case 'a':
                            selectedOption = (selectedOption - 1 + 2) % 2;
                            break;
                        case 'd':
                            selectedOption = (selectedOption + 1) % 2;
                            break;
                        case '\r':
                            clearScreen();
                            switch (selectedOption) {
                                case 0:
                                    runAgain = false;
                                    playRound();
                                    break;
                                case 1:
                                    menuActive = false;
                                    categoryActive = false;
                                    selectCategory();
                                    break;
                            }
                    }

                }
            }
        }
    }


    //MAIN MENU
    void mainMenu() {
        int selectedOption = 0;
        bool menuActive = true;

        while (menuActive) {
            clearScreen();

            //Display MAIN MENU
            //Classic (default words)
            if (selectedOption == 0) {
                std::cout << ASCIIUI::ASCIIMenuOption1();
            //Custom (user defined words)
            } else if (selectedOption == 1) {  
                std::cout << ASCIIUI::ASCIIMenuOption2();
            //Exit (exit prog)
            } else if (selectedOption == 2) {
                std::cout << ASCIIUI::ASCIIMenuOption3();
            }
            //user input
            char input = _getch();

            //process the user input
            switch (input) {
                //up on menu
                case 'w':
                    //wrap around 3 options
                    selectedOption = (selectedOption - 1 + 3) % 3;
                    break;
                //down on menu
                case 's':  
                    selectedOption = (selectedOption + 1) % 3;
                    break;
                //enter key
                case '\r':  
                    clearScreen();
                    switch (selectedOption) {
                        //MAIN MENU: Classic
                        case 0:
                            selectCategory();
                            menuActive = false;
                        //MAIN MENU: Custom
                        case 1:
                            CustomMenu();
                            menuActive = false;
                            break;
                        //MAIN MENU: Exit
                        case 2:
                            menuActive = false;
                            break; 
                    }
            }
        }

        //exit
        std::cout << ASCIIUI::ASCIIOutro();
        pauseScreen(2000);
        exit(0);
    }



    //STARTS GAME
    void playRound() {
        bool continueRound = true;
        while (continueRound) {
            std::string chosenWord = wordDatabase.getRandomWord(currentCategory);
            if (chosenWord.empty()) {
                clearScreen();
                std::cout << ASCIIUI::ASCIICongrats();
                pauseScreen(2000);
                std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tGreat job for guessing all the words! Your prize is..." << std::endl;
                pauseScreen(3000);
                std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tAbsolutely nothing..." << std::endl;
                pauseScreen(1000);
                std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to accept." << std::endl;
                std::cin.ignore();
                clearScreen();
                continueRound = false;
                return;
            }

            //if word has been guessed in the current category
            if (wordDatabase.isWordGuessed(currentCategory, chosenWord)) {
                std::cout << "\t\t\t\t\t\t\t\t\t\t\tYou've already guessed the word \"" << chosenWord << "\" for this category." << std::endl;
                bool allCustomWordsGuessed = wordDatabase.areAllCustomWordsGuessed();
                if (allCustomWordsGuessed) {
                    clearScreen();
                    std::cout << ASCIIUI::ASCIICongrats();
                    pauseScreen(2000);
                    std::cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tGreat job for guessing all the custom words!" << std::endl;
                    pauseScreen(2000);
                    std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tDon't forget you can add more in the Manage Menu." << std::endl;
                    pauseScreen(2000);
                    std::cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to exit." << std::endl;
                    std::cin.ignore();
                    clearScreen();
                    continueRound = false;
                    return;
                }
                continue;
            }

            //initialize the word mask
            wordMask.initialize(chosenWord); 

            int incorrectGuesses = 0;
            hangman.update(incorrectGuesses);
            hangman.display();

            //container to store guessed letters
            std::vector<char> guessedLetters; 

            //handle player's guesses and update the hangman figure and word mask
            while (!wordMask.isComplete() && incorrectGuesses < hangman.getMaxIncorrectGuesses()) {
                clearScreen();
                displayScore();
                hangman.display();
                wordMask.display();
                wordDatabase.displayHint(chosenWord);

                // Display the guessed letters
                if (!guessedLetters.empty()) {
                    std::cout << "\t\t\t\t\t\t\t\t\t\t\tGuessed letters: ";
                    for (char letter : guessedLetters) {
                        std::cout << letter << " ";
                    }
                    std::cout << std::endl;
                }

                char guess = inputManager.getValidGuess();

                //if the letter has already been guessed
                //restart the loop to get a new guess
                if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
                    std::cout << "\t\t\t\t\t\t\t\t\t\t\tYou already guessed that letter!" << std::endl;
                    continue; 
                }

                //add the guessed letter to the container
                guessedLetters.push_back(guess); 

                if (wordMask.update(chosenWord, guess)) {
                    std::cout << "\t\t\t\t\t\t\t\t\t\t\tCorrect guess!" << std::endl;
                } else {
                    incorrectGuesses++;
                    hangman.update(incorrectGuesses);
                    hangman.display();
                    std::cout << "\t\t\t\t\t\t\t\t\t\t\tIncorrect guess!" << std::endl;
                }
            }

            clearScreen();
            displayScore();
            hangman.display();
            wordMask.display();

            if (wordMask.isComplete()) {
                std::cout << ASCIIUI::ASCIICorrect();
                pauseScreen(1500);
                std::cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to continue..." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                wordDatabase.storeGuessedWord(currentCategory, chosenWord);
                wins++;
            } else {
                std::cout << ASCIIUI::ASCIIWrong();
                std::cout << "\t\t\t\t\t\t\t\t\t\t\tThe correct word was: " << chosenWord << std::endl;
                pauseScreen(1500);
                std::cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tPress [ENTER] to continue..." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                losses++;

                //game over prompt
                clearScreen();
                std::cout << ASCIIUI::ASCIIGameOver();
                pauseScreen(2000);

                //rerun game prompt
                if (continueRound) {
                    bool runAgain = true;
                    while (runAgain) {
                        int selectedOption = 0;
                        bool menuActive = true;
                        while (menuActive) {
                            clearScreen();
                            if (selectedOption == 0) {
                                std::cout << ASCIIUI::ASCIITryAgainYes();
                            } else if (selectedOption == 1) {
                                std::cout << ASCIIUI::ASCIITryAgainNo();
                            }

                            char input = _getch();

                            switch (input) {
                                case 'a':
                                    selectedOption = (selectedOption - 1 + 2) % 2;
                                    break;
                                case 'd':
                                    selectedOption = (selectedOption + 1) % 2;
                                    break;
                                case '\r':
                                    clearScreen();
                                    switch (selectedOption) {
                                        //try again: yes
                                        case 0:
                                            runAgain = false;
                                            continueRound  = true;
                                            playRound();
                                            break;
                                        //try again: no
                                        case 1:
                                            menuActive = false;
                                            continueRound = false;
                                            selectCategory();
                                            break;
                                    }
                            }
                        }
                    }
                }
            }
        }
    }

    //displays score at top
    void displayScore() {
        std::cout << "\t\t\t\t\t\t\t\t\t\t\tScore - Wins: " << wins << "  |  Losses: " << losses << std::endl;
    }

    //initial welcome and main menu UI
    void run() {
        clearScreen();
        displayWelcomeScreen();
        mainMenu();
    }
};

//full screen CMD
void fullscreen() {
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

//main driver function
int main() {
    fullscreen();
    HangmanGame game;
    game.run();

    return 0;
}
