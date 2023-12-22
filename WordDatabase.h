#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <unordered_set>



class WordDatabase {
private:
    //words from games and movies stored in unordered map
    std::unordered_map<std::string, std::string> videoGameWords;
    std::unordered_map<std::string, std::string> movieWords;

    //words from custom stored in vector
    std::vector<std::string> customWords;
    
    //random num gen instance
    std::mt19937 gen;

    //stores current category and hint for game
    //initialized
    std::string currentCategory = "";
    std::string currentHint = "";

    //poniter to unordered map
    std::unordered_map<std::string, std::string>* currentWordMap;

    //stores used words in vector
    std::vector<std::string> usedWords;
    //store guessed words for each category
    std::unordered_map<std::string, std::unordered_set<std::string>> guessedWords;

    //template shuffles elements of a vector randomly
    template<typename T>
    void shuffleVector(std::vector<T>& vec) {
        std::shuffle(vec.begin(), vec.end(), gen);
    }

    //shuffles keys of unordered map
    template<typename Key, typename Value>
    void shuffleMap(std::unordered_map<Key, Value>& map) {
        std::vector<Key> keys;
        for (const auto& pair : map) {
            keys.push_back(pair.first);
        }

        shuffleVector(keys);

        std::unordered_map<Key, Value> shuffledMap;
        for (const auto& key : keys) {
            shuffledMap[key] = map[key];
        }

        map = std::move(shuffledMap);
    }

    //updates word map pointer to the provided unordered map
    //switches between word categories by updating
    template<typename Key, typename Value>
    void updateCurrentWordMap(const std::unordered_map<Key, Value>& map) {
        currentWordMap = const_cast<std::unordered_map<Key, Value>*>(&map);

    }

public:
    //constructor
    WordDatabase() : gen(std::random_device()()) {
        loadDefaultWords();
        loadCustomWords();

        //shuffle the word vectors
        shuffleMap(videoGameWords);
        shuffleMap(movieWords);
        shuffleVector(customWords);

        std::shuffle(customWords.begin(), customWords.end(), gen);

    }

    //default words
    void loadDefaultWords() {
        videoGameWords = {
            //1 word = 20
            {"Fallout", "Famous with Deathclaws"},
            {"Grounded", "Backyard and Big Ants"},
            {"Minecraft", "Y-Level 12 = Diamonds"},
            {"Battlefield", "Developed by EA DICE"},
            {"Cyberpunk", "Developed by CD Projekt Red"},
            {"Portal", "Developed by Valve"},
            {"Fortnite", "#1 Victory Royale"},
            {"Doom", "Chainsaw, Shotguns, and Demons"},
            {"Metroid", "Developed by Nintendo"},
            {"Hitman", "Features Agent 47"},
            {"Bully", "Developed by Rockstar Vancouver"},
            {"Stray", "Game with Meow Button"},
            {"Infamous", "Developed by Sucker Punch"},
            {"Titanfall", "Developed by Respawn Entertainment"},
            {"Mafia", "Features Tommy Angelo"},
            {"Overwatch", "Hero Shooter"},
            {"Terraria", "2D Sandbox"},
            {"Outlast", "Developed by Red Barrels"},
            {"Skyrim", "Made by Bethesda Game Studios"},
            {"Hangman", "Also called, 'Rite of Words and Life'"},

            //two words = 15
            {"Dead Island", "Features Sam-B"},
            {"Resident Evil", "Developed by CAPCOM"},
            {"Stardew Valley", "Developed by 1 Person, 'ConcernedApe'"},
            {"The Witcher", "Features Geralt of Rivia"},
            {"Max Payne", "Developed by Remedy Entertainment"},
            {"Dark Souls", "Developed by FromSoftware Inc."},
            {"For Honor", "3 Factions: Samurai, Vikings, & Knights"},
            {"Mass Effect", "Developed by BioWare"},
            {"Scrap Mechanic", "Developed by Axolot Games"},
            {"Dying Light", "Developed by Techland"},
            {"Silent Hill", "Developed by Team Silent of Konami"},
            {"Animal Crossing", "Also known as 'Doubutsu no Mori+'"},
            {"Mortal Kombat", "Developed by NetherRealm Studios"},
            {"Saints Row", "Developed by Deep Silver Volition"},
            {"Guitar Hero", "Developed by Harmonix Music Systems"},

            //3 words = 10
            {"Grand Theft Auto", "Developed by Rockstar North"},
            {"Destroy All Humans", "Developed by Black Forest Games"},
            {"Ghost of Tsushima", "Mongol Invasion of Japan"},
            {"Super Mario Bros", "2D Platformer"},
            {"Call of Duty", "Developed by Infinity Ward"},
            {"Metal Gear Solid", "Designer by Hideo Kojima"},
            {"Army of Two", "Developed by EA Montreal"},
            {"Plants vs Zombies", "Developed by PopCap Games"},
            {"Red Dead Redemption", "Developed by Rockstar San Diego"},
            {"State of Decay", "Developed by Undead Labs"}
        };

        movieWords = {
            //1 word = 20
            {"Tenet", "Features Time Inversion"},
            {"Avatar", "Directed by James Cameron"},
            {"Alien", "Directed by Ridley Scott"},
            {"Jaws", "Shark Movie"},
            {"Predator", "Features Arnold Schwarzenegger"},
            {"Rango", "Chameleon in the Mojave Desert"},
            {"Us", "Directed by Jordan Peele"},
            {"Midsommar", "An A24 Film"},
            {"Oldboy", "Directed by Park Chan-wook"},
            {"Memento", "Memory Loss Movie"},
            {"Prometheus", "Prequel to a Franchise"},
            {"Elysium", "Directed by Neill Blomkamp"},
            {"Watchmen", "Directed by Zack Synder"},
            {"Sicario", "War on Drugs Film"},
            {"Zombieland", "Features Columbus, Tallahassee, and Wichita"},
            {"Drive", "'I Drive.' - RG"},
            {"Looper", "Directed by Rian Johnson"},
            {"Her", "Features an A.I"},
            {"Inception", "Directed by Christopher Nolan"},
            {"Psycho", "Directed by Alfred Hitchcock"},

            //2 word = 15
            {"Blade Runner", "Features Replicants"},
            {"The Terminator", "Features Sarah Connor"},
            {"Kill Bill", "Directed by Quentin Tarantino"},
            {"The Godfather", "Features a Mafia Family"},
            {"Top Gun", "Features Tom Cruise"},
            {"Star Wars", "Directed by George Lucas"},
            {"The Conjuring", "Directed by James Wan"},
            {"John Wick", "Features Keanu Reeves"},
            {"The Aristocats", "Features Cat Duchess"},
            {"Scary Movie", "Parody Film"},
            {"Knives Out", "Features Ana De Armas"},
            {"The Thing", "Directed by John Carpenter"},
            {"Pulp Fiction", "Features Samuel L. Jackson and John Travolta"},
            {"The Matrix", "Red or Blue Pill?"},
            {"The Mummy", "Features Brenden Fraser"},
            

            //3 word = 10
            {"The Dark Knight", "Features Heath Ledger"},
            {"The Fifth Element", "Features Milla Jovovich"},
            {"The Lion King", "Disney Film"},
            {"The Hunger Games", "Feature Jennifer Lawrence"},
            {"Alien vs Predator", "Crossover Monster Film"},
            {"Kung Fu Panda", "Features Jack Black"},
            {"The Karate Kid", "Chopsticks vs a Fly"},
            {"I Am Legend", "Features Will Smith"},
            {"Saving Private Ryan", "Directed by Steven Spielberg"},
            {"Lost in Translation", "Loneliness and Human Connection"},
        };
        
        //shuffles words again
        shuffleMap(videoGameWords);
        shuffleMap(movieWords);
        shuffleVector(customWords);
    }
    

    //function checks if a word has been guessed in the current category
    bool isWordGuessed(const std::string& category, const std::string& word) {
        return guessedWords[category].count(word) > 0;
    }

    //checks if all custom words have been guessed
    bool areAllCustomWordsGuessed() {
        const std::string& category = "Custom";

        if (customWords.empty()) {
            std::cout << "\t\t\t\t\t\t\t\t\t\t\tNo custom words available." << std::endl;
            return false;
        }

        //iterate through custom words and check if any are not guessed
        for (const std::string& word : customWords) {
            if (guessedWords[category].find(word) == guessedWords[category].end()) {
                // Found an unguessed custom word, return false
                return false;
            }
        }

        return true;
    }

    //marks a word as guessed for the current category
    void markWordAsGuessed(const std::string& category, const std::string& word) {
        guessedWords[category].insert(word);
    }

    //load custom words file
    void loadCustomWords() {
        std::ifstream file("CustomWords.txt");
        if(file) {
            std::string line;
            while (std::getline(file, line)) {
                customWords.push_back(line);
            }
            file.close();
        }
    }

    //checks if file exists
    bool checkCustomWordsFile() {
        std::ifstream file("CustomWords.txt");
        return file.good() && file.peek() != std::ifstream::traits_type::eof();
    }

    const std::vector<std::string>& getCustomWords() const {
        return customWords;
    }

    //read custom words
    void readCustomWords() {
        std::ifstream file("CustomWords.txt");
        if (file) {
            std::string word;
            customWords.clear();
            while (file >> word) {
                customWords.push_back(word);
            }
            file.close();
        }
    }

    //displays every word in file with a dash
    void displayCustomWordsWithDash() const {
        for (const std::string& word : customWords) {
            std::cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t- " << word << std::endl;
        }
    }

    //save custom words
    void saveCustomWords() {
        std::ofstream file("CustomWords.txt");
        if (file) {
            for (const std::string& word : customWords) {
                file << word << std::endl;
            }
            file.close();
        }
    }

    //checks if customword is valid
    bool isValidCustomWord(const std::string& word) {
        //check if word contians only letters and spaces
        for (char c : word) {
            if (!std::isalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    //add custom words
    void addCustomWord(const std::string& word) {
        if (isValidCustomWord(word)) {
            // Check if the word contains spaces
            if (word.find(' ') == std::string::npos) {
                // Check if the word already exists
                if (std::find(customWords.begin(), customWords.end(), word) == customWords.end()) {
                    customWords.push_back(word);
                    saveCustomWords();
                    std::cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << word << " Added!" << std::endl;
                } else {
                    std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tThe word \"" << word << "\" already exists in CustomWords.txt!" << std::endl;
                }
            } else {
                std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tInvalid Input! Only a single word without spaces is allowed." << std::endl;
            }
        } else {
            std::cout << "\n\t\t\t\t\t\t\t\t\t\t\tInvalid Input! Only Letters are allowed." << std::endl;
        }
    }

    //remove custom words
    void removeCustomWord(const std::string& word) {
        auto it = std::remove(customWords.begin(), customWords.end(), word);
        if (it != customWords.end()) {
            customWords.erase(it, customWords.end());  // Erase all occurrences of the word
            saveCustomWords();
            std::cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << word << " Removed!" << std::endl;
        } else {
            std::cout << "\n\t\t\t\t\t\t\t\t\t\t\t" << word << " does not exist in CustomWords.txt!" << std::endl;
        }
    }
    
    void createCustomCategory() {
        std::string category;
    }

    //gets random word from category
    std::string getRandomWord(const std::string& category) {
        std::unordered_map<std::string, std::string> selectedCategory;

        //categories
        if (category == "Video Games") {
            selectedCategory = videoGameWords;
        }
        else if (category == "Movies") {
            selectedCategory = movieWords;
        }
        else if (category == "Custom") {
            std::uniform_int_distribution<size_t> distribution(0, customWords.size() - 1);
            size_t randomIndex = distribution(gen);
            return customWords[randomIndex];
        }
        //future update with categories
        else {
            std::cout << "Invalid category." << std::endl;
            return "";
        }
    
        if (selectedCategory.empty()) {
            std::cout << "\t\t\t\t\t\t\t\t\t\t\tNo words available in the selected category." << std::endl;
            return "";
        }
    
        std::vector<std::string> words;
        for (const auto& pair : selectedCategory) {
            //check if the word has already been guessed for this category
            if (guessedWords[category].find(pair.first) == guessedWords[category].end()) {
                words.push_back(pair.first);
            }
        }
    
        if (words.empty()) {
            // All words in the category have been guessed
            std::cout << "\t\t\t\t\t\t\t\t\t\t\tAll words in this category have been guessed!" << std::endl;
            return "";
        }
    
        shuffleVector(words);
    
        std::uniform_int_distribution<std::size_t> distribution(0, words.size() - 1);
        std::size_t randomIndex = distribution(gen);
    
        const std::string& randomWord = words[randomIndex];
        displayHint(randomWord); // Display the associated hint
    
        return randomWord;
    }

    //grabs current category of user
    void setCurrentCategory(const std::string& category) {
        if (category == "Video Games" || category == "Movies" || category == "Custom") {
            currentCategory = category;
            std::cout << "Current Category set to: " << currentCategory << std::endl;
        } else {
            std::cout << "Invalid category." << std::endl;
        }
    }

    //stores guessed words for the current category
    void storeGuessedWord(const std::string& category, const std::string& word) {
        guessedWords[category].insert(word);
    }
    
    //displays hint of current category
    void displayHint(const std::string& word) {
        if (currentCategory == "Video Games") {
            if (videoGameWords.find(word) != videoGameWords.end()) {
                currentHint = videoGameWords[word];
                std::cout << "\t\t\t\t\t\t\t\t\t\t\tHint: " << currentHint << std::endl;
            }
        }
        else if (currentCategory == "Movies") {
            if (movieWords.find(word) != movieWords.end()) {
                currentHint = movieWords[word];
                std::cout << "\t\t\t\t\t\t\t\t\t\t\tHint: " << currentHint << std::endl;
            }
        }
        else {
            std::cout << "\t\t\t\t\t\t\t\t\t\t\tHint: [No Hint Available]" << std::endl;
        }
    }

    //gets current hint
    std::string getCurrentHint() const {
        return currentHint;
    }
    
};