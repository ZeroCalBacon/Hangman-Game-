# Hangman Game

A simple Hangman game in the console. It's implemented using C++.

## Table of Contents

- [Description](#description)
- [Prerequisites](#prerequisites)
- [Customization](#customization)
- [License](#license)

## Description

A Hangman game where the user has to guess a word by inputting letters. The user only has six tries to guess the word.
The program features:

- Menu UI: interative menu navigation.
- ASCII Art: UI and Hangman ASCII art.
- Class Gamemode: video game and movie words to guess.
- Custom Gamemode: allows for user-defined words.
- Modify Custom Words: allows the user to add, remove, and read from a text file.
- Hint System: to help the user guess a word.
- Score System: track the users overall score of their current run.


## Prerequisites

Before running the program, it's recommended that you have the following:

- C++ compiler (e.g., g++)
- Visual Studio Code (or any code editor of your choice)
- Windows OS (for Windows-specific features)

## Customization

You can customize the program by modifying the default words per category under WordDatabase along with its hint.
Likewise, the user can also add and remove custom words from the 'CustomWords.txt' file.
The ASCII art can also be changed in ASCIIUI and ASCIIHangman.

Feel free to replace the ASCII art with your own designs to create a unique experience.

To help, I used the following ASCII website generators for the ASCII art:

- ASCII Art Archive
- Super Emotes
- Patorjk

## license

Copyright <2023> <FranzLor>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.