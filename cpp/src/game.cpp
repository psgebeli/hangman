#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/word.h"
#include "../include/hangman.h"

using namespace std;

string word = generateRandomWord();

void print_word(string  word, vector<char> guessed_letters) {
    for (char c : word) {
        bool found = false;
        for (char letter : guessed_letters) {
            if (c == letter) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << c << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool check_letter(string word, char letter) {
    for (char c : word) {
        if (c == letter) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(nullptr));
    string word = generateRandomWord();
    int num_guesses = 0;
    int max_guesses = 6;
    vector<char> guessed_letters;
    while (num_guesses < max_guesses) {
        cout << "You have " << max_guesses - num_guesses << " tries left." << endl;
	print_hangman(max_guesses - num_guesses);
	cout << endl;
        print_word(word, guessed_letters);
        cout << "Guess a letter: ";
        char guess;
        cin >> guess;
        bool already_guessed = false;
        for (char letter : guessed_letters) {
            if (guess == letter) {
                already_guessed = true;
                break;
            }
        }
        if (already_guessed) {
            cout << "You have already guessed that." << endl;
            continue;
        }
        guessed_letters.push_back(guess);
        if (check_letter(word, guess)) {
            cout << "Correct!" << endl;
        } else {
            cout << "Incorrect!" << endl;
            num_guesses++;
        }
        bool word_guessed = true;
        for (char c : word) {
            bool found = false;
            for (char letter : guessed_letters) {
                if (c == letter) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                word_guessed = false;
                break;
            }
        }
        if (word_guessed) {
            cout << "Congratulations, you guessed the word!" << endl;
            return 0;
        }
    }
    cout << "Sorry, you ran out of guesses. The word was ";
    for (char c : word) {
        cout << c;
    }
    cout << endl;
    return 0;
}
