#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "figure.cpp"
using namespace std;

void generateKeyboard(char key[]);
void chooseWord(string& word, vector <string> list);
void playerGuess(char& guess);
void showKeyboard(char key[]);
bool contain(char guess, string word);
void update(string& guessed, string word, char guess);
void renderGame(string guessed, int guessCoung, int badGuessCount, char key[]);

int main() {
    srand(time(0));
    string word;
    vector <string> list;

    ifstream file("D:/HocTap/C++/HangmanRemake/word_list.txt");
    string temp;
    while (!file.eof()) {
        getline(file, temp);
        list.push_back(temp);
    }
    
    char answer;
    
    do {
        chooseWord(word, list);

        string guessed = string(word.length(), '_');
        char guess;

        int guessCount = 0;
        int badGuessCount = 0;
        const int MAX_BAD_GUESSES = 7; 
        char key[26];
        

        generateKeyboard(key);
        do {
            renderGame(guessed, guessCount, badGuessCount, key);
            playerGuess(guess);
            if (guess >= 'a' && guess <= 'z') key[guess - 'a'] = ' ';
            else key[guess - 'A'] = ' ';
            guessCount++;
            if (contain(guess, word)) update(guessed, word, guess);
            else badGuessCount++;
        }
        while (guessed != word && badGuessCount < MAX_BAD_GUESSES);

        drawHangman(badGuessCount);
        renderGame(guessed, guessCount, badGuessCount, key);
        if (guessed == word) cout << "Congratulation! You found the word. The word is: " << word << endl;
        else cout << "You lose! The word is: " << word << endl;
        cout << endl << "Do you want to play again? (y/n): ";
        cin >> answer;
    }
    while (answer == 'Y' || answer == 'y');
    return 0;
}

void generateKeyboard(char key[]) {
    for (int i = 0; i < 26; i++) {
        key[i] = i + 'A';
    }
}

void chooseWord(string& word, vector <string> list) {
    word = list[rand() % (list.size())];
}

void playerGuess(char& guess) {
    cout << "Guess a letter: ";
    cin >> guess;
}

void showKeyboard(char key[]) {
    cout << endl;
    cout << key[16] << " " << key[22] << " " << key[4] << " " << key[17] << " " << key[19] << " " << key[24] << " " << key[20] << " " << key[8] << " " << key[14] << " " << key[15] << endl;
    cout << " " << key[0] << " " << key[18] << " " << key[3] << " " << key[5] << " " << key[6] << " " << key[7] << " " << key[9] << " " << key[10] << " " << key[11] << endl;
    cout << "  " << key[25] << " " << key[23] << " " << key[2] << " " << key[21] << " " << key[1] << " " << key[13] << " " << key[12] << endl;
}

bool contain(char guess, string word) {
    for (int i = 0; i < word.length(); i++) {
        if (guess == word[i] || guess == word[i] - 32) return true;
    }
    return false;
}

void update(string& guessed, string word, char guess) {
    for (int i = 0; i < word.size(); i++) {
        if (guess == word[i] || guess == word[i] - 32) guessed[i] = guess;
        if (guessed[i] >= 'A' && guessed[i] <= 'Z') guessed[i] += 32;
    }
}

void renderGame(string guessed, int guessCount, int badGuessCount, char key[]) {
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    drawHangman(badGuessCount);
    showKeyboard(key);
    cout << endl;
    cout << "Your word: " << guessed << endl << endl;
    cout << "Number of guesses: " << guessCount << endl;
    cout << "Number of false guesses: " << badGuessCount << endl;
}