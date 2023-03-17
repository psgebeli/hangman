#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include <cstdlib>
using std::srand;

#include <ctime>
using std::time;

#include "../include/word.h"
#include "../include/hangman.h"

string word = generateRandomWord(); // use func from word.h to get a random word

// function to handle neatly displaying the word onto the blank canvas of hangman

void print_word(string  word, vector<char> guessed_letters) {
    for (char c : word) {
      bool found = false; // set boolean for each letter in the word to determine if the
      // user has guessed it yet or not
      
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

bool check_letter(string word, char letter) { // pretty much redefining the boolean used
  // in print word so that I can call it within main as well.
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
  int num_wrong = 0;
  int max_wrong = 6;
  vector<char> guessed_letters;
  while (num_wrong < max_wrong) { // while player has lives left
    
    int tries_left = max_wrong - num_wrong; // how many tries until death
    cout << "You have " << tries_left << " tries left." << endl;
    print_hangman(tries_left); // calling funct from hangman.h to draw him
    cout << endl;
    print_word(word, guessed_letters); // calling above function to print
    // current status of the word (eg a__be__d)
    cout << "Guess a letter: ";
    char guess;
    cin >> guess; // store user input as guess
    bool already_guessed = false;
    for (char letter : guessed_letters) {
      if (guess == letter) {
	already_guessed = true; // make a boolean true if letter has been
	// guessed already
	break;
      }
    }
    if (already_guessed) {
      cout << "You have already guessed that." << endl;
      continue;
    }
    guessed_letters.push_back(guess);
    if (check_letter(word, guess)) { // print correct if the guess is in the
      // word
      cout << "Correct!" << endl;
    } else {
      cout << "Incorrect!" << endl; // etc.
      num_wrong++;
    }
    bool word_guessed = true; // boolean to store if the player has won or not
    for (char c : word) { // for each letter in the word, say it has
      // not been found unless it matches a letter from guessed_letters vector
      bool found = false;
      for (char letter : guessed_letters) {
	if (c == letter) {
	  found = true;
	  break;
	}
      }
      if (!found) { // repeat the loop if theres more guesses to go
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
